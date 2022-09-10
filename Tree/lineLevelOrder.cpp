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
vector<vector<int> > levelOrder(Node *root)
{
  vector<vector<int> > res;
  if (root == NULL)
    return res;
  queue<Node *> q;
  // pushing root into the queue
  q.push(root);
  while (q.empty() == false)
  {
    vector<int> row;
    // making temp node from the front of the queue
    Node *curr = q.front();
    int qs = q.size();    
    while(qs--)
    {
        Node *curr = q.front();
        q.pop();
        row.push_back(curr->key);
        // removing node after printing
        if (curr->left != NULL)
        q.push(curr->left);
        if (curr->right != NULL)
        q.push(curr->right);  
    }
    res.push_back(row);     
  }
  return res;
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
  vector<vector<int > > res = levelOrder(root);
  for(int i=0;i<res.size();i++)
  {
    for(int j=0;j<res[i].size();j++)
    {
        cout << res[i][j] << " ";
    }
    cout << "" << endl;
  }
  return 0;
}