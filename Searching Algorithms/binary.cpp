#include <iostream>
// #include <bits/stdc++.h>
using namespace std;
int binarysearch(int arr[], int n, int x)
{
    int left = 0;
    int right = n - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1; //if no value==x
}
int main()
{
    int n;
    cout << "Enter array size:";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter array elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    //need a sorted array
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    int x;
    cout << "Enter element to search:";
    cin >> x;
    cout << "Array after sorting elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\n";
    }
    cout << "Element's index:" << endl;
    cout << binarysearch(arr, n, x);
    return 0;
}