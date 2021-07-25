#include <iostream>
#define GLOBALSPACE 10
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
            // break;
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
                else if ((new_node->value < temp->value) && (temp->left == NULL))
                {
                    temp->left = new_node;
                    cout << "Value inserted to the left." << endl;
                    break;
                }
                else if (new_node->value < temp->value)
                {
                    temp = temp->left;
                }
                else if ((new_node->value > temp->value) && (temp->right == NULL))
                {
                    temp->right = new_node;
                    cout << "Value inserted to the right." << endl;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
    void printPreorder(TreeNode *r) //Node Left Right
    {
        if (r == NULL)
        {
            return;
        }
        cout << r->value << " ";
        printPreorder(r->left);
        printPreorder(r->right);
    }
    void printInorder(TreeNode *r) //Left Node Right
    {
        if (r == NULL)
        {
            return;
        }
        printInorder(r->left);
        cout << r->value << " ";
        printInorder(r->right);
    }
    void printPostorder(TreeNode *r) //Left Right Node
    {
        if (r == NULL)
        {
            return;
        }
        printPostorder(r->left);
        printPostorder(r->right);
        cout << r->value << " ";
    }
    void print2D(TreeNode *r, int space)
    {
        if (r == NULL) // Base case  1
            return;
        space += GLOBALSPACE;     // Increase distance between levels   2
        print2D(r->right, space); // Process right child first 3
        cout << endl;
        for (int i = 0; i < space; i++) // 5
            cout << " ";                // 5.1
        cout << r->value << "\n";       // 6
        print2D(r->left, space);        // Process left child  7
    }
};
int main()
{
    BST obj;
    int option, val;
    do
    {
        cout << "\nEnter option nmuber. Enter 0 to exit!" << endl;
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
            obj.print2D(obj.root, 5);
            cout << "\nPre Order:" << endl;
            obj.printPreorder(obj.root);
            cout << "\nIn Order:" << endl;
            obj.printInorder(obj.root);
            cout << "\nPost Order:" << endl;
            obj.printPostorder(obj.root);
            break;
        case 5:
            system("cls");
            break;
        default:
            cout << "Enter correct option values" << endl;
        }

    } while (option != 0);
}