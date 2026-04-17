#include<iostream>
using namespace std;

class Toeplitz //Diagonal elements are same
{
private:
    int n;
    int *row;
    int *col;
public:
    Toeplitz(int n)
    {
        this -> n = n;
        row =  new int[n];
        col = new int[n-1];
    }

    void Set(int i, int j, int x)
    {
        if (i <= j)
        {
            row[j-i]= x;

        }
        else
        {
            col[i-j] = x;
        }
    }

    int Get(int i, int j)
    { 
        if (i <= j)
        {
            return row[j-i];
        }
        else
        {
            return col[i-j];
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
                    cout<<row[j-i]<<"\t";
                }
                else
                {
                    cout<<col[i-j]<<"\t";
                }
            }
            cout<<endl;
        }
        cout<<endl;
    }

    ~Toeplitz()
    {
        delete[] row;
        delete[] col;
    }
};


int main()
{
    int d=0;
    cout<<"Enter Dimensions for the matrix: "<<endl;
    cin>>d;
    Toeplitz m(d);
    int x=0;
    int p=0, q=0;
    int choice=0;

    do
    {
        cout<<"Menu: "<<endl;
        cout<<"1. Set."<<endl;
        cout<<"2. Get."<<endl;
        cout<<"3. Display."<<endl;
        cout<<"4. Exit."<<endl;
        cin>>choice;

        switch (choice)
        {
        case 1:
        cout<<"Set the values for the matrix: "<<endl;
        for (int i = 1; i <= d; i++)
        {
            for (int j = 1; j <= d; j++)
            {
                cin>>x;
                m.Set(i,j,x);
            }
        }
        break;

        case 2:
        cout<<"Enter the index of matrix to get output from: "<<endl;
        cin>>p>>q;
        cout<<m.Get(p,q)<<endl;
        break;

        case 3: 
        cout<<"Displaying the matrix: "<<endl;
        m.Display();
        break;

        case 4:
        cout<<"Exiting the code."<<endl;
        break;

        default:
        cout<<"Enter a valid choice from 1-4."<<endl;
        break;
        }
    } while (choice != 4);
    
    
    return 0;
}