#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Dot
{
protected:
    int count_of_arr;
    int **arr;

public:
    Dot()
    {
    }
    Dot(int **array, int count_of_arr)
    {
        this->count_of_arr = count_of_arr;
        arr = new int *[count_of_arr];

        for (int i = 0; i < count_of_arr; i++)
        {
            arr[i] = new int[2];
        }

        for (int i = 0; i < count_of_arr; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                arr[i][j] = array[i][j];
            }
        }
    }

    Dot(const Dot &prev_arr)
    {
        count_of_arr = prev_arr.count_of_arr;
        arr = new int *[count_of_arr];

        for (int i = 0; i < count_of_arr; i++)
        {
            arr[i] = new int[2];
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
        arr = new int *[count_of_arr];
        for (int i = 0; i < count_of_arr; i++)
        {
            arr[i] = new int[2];
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
            cout << "{";
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
    Broken_line(int **array, int count_of_arr) : Dot(array, count_of_arr)
    {
    }
    Broken_line(const Broken_line &prev_arr)
    {
        count_of_arr = prev_arr.count_of_arr;
        arr = new int *[count_of_arr];

        for (int i = 0; i < count_of_arr; i++)
        {
            arr[i] = new int[2];
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
        arr = new int *[count_of_arr];
        for (int i = 0; i < count_of_arr; i++)
        {
            arr[i] = new int[2];
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
    Closed_line(int **array, int count_of_arr) : Broken_line(array, count_of_arr)
    {
    }
    Closed_line(const Closed_line &prev_arr)
    {
        count_of_arr = prev_arr.count_of_arr;
        arr = new int *[count_of_arr];

        for (int i = 0; i < count_of_arr; i++)
        {
            arr[i] = new int[2];
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
        arr = new int *[count_of_arr];
        for (int i = 0; i < count_of_arr; i++)
        {
            arr[i] = new int[2];
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

    double search_perimeter()
    {
        double perimeter;
        for (int i = count_of_arr - 1; i > 0; i--)
        {
            perimeter += pow(pow(arr[i][1] - arr[i - 1][1], 2) + pow(arr[i][0] - arr[i - 1][0], 2), 0.5);
        }

        return perimeter;
    }

    double search_square()
    {
        double square, summ1, summ2;
        double count = count_of_arr;

        for (int i = 0; i < count - 1; i++)
        {
            summ1 += arr[i][0] * arr[i + 1][1];
            summ2 += arr[i][1] * arr[i + 1][0];
        }
        square = abs(summ1 - summ2) / 2;

        return square;
    }
};

class Polygon : public Closed_line
{
public:
    Polygon() {}
    Polygon(int **array, int count_of_arr) : Closed_line(array, count_of_arr)
    {
    }
    Polygon(const Polygon &prev_arr)
    {
        count_of_arr = prev_arr.count_of_arr;
        arr = new int *[count_of_arr];

        for (int i = 0; i < count_of_arr; i++)
        {
            arr[i] = new int[2];
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
        arr = new int *[count_of_arr];
        for (int i = 0; i < count_of_arr; i++)
        {
            arr[i] = new int[2];
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
    Triangle(int **array, int count_of_arr) : Closed_line(array, count_of_arr)
    {
    }
    Triangle(const Triangle &prev_arr)
    {
        count_of_arr = prev_arr.count_of_arr;
        arr = new int *[count_of_arr];

        for (int i = 0; i < count_of_arr; i++)
        {
            arr[i] = new int[2];
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
        arr = new int *[count_of_arr];
        for (int i = 0; i < count_of_arr; i++)
        {
            arr[i] = new int[2];
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
    Trapezoid(int **array, int count_of_arr) : Closed_line(array, count_of_arr)
    {
    }
    Trapezoid(const Trapezoid &prev_arr)
    {
        count_of_arr = prev_arr.count_of_arr;
        arr = new int *[count_of_arr];

        for (int i = 0; i < count_of_arr; i++)
        {
            arr[i] = new int[2];
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
        arr = new int *[count_of_arr];
        for (int i = 0; i < count_of_arr; i++)
        {
            arr[i] = new int[2];
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
    Regular_polygon(int **array, int count_of_arr) : Closed_line(array, count_of_arr)
    {
    }
    Regular_polygon(const Regular_polygon &prev_arr)
    {
        count_of_arr = prev_arr.count_of_arr;
        arr = new int *[count_of_arr];

        for (int i = 0; i < count_of_arr; i++)
        {
            arr[i] = new int[2];
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
        arr = new int *[count_of_arr];
        for (int i = 0; i < count_of_arr; i++)
        {
            arr[i] = new int[2];
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
    int **array_me;
    array_me = new int *[4];
    for (int i = 0; i < 4; i++)
    {
        array_me[i] = new int[2];
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {

            array_me[i][j] = 5;
        }
    }

    int **array_notme;
    array_notme = new int *[4];
    for (int i = 0; i < 4; i++)
    {
        array_notme[i] = new int[2];
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {

            array_notme[i][j] = 3;
        }
    }

    int **arr_ex;
    arr_ex = new int *[5];
    for (int i = 0; i < 5; i++)
    {
        arr_ex[i] = new int[2];
    }

    arr_ex[0][0] = {1};
    arr_ex[0][1] = {1};
    arr_ex[1][0] = {2};
    arr_ex[1][1] = {2};
    arr_ex[2][0] = {3};
    arr_ex[2][1] = {2};
    arr_ex[3][0] = {4};
    arr_ex[3][1] = {1};
    arr_ex[4][0] = {1};
    arr_ex[4][1] = {1};
    
    

    /*Dot obj(array_me, 4);
    Dot dot2 = obj;
    Dot dot3(array_notme, 4);
    dot2 = dot3;
    dot2.show();
    Broken_line line(array_notme, 4);
    Broken_line line2 = line;*/
    Regular_polygon close_line(arr_ex, 5);
    close_line.show_arr();
    // TODO Организовать иерархию периметров
    return 0;
}