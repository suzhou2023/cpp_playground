#include <iostream>
#include "../data_structure/btree.h"
#include "../data_structure/utils.h"

using namespace std;

int main()
{
  Tree tree;
  tree.root = tree.createNode(1, "root");

  printBT(tree.root);

  cout << "preOrder: ";
  tree.preOrder(tree.root);
  cout << endl;
  cout << "inOrder: ";
  tree.inOrder(tree.root);
  cout << endl;
  cout << "postOrder: ";
  tree.postOrder(tree.root);
  cout << endl;
}
