#include <iostream>
#include "btree.h"
#include "stack.h"

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

void Tree::preOrderStack(BTree *t)
{
  if (!t)
    return;

  Stack<BTree *> stack = Stack<BTree *>(100);
  stack.push(t);

  // 不需要指针辅助，只需要入栈出栈操作
  while (!stack.isEmpty())
  {
    BTree *node = stack.pop();
    cout << " " << node->value;

    if (node->right)
      stack.push(node->right);
    if (node->left)
      stack.push(node->left);
  }
}

void Tree::inOrderStack(BTree *t)
{
  if (!t)
    return;

  BTree *ptr = t;
  Stack<BTree *> stack = Stack<BTree *>(100);

  // 需要一个指针辅助
  // 指针不为空或栈不为空进行循环
  while (ptr || !stack.isEmpty())
  {
    // 左子树依次入栈
    while (ptr)
    {
      stack.push(ptr);
      ptr = ptr->left;
    }
    // 出栈节点为子树的根
    BTree *node = stack.pop();
    cout << " " << node->value;
    // 将指针移动到节点的右孩子，开始下一轮
    ptr = node->right;
  }
}

void Tree::postOrderStack(BTree *t)
{
  if (!t)
    return;

  BTree *ptr = t;
  BTree *previous_node;
  Stack<BTree *> stack = Stack<BTree *>(100);

  // 需要一个指针辅助
  // 还需要一个变量记录上一次遍历节点
  while (ptr || !stack.isEmpty())
  {
    // 左子树依次入栈
    while (ptr)
    {
      stack.push(ptr);
      ptr = ptr->left;
    }
    // 出栈节点为子树的根
    BTree *node = stack.pop();
    if (previous_node == node->right || !node->right)
    {
      // 出栈节点的右子树已遍历完成，遍历该根节点
      cout << " " << node->value;
      previous_node = node;
    }
    else
    {
      // 出栈节点的右子树未遍历，重新入栈该节点，
      // 将指针移动到右子树，开始下一轮
      stack.push(node);
      ptr = node->right;
    }
  }
}