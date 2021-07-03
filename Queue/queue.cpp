#include <iostream>
using namespace std;
class Queue
{
private:
    int front;
    int rear;
    int arr[5];

public:
    Queue()
    {
        front = -1;
        rear = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0; //initially all values to 0
        }
    }
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        return false;
    }
    bool isFull()
    {
        if (rear == 4) //length(array)-1
        {
            return true;
        }
        return false;
    }
    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue is full." << endl;
        }
        else if (isEmpty())
        {
            rear = front = 0;
            arr[rear] = val;
        }
        else
        {
            rear++;
            arr[rear] = val;
        }
    }
    int dequeue()
    {
        int x = 0;
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return 0;
        }
        else if (front == 0 && rear == 0)
        {
            x = arr[front];
            arr[front] = 0;
            front = rear = -1;
            return x;
        }
        else
        {
            x = arr[front];
            arr[front] = 0;
            front++;
            return x;
        }
    }
    int peek(int pos)
    {
        if (isEmpty())
        {
            cout << "Underflow" << endl;
            return 0;
        }
        else
        {
            return arr[pos];
        }
    }
    int count()
    {
        return ((rear - front) + 1);
    }
    void change(int pos, int val)
    {
        arr[pos] = val;
        cout << "Item changed at index:" << pos << endl;
    }
    void display()
    {
        for (int i = 0; i < 5; i++)
        {
            cout << arr[i] << endl;
        }
    }
};
int main()
{
    Queue q;
    int option, value, position;
    do
    {
        cout << "Enter your choice. Enter 0 to exit!" << endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
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
            q.enqueue(value);
            break;
        case 2:
            cout << "Popped value:" << q.dequeue() << endl;
            break;
        case 3:
            if (q.isEmpty())
            {
                cout << "Queue is empty" << endl;
            }
            else
            {
                cout << "Queue is not empty" << endl;
            }
            break;
        case 4:
            if (q.isFull())
            {
                cout << "Queue is full" << endl;
            }
            else
            {
                cout << "Queue is not full" << endl;
            }
            break;
        case 5:
            cout << "Enter the index of item to be accessed" << endl;
            cin >> position;
            cout << "Value is:" << q.peek(position) << endl;
            break;
        case 6:
            cout << "Total items in queue:" << q.count() << endl;
            break;
        case 7:
            cout << "Enter index of item to be changed" << endl;
            cin >> position;
            cout << "Enter new value:" << endl;
            cin >> value;
            q.change(position, value);
            break;
        case 8:
            cout << "All the values:" << endl;
            q.display();
            break;
        case 9:
            system("cls");
            break;
        default:
            cout << "Enter correct option values" << endl;
        }

    } while (option != 0);
    return 0;
    //once we dequeue, values from front are removed(FIFO)
    //but rear stays at that position only hence it will show Full
    //once we dequeue all 5 positions, we can enqueue only after that, else no enqueued values will be shown
    //circular queue hence better
}