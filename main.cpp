//  COUNT SORT
//  ----------

#include <iostream>

using namespace std;

void input(int*&,int&);
void printArr(int*&,int&);
void countSort(int*&,int*&,int&);
int maxNumInArr(int*&,int&);

int main(int argc, const char * argv[])
{
    int size, *arr, *result;
    
    input(arr,size);
    
    cout << "Unsorted Array:\n";
    printArr(arr,size);
    
    countSort(arr,result,size);
    
    cout << "Sorted Array:\n";
    printArr(result,size);
}

void input(int *&arr, int& size)
{
    cout << "Enter size of array:\n";
    cin >> size;
    arr = new int[size];
    cout << "Enter array:\n";
    for(int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

void countSort(int *&arr,int *&result,int& size)
{
    result = new int[size];
    int pos;
    int sum = 0;
    int maxRange = maxNumInArr(arr,size);
    maxRange++;                                 // 0 to maxRange (inclusive) for the index hence maxRange++
    int *occurence = new int[maxRange];
    int *cummulative = new int[maxRange];
    for(int i = 0; i < size; i++)
    {
        occurence[arr[i]]++;
    }
    for(int i = 0; i < maxRange; i++)
    {
        sum += occurence[i];
        cummulative[i] = sum;
    }
    for(int i = size-1; i >= 0; i--)
    {
        pos = cummulative[arr[i]];
        result[pos-1] = arr[i];
        cummulative[arr[i]]--;
    }
}

int maxNumInArr(int *&arr,int& size)
{
    int max = arr[0];
    for(int i = 1; i < size; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void printArr(int *&arr, int& size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] <<"\t";
    }
    cout <<"\n";
}
