#include <iostream>
using namespace std;

int Partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;
    
    while (i < j)
    {
        while (A[i] <= pivot && i < h)
            i++;
        
        while (A[j] > pivot)
            j--;
        if (i < j)
        {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    
    A[l] = A[j];
    A[j] = pivot;
    return j;
}

void QuickSort(int A[], int l, int h)
{
    if (l < h)
    {
        int j = Partition(A, l, h);
        QuickSort(A, l, j - 1);
        QuickSort(A, j + 1, h);
    }
}

int main()
{
    int n;
    cout << "Enter the no. of elements for array: " << endl;
    cin >> n;

    int *A;
    A = new int[n];

    cout << "Enter the elements for array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    QuickSort(A, 0, n - 1);

    cout << "The array after quicksort is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << "\t";
    }
    cout << endl;

    delete[] A;

    return 0;
}
