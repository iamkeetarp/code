#include "iostream"
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int k)
    {
        key = k;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}
int main()
{

    //         10
    //         /\
    //        /  \
    //       20   30
    //       /\    \
    //      /  \    \
    //    40   50    60
    //          /\
    //         /  \
    //        70   80

    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->left->right->left = new Node(70);
    root->left->right->right = new Node(80);

    root->right = new Node(30);
    root->right->right = new Node(60);

    cout << "\nInorder"
         << " ";
    inorder(root);
    cout << "\nPreorder"
         << " ";
    preorder(root);
    cout << "\nPostorder"
         << " ";
    postorder(root);
    return 0;
}
