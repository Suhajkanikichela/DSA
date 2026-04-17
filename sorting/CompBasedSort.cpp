#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    int temp=0;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int minIndex = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (i != minIndex)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void insertionSort(int arr[], int n)
{
    int i=1, j=0, temp = 0;
    for ( i = 1; i < n; i++)
    {
        j=i-1;
        temp = arr[i];
        while ((j > -1) && (arr[j]> temp))
        {
            arr[j+1]= arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

void Display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

int main()
{
    int n=0;
    cout<<"Enter the size for array: "<<endl;
    cin>>n;
    int arr[n];

    cout<<"Enter the elements for array: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int choice=0;
    do
    {
        cout<<"Menu."<<endl;
        cout<<"1.Bubble Sort."<<endl;
        cout<<"2.Selection Sort."<<endl;
        cout<<"3.Insertion Sort."<<endl;
        cout<<"4.Exit."<<endl;
        cin>>choice;

        switch (choice)
        {
        case 1:
            bubbleSort(arr, n);  
            Display(arr, n);
            break;

        case 2:
            selectionSort(arr, n);  
            Display(arr, n);
            break;

        case 3:
            insertionSort(arr, n);  
            Display(arr, n);
            break;

        case 4:
            cout<<"Exiting Code"<<endl;  
            break;
        
        default:
            cout<<"Enter a valid choice from 1-4."<<endl;
            break;
        }


    } while (choice != 4);
    
    
    return 0;
}