#include<iostream>
using namespace std;

class UpperTri
{
    private:
        int n;
        int *A;

    public:
        UpperTri(int n)
        {
            this->n = n;
            A = new int[(n*(n+1))/2];
        }

        void Set(int i, int j, int x)
        {
            if (i <= j)
            {
                A[i*(n - (i-1)/2) + (j-i)] = x;
            }
        }

        int Get(int i, int j)
        {
            if (i <= j)
            {
                return A[i*(n - (i-1)/2) + (j-i)];
            }
            else
            {
                return 0;
            }
        }

        void Display()
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (i <= j)
                    {
                        cout << A[i*(n - (i-1)/2) + (j-i)] << "\t";
                    }
                    else
                    {
                        cout << "0\t";
                    }
                }
                cout << endl;
            }
            cout << endl;
        }

        ~UpperTri()
        {
            delete[] A;
        }
};

int main()
{
    int d = 0;
    cout << "Enter Dimension for matrix: " << endl;
    cin >> d;
    UpperTri m(d);

    int x = 0;
    cout << "Enter all elements: " << endl;
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cin >> x;
            m.Set(i, j, x);
        }
    }

    cout << "Element at (2,1): " << m.Get(2, 1) << endl;

    cout << "Upper Triangular Matrix:" << endl;
    m.Display();

    return 0;
}
