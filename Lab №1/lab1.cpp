#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Dot
{
protected:
    int count_of_arr;
    double **arr;

public:
    Dot()
    {
    }
    Dot(double **array, int count_of_arr)
    {
        this->count_of_arr = count_of_arr;
        arr = new double *[count_of_arr];

        for (int i = 0; i < count_of_arr; i++)
        {
            arr[i] = new double[2];
        }

        for (int i = 0; i < count_of_arr; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                arr[i][j] = array[i][j];
            }
        }
        cout << "Dots with coordinates";
        show_arr();
        cout << " has created!" << endl;
    }

    Dot(const Dot &prev_arr)
    {
        count_of_arr = prev_arr.count_of_arr;
        arr = new double *[count_of_arr];

        for (int i = 0; i < count_of_arr; i++)
        {
            arr[i] = new double[2];
        }

        for (int i = 0; i < count_of_arr; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                arr[i][j] = prev_arr.arr[i][j];
            }
        }
    }

    Dot &operator=(const Dot &prev_arr)
    {
        count_of_arr = prev_arr.count_of_arr;
        arr = new double *[count_of_arr];
        for (int i = 0; i < count_of_arr; i++)
        {
            arr[i] = new double[2];
        }

        for (int i = 0; i < count_of_arr; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                arr[i][j] = prev_arr.arr[i][j];
            }
        }

        return *this;
    }

    void show_arr()
    {
        for (int i = 0; i < count_of_arr; i++)
        {
            cout << " {";
            for (int j = 0; j < 2; j++)
            {
                if (j % 2 != 0)
                {
                    cout << arr[i][j];
                }
                else
                {
                    cout << arr[i][j] << ",";
                }
                
            }
            cout << "}";
        }   
    }
};

class Broken_line : public Dot
{
public:
    Broken_line()
    {
    }
    Broken_line(double **array, int count_of_arr) : Dot(array, count_of_arr)
    {
    }
    Broken_line(const Broken_line &prev_arr)
    {
        count_of_arr = prev_arr.count_of_arr;
        arr = new double *[count_of_arr];

        for (int i = 0; i < count_of_arr; i++)
        {
            arr[i] = new double[2];
        }

        for (int i = 0; i < count_of_arr; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                arr[i][j] = prev_arr.arr[i][j];
            }
        }
    }

    Broken_line &operator=(const Broken_line &prev_arr)
    {
        count_of_arr = prev_arr.count_of_arr;
        arr = new double *[count_of_arr];
        for (int i = 0; i < count_of_arr; i++)
        {
            arr[i] = new double[2];
        }

        for (int i = 0; i < count_of_arr; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                arr[i][j] = prev_arr.arr[i][j];
            }
        }

        return *this;
    }
};

class Closed_line : public Broken_line
{
public:
    Closed_line() {}
    Closed_line(double **array, int count_of_arr) : Broken_line(array, count_of_arr)
    {

    }
    Closed_line(const Closed_line &prev_arr)
    {
        count_of_arr = prev_arr.count_of_arr;
        arr = new double *[count_of_arr];

        for (int i = 0; i < count_of_arr; i++)
        {
            arr[i] = new double[2];
        }

        for (int i = 0; i < count_of_arr; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                arr[i][j] = prev_arr.arr[i][j];
            }
        }
    }

    Closed_line &operator=(const Closed_line &prev_arr)
    {
        count_of_arr = prev_arr.count_of_arr;
        arr = new double *[count_of_arr];
        for (int i = 0; i < count_of_arr; i++)
        {
            arr[i] = new double[2];
        }

        for (int i = 0; i < count_of_arr; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                arr[i][j] = prev_arr.arr[i][j];
            }
        }

        return *this;
    }

    void search_perimeter()
    {
        double perimeter;
        for (int i = count_of_arr - 1; i > 0; i--)
        {
            perimeter += pow(pow(arr[i][1] - arr[i - 1][1], 2) + pow(arr[i][0] - arr[i - 1][0], 2), 0.5);
        }

        cout << "Perimeter is " << perimeter;

    }

    void search_square()
    {
        double square, summ1, summ2;
        double count = count_of_arr;

        for (int i = 0; i < count - 1; i++)
        {
            summ1 += arr[i][0] * arr[i + 1][1];
            summ2 += arr[i][1] * arr[i + 1][0];
        }
        square = abs(summ1 - summ2) / 2;

        cout << "Square is " << square;
    }
};

class Polygon : public Closed_line
{
public:
    Polygon() {}
    Polygon(double **array, int count_of_arr) : Closed_line(array, count_of_arr)
    {
    }
    Polygon(const Polygon &prev_arr)
    {
        count_of_arr = prev_arr.count_of_arr;
        arr = new double *[count_of_arr];

        for (int i = 0; i < count_of_arr; i++)
        {
            arr[i] = new double[2];
        }

        for (int i = 0; i < count_of_arr; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                arr[i][j] = prev_arr.arr[i][j];
            }
        }
    }

    Polygon &operator=(const Polygon &prev_arr)
    {
        count_of_arr = prev_arr.count_of_arr;
        arr = new double *[count_of_arr];
        for (int i = 0; i < count_of_arr; i++)
        {
            arr[i] = new double[2];
        }

        for (int i = 0; i < count_of_arr; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                arr[i][j] = prev_arr.arr[i][j];
            }
        }

        return *this;
    }
};

class Triangle : public Closed_line
{
public:
    Triangle() {}
    Triangle(double **array, int count_of_arr) : Closed_line(array, count_of_arr)
    {
    }
    Triangle(const Triangle &prev_arr)
    {
        count_of_arr = prev_arr.count_of_arr;
        arr = new double *[count_of_arr];

        for (int i = 0; i < count_of_arr; i++)
        {
            arr[i] = new double[2];
        }

        for (int i = 0; i < count_of_arr; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                arr[i][j] = prev_arr.arr[i][j];
            }
        }
    }

    Triangle &operator=(const Triangle &prev_arr)
    {
        count_of_arr = prev_arr.count_of_arr;
        arr = new double *[count_of_arr];
        for (int i = 0; i < count_of_arr; i++)
        {
            arr[i] = new double[2];
        }

        for (int i = 0; i < count_of_arr; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                arr[i][j] = prev_arr.arr[i][j];
            }
        }

        return *this;
    }

};

class Trapezoid : public Closed_line
{
public:
    Trapezoid() {}
    Trapezoid(double **array, int count_of_arr) : Closed_line(array, count_of_arr)
    {
    }
    Trapezoid(const Trapezoid &prev_arr)
    {
        count_of_arr = prev_arr.count_of_arr;
        arr = new double *[count_of_arr];

        for (int i = 0; i < count_of_arr; i++)
        {
            arr[i] = new double[2];
        }

        for (int i = 0; i < count_of_arr; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                arr[i][j] = prev_arr.arr[i][j];
            }
        }
    }

    Trapezoid &operator=(const Trapezoid &prev_arr)
    {
        count_of_arr = prev_arr.count_of_arr;
        arr = new double *[count_of_arr];
        for (int i = 0; i < count_of_arr; i++)
        {
            arr[i] = new double[2];
        }

        for (int i = 0; i < count_of_arr; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                arr[i][j] = prev_arr.arr[i][j];
            }
        }

        return *this;
    }

};

class Regular_polygon : public Closed_line
{
public:
    Regular_polygon() {}
    Regular_polygon(double **array, int count_of_arr) : Closed_line(array, count_of_arr)
    {
    }
    Regular_polygon(const Regular_polygon &prev_arr)
    {
        count_of_arr = prev_arr.count_of_arr;
        arr = new double *[count_of_arr];

        for (int i = 0; i < count_of_arr; i++)
        {
            arr[i] = new double[2];
        }

        for (int i = 0; i < count_of_arr; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                arr[i][j] = prev_arr.arr[i][j];
            }
        }
    }

    Regular_polygon &operator=(const Regular_polygon &prev_arr)
    {
        count_of_arr = prev_arr.count_of_arr;
        arr = new double *[count_of_arr];
        for (int i = 0; i < count_of_arr; i++)
        {
            arr[i] = new double[2];
        }

        for (int i = 0; i < count_of_arr; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                arr[i][j] = prev_arr.arr[i][j];
            }
        }

        return *this;
    }

};


int main(int argc, char *argv[])
{
    
}