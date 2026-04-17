#include<iostream>
using namespace std;

class Element
{
    public:
    int i;
    int j;
    int x;
};

class Sparse
{
    private:
    int m;
    int n;
    int num;
    Element * ele;

    public:
    Sparse(int m, int n, int num)
    {
        this-> m = m;
        this-> n = n;
        this-> num = num; 
        ele = new Element[this-> num];
    }

    ~Sparse()
    {
        delete[] ele;
    }

    void read()
    {
        cout<<"Enter non zero elements: "<<endl;
        for (int i = 0; i < num; i++)
        {
            cin>>ele[i].i>>ele[i].j>>ele[i].x;
        }  
    }

    void display()
    {
        int k = 0;
        for (size_t i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (ele[k].i == i && ele[k].j == j)
                {
                    cout<<ele[k++].x<<"\t";
                }
                else
                {
                    cout<<"0\t";
                } 
            } 
            cout<<endl;
        }
    }
};

int main()
{
    int a, b, c;
    cout<<"Enter the dimesions for matrix : "<<endl;
    cin>>a>>b;
    cout<<"Enter the number of non zero elements: "<<endl;
    cin>>c;
    Sparse s1(a,b,c);
    s1.read();
    s1.display();

    return 0;
}