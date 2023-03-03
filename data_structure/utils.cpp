#include <iostream>
#include "utils.h"
#include "btree.h"

using namespace std;

void printBT(const string prefix, const BTree *node, bool isLeft)
{
  if (node != NULL)
  {
    cout << prefix;

    cout << (isLeft ? "├──" : "└──");

    // print the value of the node
    cout << node->value << endl;

    // enter the next tree level - left and right branch
    printBT(prefix + (isLeft ? "│   " : "    "), node->left, true);
    printBT(prefix + (isLeft ? "│   " : "    "), node->right, false);
  }
}

void printBT(const BTree *t)
{
  printBT("", t, false);
}