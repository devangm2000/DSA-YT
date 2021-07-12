#include <iostream>
using namespace std;
void merge(int arr[], int l, int m, int r, int n)
{
    int i = l;     //starting index for left sub array
    int j = m + 1; //starting index for right sub array
    int k = l;     //for new array-temp
    int *temp = new int[n];
    while (i <= m && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    //either of these loop will run when one of the arrays is exhausted(i.e all values are now in temp)
    //whichiever sub array values are left, we will simply copy it into temp array
    while (i <= m)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= r)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    //from temp to arr
    for (int p = l; p <= r; p++)
    {
        arr[p] = temp[p];
    }
}
void mergesort(int arr[], int l, int r, int n)
{
    if (l < r) //when l=r means only 1 value present hence no more dividing
    {
        int mid = (l + r) / 2;
        mergesort(arr, l, mid, n);     //using recursion(divide and conquer) we keep dividing the array into 2 using midpt
        mergesort(arr, mid + 1, r, n); //then comparision takes place and merge() is used for all those mini arrays
        merge(arr, l, mid, r, n);
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
    mergesort(arr, 0, n - 1, n);

    cout << "Array after merge sort:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}