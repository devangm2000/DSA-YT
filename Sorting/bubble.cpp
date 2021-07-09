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
void bubblesort(int arr[], int n)
{
    for (int i = 0; i < n; i++) //after iteration, largest element will be sent to the end and will become inaccessible
    {
        for (int j = 0; j < n - 1 - i; j++) //j will not be = last i+1 elements
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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
    bubblesort(arr, n);
    return 0;
}