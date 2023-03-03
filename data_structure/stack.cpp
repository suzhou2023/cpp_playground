#include <iostream>
#include "stack.h"

using namespace std;

Stack::Stack(int capacity)
{
  p_arr = new int[capacity];
  this->capacity = capacity;
  bottom = top = 0;
}

Stack::~Stack()
{
  delete[] p_arr;
}

int Stack::size()
{
  return top - bottom;
}

int Stack::getCapacity()
{
  return capacity;
}

bool Stack::isEmpty()
{
  return top == bottom;
}

bool Stack::isFull()
{
  return top - bottom == capacity;
}

bool Stack::push(int data)
{
  if (isFull())
    return false;
  p_arr[top++] = data;
  return true;
}

int Stack::pop()
{
  if (isEmpty())
    return -1;
  return p_arr[--top];
}

void Stack::print()
{
  cout << "capacity: " << getCapacity() << endl;
  cout << "data size: " << size() << endl;
  cout << "data:" << endl;
  int index = top;
  while (index > bottom)
  {
    cout << p_arr[--index] << endl;
  }
}
