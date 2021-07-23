#include <iostream>
using namespace std;
#define SPACE 10;
class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
    {
        value = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int v)
    {
        value = v;
        left = NULL;
        right = NULL;
    }
};
class BST
{
public:
    TreeNode *root = NULL;
    bool isEmpty()
    {
        if (root == NULL)
        {
            return true;
        }
        return false;
    }
    void InsertNode(TreeNode *new_node)
    {
        if (root == NULL)
        {
            root = new_node;
            cout << "Value inserted as root node." << endl;
        }
        else
        {
            TreeNode *temp = root;
            while (temp != NULL)
            {
                if (new_node->value == temp->value)
                {
                    cout << "Value already exists." << endl;
                    return;
                }
                else if (new_node->value < temp->value && temp->left == NULL)
                {
                    temp->left = new_node;
                    cout << "Value inserted." << endl;
                    break;
                }
                else if (new_node->value < temp->value)
                {
                    temp = temp->left;
                    break;
                }
                else if (new_node->value > temp->value && temp->right == NULL)
                {
                    temp->right = new_node;
                    cout << "Value inserted." << endl;
                    break;
                }
                else
                {
                    temp = temp->right;
                    break;
                }
            }
        }
    }
};
int main()
{
    BST obj;
    int option, val;
    do
    {
        cout << "Enter option nmuber. Enter 0 to exit!" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Search Node" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Print BST values" << endl;
        cout << "5. Clear Screen" << endl;
        cin >> option;
        TreeNode *new_node = new TreeNode();
        switch (option)
        {
        case 1:
            cout << "Insert value:" << endl;
            cin >> val;
            new_node->value = val;
            obj.InsertNode(new_node);
            break;
        case 2:
            cout << "Search value:" << endl;
            break;
        case 3:
            cout << "Delete value:" << endl;
            break;
        case 4:
            cout << "BST:" << endl;
            break;
        case 5:
            system("cls");
            break;
        default:
            cout << "Enter correct option values" << endl;
        }

    } while (option != 0);
}