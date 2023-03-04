#include <iostream>
#include <stdlib.h>

#include "../data_structure/queue.h"

using namespace std;

int main()
{
  Queue<int> queue = Queue<int>(10);
  for (int i = 0; i < 12; i++)
  {
    queue.enQueue(rand() % 100);
  }
  queue.print();

  int data;
  int &r = data;
  queue.deQueue(r);
  cout << "deQueue: " << data << endl;
  queue.print();

  queue.enQueue(8);
  cout << "enQueue: " << 8 << endl;
  queue.print();

  queue.deQueue(r);
  cout << "deQueue: " << data << endl;
  queue.print();

  queue.enQueue(66);
  cout << "enQueue: " << 66 << endl;
  queue.print();

  queue.deQueue(r);
  cout << "deQueue: " << data << endl;
  queue.print();
}
