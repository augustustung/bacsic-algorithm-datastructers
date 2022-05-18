#ifndef tree_h
#define tree_h
#include "treenode.h"
#include <iostream>
using namespace std;

template <class T> 
class Tree 
{
private:
  TreeNode<T> *root;
  int height(TreeNode<T> *&node) 
  {
    if (node == 0) 
    {
      return 0;
    }
    return node->height;
  };
  int max(int a, int b) 
  {
    return (a > b) ? a : b; 
  };
  int GetBalance(TreeNode<T> *&node) 
  {
    if (node == 0) 
    {
      return 0;
    }
    return height(node->left) - height(node->right);
  };
  void rightRotate(TreeNode<T> *&x) 
  {
    TreeNode<T> *y = x->left;
    TreeNode<T> *z = y->right;
    y->right = x;
    x->left = z;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    x = y;
  };

  void leftRotate(TreeNode<T> *&x) 
  {
    TreeNode<T> *y = x->right;
    TreeNode<T> *z = y->left;
    y->left = x;
    x->right = z;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    x = y;
  };
  void Balance(TreeNode<T> *&node) 
  {
    if (node == NULL) 
    {
      return;
    }
    int balance = GetBalance(node);
    if (balance > 1) {
      if (GetBalance(node->left) >= 0) // LL
        rightRotate(node);
      else
      {
        leftRotate(node->left);
        rightRotate(node);
      }
    }

    if (balance < -1) 
    {
      if (GetBalance(node->right) <= 0) // RR
        leftRotate(node);
      else // RL
      {
        rightRotate(node->right);
        leftRotate(node);
      }
    }
  };
  void AddToRoot(TreeNode<T> *&node, T v) 
  {
    if (node == 0) 
    {
      node = new TreeNode<T>;
      node->data = v;
      node->left = 0;
      node->right = 0;
    }
    else 
    {
      if (node->data > v)
        AddToRoot(node->left, v);
      else if (node->data < v)
        AddToRoot(node->right, v);
    }
    node->height = 1 + max(height(node->left), height(node->right));
    Balance(node);
  };
  void GetAll(TreeNode<T> *&node) 
  {
    if (node != 0) 
    {
      cout << node->data << " ";
      GetAll(node->left);
      GetAll(node->right);
    }
  }

public:
  Tree() 
  {
    root = 0; 
  };
  void Add(T v) 
  {
    AddToRoot(root, v); 
  };
  void GetLeftToRight() 
  {
    GetAll(root);
    cout << "\n";
  }
};

#endif