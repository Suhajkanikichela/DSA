#include<iostream>
using namespace std;

class Diagonal
{
    private:
    int n;
    int *A;

    public:
    
    Diagonal(int n)
    {
        this -> n = n;
        A = new int[n];
    }

    void Set(int i, int j, int x)
    {
        if (i == j)
        {
            A[i - 1] = x;
        }
        
    }

    int Get(int i, int j)
    {
        if (i == j)
        {
            return A[i-1];
        }
        else
        {
            return 0;
        }
        
    }

    void Display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    cout<<A[i]<<"\t";
                }
                else
                {
                    cout<<"0\t";
                }
            }  
            cout<<endl;
        }
        cout<<endl;
    }

    ~ Diagonal()
    {
        delete[] A;
    }
};

int main()
{
    Diagonal d(4);

    d.Set(1,1,5);
    d.Set(2,2,10);
    d.Set(3,3,15);
    d.Set(4,4,20);

    cout<<d.Get(2,1);
    cout<<endl;

    d.Display();

    return 0;
}