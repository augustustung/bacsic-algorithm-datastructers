#ifndef treenode_h
#define treenode_h
template <class T>
struct TreeNode 
{
  int height;
  T data;
  TreeNode<T> *left;
  TreeNode<T> *right;
};

#endif