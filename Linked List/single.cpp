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
    Node(int key, int data)
    {
        key = key;
        data = data;
    }
};
class SinglyLinkedList
{
public:
    Node *head; //always points to the head of the linked list
    SinglyLinkedList()
    {
        head = NULL;
    }
    SinglyLinkedList(Node *n)
    {
        head = n;
    }
    //to check if node exists or not using key values
    Node *nodeExists(int k)
    {
        Node *temp = NULL;
        Node *ptr = head; //points to the head node
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
        //first check if key exists or not
        if (nodeExists(n->key) != NULL) //key exists
        {
            cout << "Node already exists with key value:" << n->key << endl;
        }
        else //key doesnt exist
        {
            if (head == NULL) //no node initally in the list
            {
                head = n;
                cout << "Node appended" << endl;
            }
            else
            {
                Node *ptr = head; //new pointer for traversing to the last node
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                cout << "Node apppended" << endl;
            }
        }
    }
    //prepend node-attah node at start
    void prependNode(Node *n)
    {
        //first check if key exists or not
        if (nodeExists(n->key) != NULL) //key exists
        {
            cout << "Node already exists with key value:" << n->key << endl;
        }
        else
        {
            //dont have to travers throught the whole list like appendNode()
            n->next = head; //(head points towards initial 1st node)
            head = n;       //now head points towards new node
            cout << "Node appended";
        }
    }
    //inserting a node after a particular node in the list
    void insertNode(int k, Node *n) //key of the node after which we want to attach the new node
    {
        //first we check if node with key k exists or not
        Node *ptr = nodeExists(k); //new pointer directly to node with key k
        if (ptr == NULL)
        {
            cout << "No node exists with that key" << endl;
        }
        else
        {
            //now we check if new node k is duplicate or not
            if (nodeExists(n->key) != NULL) //key exists
            {
                cout << "Node already exists with key value:" << n->key << endl;
            }
            else
            {
                // e.g n2-n4-n3
                n->next = ptr->next; //n4 to n3
                ptr->next = n;       //n2 to n4
                cout << "Node inserted" << endl;
            }
        }
    }
    //delete code by unique key
    void deleteNodebyKey(int k)
    {
        if (head == NULL)
        {
            cout << "Singly Linked List is already empty. Cant delte" << endl;
        }
        else if (head != NULL)
        { //deleting head node
            if (head->key == k)
            {
                head = head->next;
                cout << "Node unlinked with key value:" << k << endl;
            }
            else
            {
                Node *temp = NULL;
                Node *prevptr = head;
                Node *currentptr = head->next;
                while (currentptr != NULL)
                {
                    if (currentptr->key == k)
                    {
                        temp = currentptr;
                        currentptr = NULL;
                    }
                    else
                    {
                        prevptr = prevptr->next;
                        currentptr = currentptr->next;
                    }
                }
                if (temp != NULL)
                {
                    prevptr->next = temp->next;
                    cout << "Node unlinked with key:" << k << endl;
                }
                else
                {
                    cout << "Node doesnt exist with key value:" << k << endl;
                }
            }
        }
    }
    void updateNodebyKey(int k, int d)
    {
        Node *ptr = nodeExists(k);
        if (ptr != NULL)
        {
            ptr->data = d;
            cout << "Node data updated successfully" << endl;
        }
        else
        {
            cout << "Node doesnt exist with key value:" << k << endl;
        }
    }
    void printList()
    {
        if (head == NULL)
        {
            cout << "No nodes in the list" << endl;
        }
        else
        {
            cout << "Values:" << endl;
            Node *temp = head;
            while (temp != NULL)
            {
                cout << "Key:" << temp->key << " Data:" << temp->data << endl;
                temp = temp->next;
            }
        }
    }
};
int main()
{
    SinglyLinkedList s;
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
            s.appendNode(n1);
            break;
        case 2:
            cout << "Enter key:" << endl;
            cin >> key;
            cout << "Enter data:" << endl;
            cin >> data;
            n1->key = key;
            n1->data = data;
            s.prependNode(n1);
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
            s.insertNode(key1, n1);
            break;
        case 4:
            cout << "Enter the key of the node to be deleted:" << endl;
            cin >> key;
            s.deleteNodebyKey(key);
            break;
        case 5:
            cout << "Enter the key of the node:" << endl;
            cin >> key;
            cout << "Enter new data for the key" << endl;
            cin >> data;
            s.updateNodebyKey(key, data);
            break;
        case 6:
            s.printList();
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