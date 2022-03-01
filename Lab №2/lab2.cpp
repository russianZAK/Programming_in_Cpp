#include "json.hpp"
#include <iostream>
#include <vector>
#include <curl/curl.h>
#include <fstream>
#include <string>


using json = nlohmann::json;
using namespace std;

int overwrite(char* info, int size, int nmemb, ofstream* buffer) {
    int result = 0;
    if (buffer != NULL) {
        buffer->write(info, size * nmemb);
        result = size * nmemb;
    }
    return result;
}

void pic() 
{
    for (int i = 0; i < 58; i++)
    {
        cout << "_";
    }
}

typedef struct info
{
    vector<vector<double>> information;
    vector<string> values;

} info;

void merge(info stat, int left, int middle, int right, int index) {
    int k, nl, nr;
    nl = middle - left + 1; nr = right - middle;
    vector<double> larr;
    larr.resize(nl);
    vector<double> rarr;
    rarr.resize(nr);
    for (int i = 0; i < nl; i++)
        larr[i] = stat.information[index][left + i];
    for (int j = 0; j < nr; j++)
        rarr[j] = stat.information[index][middle + 1 + j];
    int i = 0; 
    int j = 0;
    k = left;
    while (i < nl && j < nr) 
    {
        if (larr[i] <= rarr[j])
        {
            stat.information[index][k] = larr[i];
            i++;
        }
        else 
        {
            stat.information[index][k] = rarr[j];
            j++;
        }
        k++;
    }
    while (i < nl) 
    {
        stat.information[index][k] = larr[i];
        i++; k++;
    }
    while (j < nr) 
    
    {
        stat.information[index][k] = rarr[j];
        j++; k++;
    }
}
void mergeSort(info stat, int left, int right, int index) {
    int middle;
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(stat, left, middle, index);
        mergeSort(stat, middle + 1, right, index);
        merge(stat, left, middle, right, index);
    }
} 

int main() {
    bool further = true;
    info information1;   
    information1.information.resize(34, vector<double>(0));
    while (further) {
        CURL* curl;
        curl = curl_easy_init();
        ofstream ofs("valute.json");
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &ofs);
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.cbr-xml-daily.ru/daily_json.js");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, overwrite);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        ofs.close();
        int pos = 0;
        ifstream src("valute.json");
        json jsn;
        src >> jsn;
        string fName = jsn.value("Date", "Date");
        cout << "Date " << fName << endl;
        fName = jsn.value("Timestamp", "Timestamp");
        cout << "Timestamp " << fName << endl;
        if (jsn.find("Valute") != jsn.end())
        {
            pic();
            cout << endl << "|Valute " << setw(5) << "|"
                << setw(11) << "Value" << setw(13) << "|"
                << setw(17) << "Previous Value" << setw(5) << "|"
                <<endl;
            
            pic();
            cout << endl;
            for (auto const& val : jsn["Valute"])
            {
                
                string fName = val.value("CharCode", "CharCode");
                double value = val.value("Value", 11.1);
                double previous_value = val.value("Previous", 11.1);
                information1.information[pos].push_back(value);
                information1.values.push_back(fName);

                pos++;
                cout << setw(1) <<"|" << fName << setw(9) << "|"
                    << setw(11) << value << " RUB" << setw(9) << "|"
                    << setw(11) << previous_value << " RUB" << setw(7) << "|"
                    << endl;
            }
        }
        pic();
        int time = GetTickCount();
        while ((GetTickCount() - time) < 10000)
        {
            if (GetAsyncKeyState(VK_RETURN)) {
                goto Stop;
            }
        }
        information1.values.clear();
        
        system("cls");

    }
Stop:  
    cout << endl << endl;
    pic();
    cout << endl << "|Valute " << setw(5) << "|"
        << setw(14) << "Mean Value" << setw(10) << "|"
        << setw(15) << "Median Value" << setw(7) << "|"
        << endl;
    pic();
    cout << endl;
    for (int i = 0; i < information1.values.size(); i++) 
    {
        double middle = 0;
        double middle_count = 0;
        double median_count = 0;
        int mid = 0;
        for (int j = 0; j < information1.information[i].size(); j++)
        {
            middle += information1.information[i][j];
            mergeSort(information1, 0, information1.information[i].size() - 1, i);
        }
        mid = information1.information[i].size() / 2;
        median_count = information1.information[i][mid];
        middle_count = middle / information1.information[i].size();
        cout << setw(1) << "|" << information1.values[i] << setw(9) << "|"
            << setw(11) << middle_count << " RUB" << setw(9) << "|"
            << setw(11) << median_count << " RUB" << setw(7) << "|"
            << endl;
        
    }
    pic();
    return 0;
}
