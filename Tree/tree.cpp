#include <iostream>
#include <queue>
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
    int data;
    cin >> data;

    if (data == -1)
        return NULL;

    Node *root = new Node(data);

    root->left = buildTree();
    root->right = buildTree();

    return root;
}

void printTree(Node *root)
{
    if (root == NULL)
    {
        cout << "-1 ";
        return;
    }
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

void InorderTraverse(Node *root)
{
    // base case
    if (root == NULL)
        return;

    // recursive call
    InorderTraverse(root->left);  // L
    cout << root->data << " ";    // N
    InorderTraverse(root->right); // R
}

void PreorderTraverse(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";     // N
    PreorderTraverse(root->left);  // L
    PreorderTraverse(root->right); // R
}

void PostorderTraverse(Node *root)
{
    if (root == NULL)
        return;

    PostorderTraverse(root->left);  // L
    PostorderTraverse(root->right); // R
    cout << root->data << " ";      // N
}

void LevelorderTraverse(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *cur = q.front();
        q.pop();

        if (cur == NULL)
        {
            cout << endl;

            if (q.empty())
                return;
            else
                q.push(NULL);
        }
        else
        {
            cout << cur->data << " ";

            if (cur->left != NULL)
                q.push(cur->left);

            if (cur->right != NULL)
                q.push(cur->right);
        }
    }
}

int main()
{
    Node *root = buildTree();

    printTree(root);
    cout << endl;

    cout<<"Inorder   ->  ";
    InorderTraverse(root);
    cout << endl;

    cout<<"Preorder  ->  ";
    PreorderTraverse(root);
    cout << endl;

    cout<<"Postorder ->  ";
    PostorderTraverse(root);
    cout << endl;

    cout<<"Levelorder :\n";
    LevelorderTraverse(root);
    return 0;
}
