#include <iostream>
using namespace std;
class Node
{
public:
    int key;
    int data;
    Node *next;
    Node *prev;
    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
        prev = NULL;
    }
    Node(int k, int d)
    {
        key = k;
        data = d;
        next = NULL;
        prev = NULL;
    }
};
class DoublyLinkedList
{
public:
    Node *head;
    DoublyLinkedList()
    {
        head = NULL;
    }
    DoublyLinkedList(Node *n)
    {
        head = n;
    }
    //check if node exists or not
    Node *nodeExists(int k)
    {
        Node *temp = NULL;
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
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
                cout << "Node appended" << endl;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->prev = ptr;
                cout << "Node apppended" << endl;
            }
        }
    }

    //prepend node to start
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
                cout << "Node prepended as Head Node" << endl;
            }
            else
            {
                //head points towards initial first node
                head->prev = n; //linking first node prev to new node
                n->next = head; //linking new node next to first node
                head = n;       //making new node as head
                cout << "Node prepended";
            }
        }
    }
    //insert a new node after a particular node in the list
    void insertNode(int k, Node *n)
    {
        //first check if node exists or not
        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "No node exists with that key" << endl;
        }
        else
        {
            if (nodeExists(n->key) != NULL) //new node key exists
            {
                cout << "Node already exists with key value:" << n->key << endl;
            }
            else
            {
                //inserting at the end(e.g k is the last node key)
                if (ptr->next == NULL)
                {
                    ptr->next = n;
                    n->prev = ptr;
                    cout << "Node inserted at the end" << endl;
                }
                else //inserting in between
                {
                    n->next = ptr->next;
                    ptr->next->prev = n;
                    n->prev = ptr;
                    ptr->next = n;
                    cout << "Node inserted" << endl;
                }
            }
        }
    }
    //deleting node by key(more like unlinking)
    //use delete temp;  to actually delete the node where temp is a pointer to the node
    void deleteNodebyKey(int k)
    {
        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "No node exists with that key" << endl;
        }
        else
        {
            if (head->key == k)
            {
                head = head->next;
                cout << "Node unlinked with key values:" << k << endl;
            }
            else
            {
                Node *nextNode = ptr->next;
                Node *prevNode = ptr->prev;
                //deleting last node
                if (nextNode == NULL)
                {
                    prevNode->next = NULL;
                    cout << "Node deleted at the end";
                }
                else
                {
                    prevNode->next = nextNode;
                    nextNode->prev = prevNode;
                    cout << "Node deleted" << endl;
                }
            }
        }
    }
    //updating node by key
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

    //printing
    void printList()
    {
        if (head == NULL)
        {
            cout << "No nodes in the list" << endl;
        }
        else
        {
            Node *ptr = head;
            while (ptr != NULL)
            {
                cout << "Key:" << ptr->key << " Data:" << ptr->data << endl;
                ptr = ptr->next;
            }
        }
    }
};

int main()
{
    DoublyLinkedList obj;
    int option;
    int key, data, key1;
    do
    {
        cout << "Enter option nmuber. Enter 0 to exit!" << endl;
        cout << "1. appendNode()" << endl;
        cout << "2. prependNode()" << endl;
        cout << "3. insertNodeAfter()" << endl;
        cout << "4. deleteNodebyKey()" << endl;
        cout << "5. updateNodebyKey()" << endl;
        cout << "6. print()" << endl;
        cout << "7. Clear Screen" << endl;
        cin >> option;
        Node *n1 = new Node(); //dynamic memory allocation
        //can do Node *n1; also but then after each do while iteration, n1 will be destroyed
        switch (option)
        {
        case 1:
            cout << "Enter key:" << endl;
            cin >> key;
            cout << "Enter data:" << endl;
            cin >> data;
            n1->key = key;
            n1->data = data;
            obj.appendNode(n1);
            break;
        case 2:
            cout << "Enter key:" << endl;
            cin >> key;
            cout << "Enter data:" << endl;
            cin >> data;
            n1->key = key;
            n1->data = data;
            obj.prependNode(n1);
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
            obj.insertNode(key1, n1);
            break;
        case 4:
            cout << "Enter the key of the node to be deleted:" << endl;
            cin >> key;
            obj.deleteNodebyKey(key);
            break;
        case 5:
            cout << "Enter the key of the node:" << endl;
            cin >> key;
            cout << "Enter new data for the key" << endl;
            cin >> data;
            obj.updateNodebyKey(key, data);
            break;
        case 6:
            obj.printList();
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
