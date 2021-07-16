#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
void push(Node **head, int key)
{
    Node *newnode = new Node();
    newnode->data = key;
    newnode->next = NULL;
    if (*head == NULL)
    {
        *head = newnode;
        return;
    }
    else
    {
        Node *ptr = *head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        return;
    }
}
bool search(Node *head, int key)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data == key)
        {
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}
void print(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
int main()
{
    Node *head = NULL;
    cout << "Enter size:";
    int n;
    cin >> n;
    int *arr = new int[n];
    cout << "Enter elements:";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        push(&head, arr[i]);
    }
    cout << "Enter element to be found:";
    int x;
    cin >> x;
    if (search(head, x))
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }
    cout << "All elements in LL:" << endl;
    print(head);
}