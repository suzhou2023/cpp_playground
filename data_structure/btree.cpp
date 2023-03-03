#include <iostream>
#include "btree.h"

using namespace std;

BTree *Tree::createNode(int level, string pos)
{
  int data;
  cout << "Please enter data, level " << level << " " << pos << ": ";
  cin >> data;

  if (data == 0)
    return NULL;

  BTree *node = new BTree;

  node->value = data;
  node->left = createNode(level + 1, "left");
  node->right = createNode(level + 1, "right");

  return node;
}

void Tree::preOrder(BTree *t)
{
  if (!t)
    return;

  cout << " " << t->value;
  preOrder(t->left);
  preOrder(t->right);
}

void Tree::inOrder(BTree *t)
{
  if (!t)
    return;

  inOrder(t->left);
  cout << " " << t->value;
  inOrder(t->right);
}

void Tree::postOrder(BTree *t)
{
  if (!t)
    return;

  postOrder(t->left);
  postOrder(t->right);
  cout << " " << t->value;
}