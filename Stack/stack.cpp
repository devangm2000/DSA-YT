#include <iostream>
#include <string>
using namespace std;
class Stack
{
private:
    int top;
    int arr[5];

public:
    Stack()
    {
        top = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0; //initially all values to 0
        }
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
    bool isFull()
    {
        if (top == 4)
        {
            return true;
        }
        return false;
    }
    void push(int val)
    {
        if (isFull())
            cout << "Stack Overflow" << endl;
        else
        {
            top++;
            arr[top] = val;
        }
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return 0;
        }
        else
        {
            int popValue = arr[top];
            arr[top] = 0; //asigning popped values to 0
            top--;
            return popValue;
        }
    }
    int count()
    {
        return (top + 1);
    }
    int peek(int pos)
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return 0;
        }
        else
        {
            return arr[pos];
        }
    }
    void change(int pos, int val)
    {
        arr[pos] = val;
        cout << "Item changed at index:" << pos << endl;
    }
    void display()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }
};
int main()
{
    Stack s;
    int option, position, value;
    do
    {
        cout << "Enter your choice. Enter 0 to exit!" << endl;
        cout << "1. Push()" << endl;
        cout << "2. Pop()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. Peek()" << endl;
        cout << "6. Count()" << endl;
        cout << "7. Change()" << endl;
        cout << "8. Display()" << endl;
        cout << "9. Clear Screen" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Enter value to push:" << endl;
            cin >> value;
            s.push(value);
            break;
        case 2:
            cout << "Popped value:" << s.pop() << endl;
            break;
        case 3:
            if (s.isEmpty())
            {
                cout << "Stack is empty" << endl;
            }
            else
            {
                cout << "Stack is not empty" << endl;
            }
            break;
        case 4:
            if (s.isFull())
            {
                cout << "Stack is full" << endl;
            }
            else
            {
                cout << "Stack is not full" << endl;
            }
            break;
        case 5:
            cout << "Enter the index of item to be accessed" << endl;
            cin >> position;
            cout << "Value is:" << s.peek(position) << endl;
            break;
        case 6:
            cout << "Total items in stack:" << s.count() << endl;
            break;
        case 7:
            cout << "Enter index of item to be changed" << endl;
            cin >> position;
            cout << "Enter new value:" << endl;
            cin >> value;
            s.change(position, value);
            break;
        case 8:
            cout << "All the values:" << endl;
            s.display();
            break;
        case 9:
            system("cls");
            break;
        default:
            cout << "Enter correct option values" << endl;
        }

    } while (option != 0);
    return 0;
}
