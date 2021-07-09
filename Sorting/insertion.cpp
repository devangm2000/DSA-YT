#include <iostream>
using namespace std;
void printarray(int arr[], int n)
{

    cout << "Array after slection sort:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}
void insertionsort(int arr[], int n)
{
    int key, j;
    for (int i = 1; i < n; i++)
    { //replace using next item in array
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    printarray(arr, n);
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
    insertionsort(arr, n);
    return 0;
}