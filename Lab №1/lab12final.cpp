#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>
using namespace std;

class Polynomial
{
private:
    double *arr;
    int capacity;

public:
    Polynomial()
    {
        /*cout << "Enter capacity of polynomial: ";
        cin >> capacity;
        arr = new double[++capacity];
        capacity--;
        cout << "Enter odds: \n";
        for (int i = capacity; i > 0; i--)
        {
            cin >> arr[i];
        }
        cout << "Enter free member: \n";
        cin >> arr[0];*/
    }

    Polynomial(int capacity)
    {
        arr = new double[++capacity];
        this->capacity = --capacity;
    }

    Polynomial(const Polynomial &prev_arr)
    {
        capacity = prev_arr.capacity;
        arr = new double[++capacity];
        capacity--;

        for (int i = capacity; i >= 0; i--)
        {
            arr[i] = prev_arr.arr[i];
        }
    }

    Polynomial operator+(const Polynomial &prev_arr)
    {
        int count = max(capacity, prev_arr.capacity);
        Polynomial temp(count);

        if (this->capacity >= prev_arr.capacity)
        {
            for (int i = prev_arr.capacity; i >= 0; i--)
            {
                temp.arr[i] = prev_arr.arr[i] + this->arr[i];
            }
            for (int i = capacity; i > prev_arr.capacity; i--)
            {
                temp.arr[i] = this->arr[i];
            }
        }
        else
        {
            for (int i = this->capacity; i >= 0; i--)
            {
                temp.arr[i] = prev_arr.arr[i] + this->arr[i];
            }
            for (int i = prev_arr.capacity; i > this->capacity; i--)
            {
                temp.arr[i] = prev_arr.arr[i];
            }
        }

        return temp;
    }
    Polynomial operator-(const Polynomial &prev_arr)
    {
        int count = max(capacity, prev_arr.capacity);
        Polynomial temp(count);

        if (this->capacity >= prev_arr.capacity)
        {
            for (int i = prev_arr.capacity; i >= 0; i--)
            {
                temp.arr[i] = this->arr[i] - prev_arr.arr[i];
            }
            for (int i = capacity; i > prev_arr.capacity; i--)
            {
                temp.arr[i] = this->arr[i];
            }
        }
        else
        {
            for (int i = this->capacity; i >= 0; i--)
            {
                temp.arr[i] = this->arr[i] - prev_arr.arr[i];
            }
            for (int i = prev_arr.capacity; i > this->capacity; i--)
            {
                temp.arr[i] = -prev_arr.arr[i];
            }
        }

        return temp;
    }

    Polynomial &operator=(const Polynomial &prev_arr)
    {
        capacity = prev_arr.capacity;
        arr = new double[++capacity];
        capacity--;
        for (int i = capacity; i >= 0; i--)
        {
            arr[i] = prev_arr.arr[i];
        }

        return *this;
    }
    bool operator==(const Polynomial &prev_arr)
    {
        if (capacity != prev_arr.capacity)
        {
            return false;
        }
        else
        {
            for (int i = capacity; i >= 0; i--)
            {
                if (arr[i] == prev_arr.arr[i])
                {
                }
                else
                {
                    return false;
                }

                return true;
            }
        }
    }

    bool operator!=(const Polynomial &prev_arr)
    {
        if (capacity != prev_arr.capacity)
        {
            return true;
        }
        else
        {
            for (int i = capacity; i >= 0; i--)
            {
                if (arr[i] == prev_arr.arr[i])
                {
                }
                else
                {
                    return true;
                }

                return false;
            }
        }
    }

    Polynomial operator+=(const Polynomial &prev_arr)
    {

        if (capacity >= prev_arr.capacity)
        {
            for (int i = prev_arr.capacity; i >= 0; i--)
            {
                arr[i] += prev_arr.arr[i];
            }
        }
        else
        {
            Polynomial temp(prev_arr.capacity);

            for (int i = prev_arr.capacity; i >= 0; i--)
            {
                temp.arr[i] = prev_arr.arr[i];
            }

            for (int i = capacity; i >= 0; i--)
            {
                temp.arr[i] += arr[i];
            }
            delete[] arr;
            capacity = temp.capacity;
            arr = new double[++capacity];
            capacity--;
            for (int i = temp.capacity; i >= 0; i--)
            {
                arr[i] = temp.arr[i];
            }
        }
        return *this;
    }

    Polynomial operator-=(const Polynomial &prev_arr)
    {

        if (capacity >= prev_arr.capacity)
        {
            for (int i = prev_arr.capacity; i >= 0; i--)
            {
                arr[i] -= prev_arr.arr[i];
            }
        }
        else
        {
            Polynomial temp(prev_arr.capacity);

            for (int i = prev_arr.capacity; i >= 0; i--)
            {
                temp.arr[i] = -prev_arr.arr[i];
            }

            for (int i = capacity; i >= 0; i--)
            {
                temp.arr[i] += arr[i];
            }

            delete[] arr;
            capacity = temp.capacity;
            arr = new double[++capacity];
            capacity--;
            for (int i = temp.capacity; i >= 0; i--)
            {
                arr[i] = temp.arr[i];
            }
        }
        return *this;
    }

    Polynomial operator/(const double &number)
    {
        for (int i = this->capacity; i >= 0; i--)
        {
            this->arr[i] /= number;
        }
        return *this;
    }

    Polynomial operator*(const double &number)
    {
        for (int i = this->capacity; i >= 0; i--)
        {
            this->arr[i] *= number;
        }
        return *this;
    }

    Polynomial operator*(const Polynomial &prev_arr)
    {
        int count = capacity + prev_arr.capacity;
        Polynomial temp(count);
        for (int i = 0; i <= count; i++)
        {
            temp.arr[i] = 0;
        }
        for (int i = capacity; i >= 0; i--)
        {
            for (int j = prev_arr.capacity; j >= 0; j--)
            {
                temp.arr[i + j] += (arr[i] * prev_arr.arr[j]);
            }
        }

        return temp;
    }

    Polynomial operator/=(const double &number)
    {
        for (int i = this->capacity; i >= 0; i--)
        {
            this->arr[i] /= number;
        }
        return *this;
    }

    Polynomial operator*=(const Polynomial &prev_arr)
    {
        int count = capacity + prev_arr.capacity;
        Polynomial temp(count);
        for (int i = 0; i <= count; i++)
        {
            temp.arr[i] = 0;
        }
        for (int i = capacity; i >= 0; i--)
        {
            for (int j = prev_arr.capacity; j >= 0; j--)
            {
                temp.arr[i + j] += (arr[i] * prev_arr.arr[j]);
            }
        }

        delete[] arr;
        capacity = temp.capacity;
        arr = new double[++capacity];
        capacity--;
        for (int i = temp.capacity; i >= 0; i--)
        {
            arr[i] = temp.arr[i];
        }

        return *this;
    }
    Polynomial operator*=(const double &number)
    {
        for (int i = this->capacity; i >= 0; i--)
        {
            this->arr[i] *= number;
        }
        return *this;
    }

    Polynomial operator[](const int &index)
    {
        if (index <= capacity)
        {
            cout << arr[index] << "X^" << index << endl;
        }
        else
        {
            cout << "Index out of range!";
        }
    }

    ~Polynomial()
    {
        delete[] arr;
    }


    friend ostream &operator<<(ostream &out, const Polynomial &temp);
    friend istream &operator>>(istream &in, Polynomial &temp);
};
ostream &operator<<(ostream &out, const Polynomial &temp)
{
    for (int i = temp.capacity; i > 0; i--)
    {
        if (temp.arr[i] == 1)
        {
            out << "X^" << i << " + ";
        }

        else
        {
            out << temp.arr[i] << "X^" << i << " + ";
        }
    }

    cout << temp.arr[0];
}
istream &operator>>(istream &in, Polynomial &temp)
{
    vector<string> result;
    char sentence[256];
    string num;
    cin.getline(sentence, 256);
    string tmp(sentence);
    int count = 0;
    istringstream ist(tmp);
    while (ist >> num)
    {
        result.push_back(num);
        count++;
    }

    temp.arr = new double[count];
    temp.capacity = count;

    for (int i = 0; i < count; i++)
    {
        double num = atof(result[i].c_str());
        temp.arr[count - i - 1] = num;
    }
    temp.capacity--;
    return in;
}

int main(int argc, char *argv[])
{
    Polynomial k;
    Polynomial l;
    Polynomial c;
   


    return 0;
}