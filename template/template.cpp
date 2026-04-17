#include<iostream>
using namespace std;

template <class T> //Template ends with class
class arithmetic
{
    private: 
    T a;
    T b;

    public:
    arithmetic(T x, T y) //constructor declaration
    {
        a=x;
        b=y;
    }

    T add()
    {
        return a+b;
    }

    T sub();
};

template <class T> //New template for outside declaration
T arithmetic<T>::sub()
{
    return a-b;
}

int main()
{
    arithmetic <int> ar_int(10,11); //Declared intended data type here.
    cout<<ar_int.add()<<endl;
    cout<<ar_int.sub()<<endl;

    arithmetic <float> ar_float(1.5,1.1);
    cout<<ar_float.add()<<endl;
    cout<<ar_float.sub()<<endl;


    return 0;
}