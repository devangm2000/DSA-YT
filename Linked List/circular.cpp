#include <iostream>
using namespace std;
class Node
{
public:
    int key;
    int data;
    Node *next;
    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }
    Node(int k, int d)
    {
        key = k;
        data = d;
        next = NULL;
    }
};
class CircularLinkedList
{
public:
    Node *head;
    CircularLinkedList()
    {
        head = NULL;
    }
    CircularLinkedList(Node *n)
    {
        head = n;
    }
    //check if node exists
    Node *nodeExists(int k)
    {
        Node *temp = NULL;
        Node *ptr = head;
        if (ptr == NULL) //no nodes
        {
            return temp;
        }
        else //do-while loop here cause there's no node with next=NULL
        {
            do
            {
                if (ptr->key == k)
                {
                    temp = ptr;
                }
                ptr = ptr->next;
            } while (ptr != head); //checking with head as then we will complete a full loop of the list
            return temp;
        }
    }
    //append a node to the list
    void appendNode(Node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "Node already exists with key value:" << n->key << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                n->next = head; //circular now(points to itself)
                cout << "Node appended" << endl;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != head)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->next = head;
            }
        }
    }

    //prepend node
    void prependNode(Node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "Node already exists with key value:" << n->key << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                n->next = head;
                cout << "Node prepended as Head Node" << endl;
            }
            else
            {
                Node *ptr = head; //connecting last node to new node
                while (ptr->next != head)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->next = head; //new node to initial first node
                head = n;       //head to new node
            }
        }
    }

    //inserting node after a particualr node
    void insertNode(int k, Node *n)
    {
        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "No node exists with that key" << endl;
        }
        else
        {
            if (nodeExists(n->key) != NULL)
            {
                cout << "Node already exists with key value:" << n->key << endl;
            }
            else
            {
                n->next = ptr->next;
                ptr->next = n;
                cout << "Node inserted" << endl;
            }
        }
    }

    //delete node by key
    void deleteNodebyKey(int k)
    {
        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "No node exists with that key" << endl;
        }
        else
        {
            if (ptr == head)            //deleting the head node
            {                           //head is the only node
                if (head->next == head) //circular
                {
                    head = NULL;
                    cout << "Head node unlinked" << endl;
                }
                else //head isnt the only node
                {
                    Node *temp = head;
                    while (temp->next != head)
                    {
                        temp = temp->next;
                    }
                    temp->next = head->next;
                    head = head->next;
                    cout << "Node unlinked" << endl;
                }
            }
            else //ptr not ==head
            {
                Node *temp = NULL;
                Node *prevpointer = head;
                Node *currentpointer = head->next;
                while (currentpointer != NULL)
                {
                    if (currentpointer->key == k)
                    {
                        temp = currentpointer;
                        currentpointer = NULL;
                    }
                    else
                    {
                        prevpointer = prevpointer->next;
                        currentpointer = currentpointer->next;
                    }
                }
                prevpointer->next = temp->next;
                cout << "Node unlinked" << endl;
            }
        }
    }

    //update node by key
    void updateNodebyKey(int k, int d)
    {
        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "Node does not exist" << endl;
        }
        else
        {
            ptr->data = d;
            cout << "Updated successfully" << endl;
        }
    }

    //print
    void printList()
    {
        if (head == NULL)
        {
            cout << "No nodes in the list" << endl;
        }
        else
        {
            Node *ptr = head;
            do
            {
                cout << "Key:" << ptr->key << " Data:" << ptr->data << endl;
                ptr = ptr->next;
            } while (ptr != head);
        }
    }
};
int main()
{
    CircularLinkedList c;
    int option;
    int key, data, key1;
    do
    {
        cout << "Enter option number. Enter 0 to exit!" << endl;
        cout << "1. appendNode()" << endl;
        cout << "2. prependNode()" << endl;
        cout << "3. insertNodeAfter()" << endl;
        cout << "4. deleteNodebyKey()" << endl;
        cout << "5. updateNodebyKey()" << endl;
        cout << "6. print()" << endl;
        cout << "7. Clear Screen" << endl;
        cin >> option;
        Node *n1 = new Node(); //dynamic memory allocation
        //can do Node *n1; also bu then after each do while iteration, n1 will be destroyed
        switch (option)
        {
        case 1:
            cout << "Enter key:" << endl;
            cin >> key;
            cout << "Enter data:" << endl;
            cin >> data;
            n1->key = key;
            n1->data = data;
            c.appendNode(n1);
            break;
        case 2:
            cout << "Enter key:" << endl;
            cin >> key;
            cout << "Enter data:" << endl;
            cin >> data;
            n1->key = key;
            n1->data = data;
            c.prependNode(n1);
            break;
        case 3:
            cout << "Enter key of new node:" << endl;
            cin >> key;
            cout << "Enter data of new node:" << endl;
            cin >> data;
            n1->key = key;
            n1->data = data;
            cout << "Enter key after which new node is inserted:" << endl;
            cin >> key1;
            c.insertNode(key1, n1);
            break;
        case 4:
            cout << "Enter the key of the node to be deleted:" << endl;
            cin >> key;
            c.deleteNodebyKey(key);
            break;
        case 5:
            cout << "Enter the key of the node:" << endl;
            cin >> key;
            cout << "Enter new data for the key" << endl;
            cin >> data;
            c.updateNodebyKey(key, data);
            break;
        case 6:
            c.printList();
            break;
        case 7:
            system("cls");
            break;
        default:
            cout << "Enter correct option values" << endl;
        }
    } while (option != 0);
    return 0;
}