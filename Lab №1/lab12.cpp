#include <iostream>
using namespace std;

class Polynomial
{
private:
    double *arr;
    int capacity;

public:
    Polynomial()
    {
        cout << endl;
        cout << "Enter capacity of polynomial: ";
        cin >> capacity;
        arr = new double[capacity];
        cout << "Enter odds: \n";
        for (int i = capacity; i > 0; i--)
        {
            cin >> arr[i];
        }
        cout << "Enter free member: \n";
        cin >> arr[0];
    }

    Polynomial(int capacity)
    {
        arr = new double[capacity];
        this->capacity = capacity;
    }

    Polynomial(const Polynomial &prev_arr)
    {
        capacity = prev_arr.capacity;
        arr = new double[capacity];

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

    Polynomial operator+=(const Polynomial &prev_arr)
    {
      
        if (capacity >= prev_arr.capacity)
        {
            Polynomial temp(capacity);
            for (int i = prev_arr.capacity; i >= 0; i--)
            {
                temp.arr[i] += prev_arr.arr[i];
            }
            delete[] arr;
            arr = new double[capacity];

            for (int i = capacity; i >= 0; i--)
            {
                arr[i] += temp.arr[i];
            }

            for (int i = prev_arr.capacity; i >= 0; i--)
            {
                arr[i] += prev_arr.arr[i] + temp.arr[i];
            }
        }
        else
        {
            Polynomial temp(prev_arr.capacity);
            for (int i = capacity; i >= 0; i--)
            {
                temp.arr[i] += this->arr[i];
            }
         
            for (int i = prev_arr.capacity; i >= 0; i--)
            {
                temp.arr[i] += prev_arr.arr[i];
            }

            delete[] arr;
            arr = new double[temp.capacity];
            for (int i = temp.capacity; i >= 0; i--)
            {
                this->arr[i] += temp.arr[i];
            }
            this->capacity = temp.capacity;
        }

        // return temp;
        return *this;
    }

    Polynomial &operator=(const Polynomial &prev_arr)
    {
        capacity = prev_arr.capacity;
        arr = new double[capacity];

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

    ~Polynomial()
    {
        delete[] arr;
    }
    void show()
    {
        for (int i = capacity; i > 0; i--)
        {
            if (arr[i] == 1)
            {
                cout << "X^" << i << " + ";
            }
            else if (arr[i] == 0)
            {
            }
            else
            {
                cout << arr[i] << "X^" << i << " + ";
            }
        }

        cout << arr[0];
    }
};

int main(int argc, char *argv[])
{
    Polynomial k;
    Polynomial c;
    // Polynomial i = k;
    //  c = k;

    c += k;

    c.show();
}