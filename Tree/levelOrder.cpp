#include <iostream>
#include <queue>
#include <vector>
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
    std::cout << root->key << " ";
    inorder(root->right);
  }
}
void levelOrder(Node *root)
{
  // vector<vector<Node *>> res;
  if (root == NULL)
    return;
  queue<Node *> q;
  // pushing root into the queue
  q.push(root);
  while (q.empty() == false)
  {
    // making temp node from the front of the queue
    Node *curr = q.front();
    cout << curr->key << " ";
    // removing node after printing
    q.pop();
    if (curr->left != NULL)
      q.push(curr->left);
    if (curr->right != NULL)
      q.push(curr->right);   
  }
}

int main()
{
  Node *root = new Node(10);
  root->left = new Node(20);
  root->left->left = new Node(8);
  root->left->right = new Node(7);
  root->left->right->left = new Node(9);
  root->left->right->right = new Node(15);

  root->right = new Node(30);
  root->right->left = new Node(5);
  root->right->right = new Node(6);
  levelOrder(root);

  return 0;
}