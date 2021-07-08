#include <iostream>
using namespace std;
void linearsearch(int arr[], int n, int x)
{
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            cout << "Element found at index:" << i << endl;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << "No such element found";
    }
}
int main()
{
    int n;
    cout << "Enter array size:";
    cin >> n;
    int arr[n];
    cout << "Enter array elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int x;
    cout << "Enter element to search:";
    cin >> x;
    linearsearch(arr, n, x);
}