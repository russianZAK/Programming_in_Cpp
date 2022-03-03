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
    Dot() {}
    Dot(double x, double y)
    {
        count_of_arr = 1;
        arr = new double *[count_of_arr];
        arr[0] = new double[2];
        arr[0][0] = x;
        arr[0][1] = y;
        cout << "Dot with coordinates";
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
    ~Dot()
    {
        for (int i = 0; i < count_of_arr; i++)
        {
            delete[] arr[i];
        }

        delete[] arr;
    }

    void show_arr()
    {
        for (int i = 0; i < count_of_arr; i++)
        {
            cout << " (";
            for (int j = 0; j < 2; j++)
            {
                if (j % 2 != 0)
                {
                    cout << arr[i][j];
                }
                else
                {
                    cout << arr[i][j] << " , ";
                }
            }
            cout << ")";
        }
    }
};

class Broken_line : public Dot
{

public:
    Broken_line()
    {
        bool futher = true;
        while (futher)
        {
            cout << "Enter the number of points - ";
            cin >> this->count_of_arr;
            if (count_of_arr <= 2)
            {
                cout << "Enter more points than 2!" << endl;
                this->~Broken_line();
            }
            else
            {
                cout << "Enter the coordinates of the points :" << endl;
                arr = new double *[count_of_arr];
                for (int i = 0; i < count_of_arr; i++)
                {
                    arr[i] = new double[2];
                    cout << "Dot" << i + 1 << "(x,y) ";
                    cin >> arr[i][0] >> arr[i][1];
                    if (i == 1)
                    {
                        if ((this->arr[i][0] == this->arr[i - 1][0]) && (this->arr[i][1] == this->arr[i - 1][1]))
                        {
                            cout << "Dots cannot match!" << endl;
                            cout << "Enter new dots!" << endl;
                            this->~Broken_line();
                        }
                    }
                }

                for (int i = 0; i < count_of_arr - 1; i++)
                {
                    for (int j = i; j < count_of_arr - 1; j++)
                    {
                        if ((this->arr[i][0] == this->arr[j + 1][0]) && (this->arr[i][1] == this->arr[j + 1][1]))
                        {
                            cout << "Dots cannot be equal!" << endl;
                            cout << "Enter new dots!" << endl;
                            this->~Broken_line();
                        }
                    }
                }
            }
            futher = false;
        }

        double line1, line2;
        line2 = line1 = 0.0;
        for (int j = 0; j < count_of_arr - 2; j++)
        {
            line1 = (arr[j][1] - arr[j + 1][1]) / (arr[j][0] - arr[j + 1][0]);
            line2 = (arr[j + 1][1] - arr[j + 2][1]) / (arr[j + 1][0] - arr[j + 2][0]);
            if (line1 == line2)
            {
                cout << "Wrong build!!" << endl;
                cout << "Enter new dots!" << endl;
                this->~Broken_line();
            }
        }
        cout << "Dots with coordinates";
        show_arr();
        cout << " has created!" << endl;
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

    ~Broken_line()
    {
        for (int i = 0; i < count_of_arr; i++)
        {
            delete[] arr[i];
        }

        delete[] arr;
    }
};

class Closed_line : public Dot
{
protected:
    struct point
    {
        double x, y;
    };

public:
    Closed_line()
    {
        bool futher = true;
        while (futher)
        {
            cout << "Enter the number of points - ";
            cin >> this->count_of_arr;
            if (count_of_arr <= 2)
            {
                cout << "Enter more points than 2!" << endl;
                this->~Closed_line();
            }
            else
            {
                this->count_of_arr++;
                cout << "Enter the coordinates of the dots :" << endl;
                this->arr = new double *[count_of_arr];
                for (int i = 0; i < this->count_of_arr; i++)
                {
                    this->arr[i] = new double[2];

                    if (i + 1 < count_of_arr)
                    {
                        cout << "Dot_" << i + 1 << "(x,y) ";
                    }
                    if (i + 1 == count_of_arr)
                    {
                        this->arr[count_of_arr - 1][0] = this->arr[0][0];
                        this->arr[count_of_arr - 1][1] = this->arr[0][1];
                        break;
                    }
                    cin >> this->arr[i][0] >> this->arr[i][1];
                }
                for (int i = 0; i < count_of_arr - 2; i++)
                {
                    for (int j = i; j < count_of_arr - 2; j++)
                    {
                        if ((this->arr[i][0] == this->arr[j + 1][0]) && (this->arr[i][1] == this->arr[j + 1][1]))
                        {
                            cout << "Dots cannot be equal!" << endl;
                            cout << "Enter new dots!" << endl;
                            exit(0);
                            this->~Closed_line();
                        }
                    }
                }

                futher = false;
            }
        }
        double line1, line2;
        line2 = line1 = 0.0;
        for (int j = 0; j < count_of_arr - 2; j++)
        {
            line1 = (arr[j][1] - arr[j + 1][1]) / (arr[j][0] - arr[j + 1][0]);
            line2 = (arr[j + 1][1] - arr[j + 2][1]) / (arr[j + 1][0] - arr[j + 2][0]);
            if (line1 == line2)
            {
                cout << "Wrong build!!" << endl;
                cout << "Enter new dots!" << endl;
                this->~Closed_line();
                exit(0);
            }
        }

        for (int k = count_of_arr - 2; k > 0; k--)
        {
            for (int j = k - 2; j > 0; j--)
            {
                int res;
                point p1, p2, p3, p4;
                p1.x = arr[k][0];
                p1.y = arr[k][1];

                p2.x = arr[k - 1][0];
                p2.y = arr[k - 1][1];

                p3.x = arr[j][0];
                p3.y = arr[j][1];

                p4.x = arr[j - 1][0];
                p4.y = arr[j - 1][1];

                res = miintersect(p1, p2, p3, p4);
                if (res == 1)
                {
                    cout << "Lines must not cross!!" << endl;
                    cout << "Enter new dots!" << endl;
                    exit(0);
                    this->~Closed_line();
                }
            }
        }

        cout << "Dots with coordinates";
        show_arr();
        cout << " has created!" << endl;
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

    ~Closed_line()
    {
        for (int i = 0; i < count_of_arr; i++)
        {
            delete[] arr[i];
        }

        delete[] arr;
    }

    double miarea(point a, point b, point c)
    {
        return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    }

    bool miintersect_1(int a, int b, int c, int d)
    {
        if (a > b)
            swap(a, b);
        if (c > d)
            swap(c, d);
        return max(a, c) <= min(b, d);
    }

    bool miintersect(point a, point b, point c, point d)
    {
        return miintersect_1(a.x, b.x, c.x, d.x) && miintersect_1(a.y, b.y, c.y, d.y) && miarea(a, b, c) * miarea(a, b, d) <= 0 && miarea(c, d, a) * miarea(c, d, b) <= 0;
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
    Polygon() : Closed_line()
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

    ~Polygon()
    {
        for (int i = 0; i < count_of_arr; i++)
        {
            delete[] arr[i];
        }

        delete[] arr;
    }
};

class Triangle : public Polygon
{
public:
    Triangle() : Polygon()
    {
        if (count_of_arr - 1 != 3)
        {
            cout << "Wrong number of points!" << endl;
            cout << "Enter 3 points!" << endl;
            this->~Triangle();
            exit(0);
        }
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
    ~Triangle()
    {
        for (int i = 0; i < count_of_arr; i++)
        {
            delete[] arr[i];
        }

        delete[] arr;
    }
};

class Trapezoid : public Polygon
{
public:
    Trapezoid() : Polygon()
    {

        if (count_of_arr - 1 != 4)
        {
            cout << "Wrong number of points!" << endl;
            cout << "Enter 4 points!" << endl;
            this->~Trapezoid();
            exit(0);
        }
        else
        {
            double line1, line2, line3, line4;
            line1 = line2 = line3 = line4 = 0;
            int res[2];
            res[0] = res[1] = 0;

            for (int i = 4; i > 2; i--)
            {
                line1 = (arr[i][1] - arr[i - 1][1]) / (arr[i][0] - arr[i - 1][0]);
                line2 = (arr[i - 3][1] - arr[i - 2][1]) / (arr[i - 3][0] - arr[i - 2][0]);
                if (line1 == line2)
                {
                    res[i - 3] = 1;
                }
            }

            if (res[0] == res[1])
            {
                cout << "Wrong sides of trapezoid, enter only 2 parallel sides!" << endl;
                this->~Trapezoid();
                exit(0);
            }
            else if (res[0] == 1 || res[1] == 1)
            {
            }
            else
            {
                cout << "Wrong sides of trapezoid, enter parallel sides!" << endl;
                this->~Trapezoid();
                exit(0);
            }
        }
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

    ~Trapezoid()
    {
        for (int i = 0; i < count_of_arr; i++)
        {
            delete[] arr[i];
        }

        delete[] arr;
    }
};

class Regular_polygon : public Polygon
{
public:
    Regular_polygon() : Polygon()
    {
        double line1, line2;
        line1 = 0;
        line2 = 0;

        for (int i = count_of_arr - 1; i > 2; i--)
        {
            line1 = pow(pow(arr[i][1] - arr[i - 1][1], 2) + pow(arr[i][0] - arr[i - 1][0], 2), 0.5);
            line2 = pow(pow(arr[i - 1][1] - arr[i - 2][1], 2) + pow(arr[i - 1][0] - arr[i - 2][0], 2), 0.5);
            if (line1 != line2)
            {
                cout << "Wrong sides of regular polygon, enter equal sides!" << endl;
                this->~Regular_polygon();
                exit(0);
            }
        }
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
    ~Regular_polygon()
    {
        for (int i = 0; i < count_of_arr; i++)
        {
            delete[] arr[i];
        }

        delete[] arr;
    }
};

int main(int argc, char *argv[])
{
    Regular_polygon ik;
    ik.search_square();
    return 0;
}