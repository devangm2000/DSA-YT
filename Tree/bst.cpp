#include <iostream>
using namespace std;
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
    TreeNode *root;
    bool isEmpty()
    {
        if (root == NULL)
        {
            return true;
        }
        return false;
    }
    void InsertNode(TreeNode *new_node, int value)
    {
        if (root == NULL)
        {
            root = new TreeNode(value);
        }
        else if (value > root->value)
        {
            // root->right=InsertNode(root->right,value);
        }
        else
        {
        }
    }
};
int main()
{
    int option;
    do
    {
        cout << "Enter option nmuber. Enter 0 to exit!" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Search Node" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Print BST values" << endl;
        cout << "5. Clear Screen" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Insert value:" << endl;
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