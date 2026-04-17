#include<iostream>
using namespace std;

class Symmetric
{
private:
    int n;
    int *A;
public:
    Symmetric(int n)
    {
        this -> n = n;
        A =  new int[(n*(n+1))/2];
    }

    void Set(int i, int j, int x)
    {
        if (i >= j)
        {
            A[(i*(i-1)/2) + (j-1)] = x;
        }
        else
        {
            A[(j*(j-1)/2) + (i-1)] = x;
        }
    }

    int Get(int i, int j)
    { 
        if (i >= j)
        {
            return A[(i*(i-1)/2) + (j-1)];
        }
        else
        {
            return A[(j*(j-1)/2) + (i-1)];
        }
    }

    void Display()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i >= j)
                {
                    cout<<A[(i*(i-1)/2) + (j-1)]<<"\t";
                }
                else
                {
                    cout<<A[(j*(j-1)/2) + (i-1)]<<"\t";
                }
            }
            cout<<endl;
        }
        cout<<endl;
    }

    ~Symmetric()
    {
        delete[] A;
    }
};


int main()
{
    int d=0;
    cout<<"Enter Dimensions for the matrix: "<<endl;
    cin>>d;
    Symmetric m(d);

    int x=0;
    cout<<"Enter the values: "<<endl;
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cin>>x;
            m.Set(i, j, x);
        }
        
    }
    
    cout<<"Symmetric Matrix: "<<endl;
    m.Display();
    
    return 0;
}