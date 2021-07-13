#include <iostream>
using namespace std;
int partition(int arr[], int s, int e)
{
    int pivot = arr[e]; //last element
    int pIndex = s;     //from the start
    for (int i = s; i < e; i++)
    {
        if (arr[i] <= pivot) //when compared with pivot(last element in unsorted array), if smaller then replaced at the start
        {
            int temp = arr[i];
            arr[i] = arr[pIndex];
            arr[pIndex] = temp;
            pIndex++;
        }
    }
    //pIndex will come to mid point so now replacing pivot with mid element
    //now all elements left of pivot are smaller(but unsorted) and all on right are larger(but unsorted)
    int temp1 = arr[pIndex];
    arr[pIndex] = arr[e];
    arr[e] = temp1;
    return pIndex;
}
void quicksort(int arr[], int s, int e)
{
    if (s < e)
    {
        int p = partition(arr, s, e); //first we partition to get pivot in the middle
        quicksort(arr, s, p - 1);
        quicksort(arr, p + 1, e);
    }
}
int main()
{
    int n;
    cout << "Enter number of elements:" << endl;
    cin >> n;
    int *arr = new int[n];
    cout << "Enter array elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quicksort(arr, 0, n - 1);
    cout << "Array after quick sort:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}