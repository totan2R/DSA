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

Node *BST(Node *root, int value)
{
    if (root == NULL)
    {
        root = new Node(value);
        return root;
    }

    if (value < root->data)
        root->left = BST(root->left, value);

    else if (value > root->data)
        root->right = BST(root->right, value);

    return root;
}

bool searchBST(Node *root, int value)
{
    if (root == NULL)
        return false;

    if (value == root->data)
        return true;

    if (value < root->data)
        return searchBST(root->left, value);

    else
        return searchBST(root->right, value);
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
        cout << -1 << " ";
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    int n;
    cin >> n;
    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;

        root = BST(root, value);
    }

    inorder(root);
    cout << endl;

    int key;
    cin >> key;
    // if (searchBST(root, key) == NULL)
    // {
    //     cout << "value does not exits" << endl;
    // }
    // else
    //     cout << "value found!" << endl;

    cout << searchBST(root, key) << endl;
    return 0;
}