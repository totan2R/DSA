#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree()
{
    int value;
    cin >> value;

    if (value == -1)
        return NULL;

    Node *root = new Node(value);

    root->left = buildTree();
    root->right = buildTree();

    return root;
}

Node *BST(Node *root, int value)
{
    if (root == NULL)
    {
        root = new Node(value);;
        return root;
    }

    if (value < root->data)
        root->left = BST(root->left, value);

    else if (value > root->data)
        root->right = BST(root->right, value);

    return root;
}

void PreorderPrint(Node *root)
{
    if (root == NULL)
    {
        cout << "-1 ";
        return;
    }
    cout << root->data << " ";
    PreorderPrint(root->left);
    PreorderPrint(root->right);
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        cout<<-1<<" ";
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    // Node *root = buildTree();
    //  PreorderPrint(root);
    //  cout << endl;

    int n;
    cin >> n;
    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;

        root = BST(root, value);
    }

    // PreorderPrint(root);
    // cout << endl;

    inorder(root);
    cout << endl;
    return 0;
}