#include<iostream>
using namespace std;

void merge(int array[], int leftIndex, int midIndex, int rightIndex)
{
    int leftArraySize = (midIndex - leftIndex) +1;
    int rightArraySize = rightIndex - midIndex;

    int leftArray[leftArraySize];
    int rightArray[rightArraySize];

    for (int i = 0; i < leftArraySize; i++)
    {
        leftArray[i] = array[leftIndex + i];
    }
    for (int j = 0; j < rightArraySize; j++)
    {
        rightArray[j] = array[midIndex+1 + j];
    }
    int index = leftIndex;
    int i=0, j=0;

    while (i < leftArraySize && j < rightArraySize)
    {
        if (leftArray[i] <= rightArray[j])
        {
            array[index] = leftArray[i];
            i++;
            index++;
        }
        else
        {
            array[index] = rightArray[j];
            j++;
            index++;
        }
    }
    while (i < leftArraySize)
    {   
        array[index] = leftArray[i];
        i++;
        index++;
    }    
    while (j < rightArraySize)
    {   
        array[index] = rightArray[j];
        j++;
        index++;
    }
}

void mergeSort(int array[], int leftIndex, int rightIndex)
{
    if (leftIndex >= rightIndex) return;

    int midIndex = leftIndex + (rightIndex - leftIndex)/2;
    mergeSort(array, leftIndex, midIndex);
    mergeSort(array, midIndex+1, rightIndex);

    merge(array, leftIndex, midIndex, rightIndex);
}

int main()
{
    int size = 0;
    cout<<"Enter size for array: "<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter elements for array: "<<endl;
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    mergeSort(arr, 0, size-1);
    cout<<"Merge Sort Output: "<<endl;
    for (auto num : arr)
    {
        cout<<num<<"\t";
    }
    
    cout<<endl;

    return 0;
}           