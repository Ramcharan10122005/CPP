#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = right = nullptr;
    }
};

Node *buildTree()
{
    int d;
    cin >> d;

    if (d == -1)
        return nullptr;

    Node *n = new Node(d);
    n->left = buildTree();
    n->right = buildTree();

    return n;
}

void printPreOrder(Node *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printInOrder(Node *root)
{
    if (root == nullptr)
        return;
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

void printPostOrder(Node *root)
{
    if (root == nullptr)
        return;

    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

// use a datastructure "Queue" to keep track address of the previous node and traverse iteratively.
void printLevelOrder(Node *root)
{
    if (root == nullptr)
        return;

    queue<Node *> qu;
    qu.push(root);
    qu.push(nullptr);

    while (!qu.empty())
    {
        Node *temp = qu.front();
        if (temp == nullptr)
        {

            cout << endl;
            qu.pop();
            if (!qu.empty())
            {
                qu.push(nullptr);
            }
        }
        else
        {
            qu.pop();
            cout << temp->data << " ";
            if (temp->left)
            {
                qu.push(temp->left);
            }
            if (temp->right)
            {
                qu.push(temp->right);
            }
        }
    }
}

int heightOfTree(Node *root)
{
    int height;
    if (root == nullptr)
        return 0;
    int h1 = heightOfTree(root->left);
    int h2 = heightOfTree(root->right);
    return 1 + max(h1, h2);
}

int main()
{
    Node *root = buildTree();
    cout << "Pre-Order : ";
    printPreOrder(root);
    cout << endl;
    cout << "In-Order : ";
    printInOrder(root);
    cout << endl;
    cout << "Post-Order : ";
    printPostOrder(root);
    cout << endl;
    cout << "Level-Order : " << endl;
    printLevelOrder(root);
    cout << "height of the tree: " << heightOfTree(root) << endl;
    return 0;
}

// 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1