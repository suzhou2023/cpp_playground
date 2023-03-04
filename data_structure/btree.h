#ifndef _BTREE_HEADER
#define _BTREE_HEADER

#include <string>

using namespace std;

typedef struct btree_node
{
  int value;
  struct btree_node *left, *right;
} BTree;

class Tree
{
public:
  BTree *createNode(int level, string pos);
  void preOrder(BTree *t);
  void inOrder(BTree *t);
  void postOrder(BTree *t);
  void preOrderStack(BTree *t);
  void inOrderStack(BTree *t);
  void postOrderStack(BTree *t);
  void levelOrder(BTree *t);

  BTree *root;
};

#endif
