#include <iostream>
#include <stdlib.h>

#include "../data_structure/stack.h"

using namespace std;

int main()
{
  Stack stack = Stack(20);
  for (int i = 0; i < 10; i++)
  {
    stack.push(rand() % 100);
  }
  stack.print();

  int data = stack.pop();
  cout << "pop: " << data << endl;
  stack.print();

  data = stack.pop();
  cout << "pop: " << data << endl;
  stack.print();
}
