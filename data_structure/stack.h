#ifndef _STACK_HEADER
#define _STACK_HEADER

#include <iostream>

using namespace std;

template <typename T>
class Stack
{
public:
  Stack(int capacity);
  ~Stack();
  // 栈的元素个数
  int size();
  // 栈的容量
  int getCapacity();
  bool isEmpty();
  bool isFull();
  bool push(T data);
  T pop();
  void print();

private:
  // 数组指针
  T *p_arr;
  // 容量
  int capacity;
  // 栈底
  int bottom;
  // 栈顶
  int top;
};

template <typename T>
Stack<T>::Stack(int capacity)
{
  p_arr = new T[capacity];
  this->capacity = capacity;
  bottom = top = 0;
}

template <typename T>
Stack<T>::~Stack()
{
  delete[] p_arr;
}

template <typename T>
int Stack<T>::size()
{
  return top - bottom;
}

template <typename T>
int Stack<T>::getCapacity()
{
  return capacity;
}

template <typename T>
bool Stack<T>::isEmpty()
{
  return top == bottom;
}

template <typename T>
bool Stack<T>::isFull()
{
  return top - bottom == capacity;
}

template <typename T>
bool Stack<T>::push(T data)
{
  if (isFull())
  {
    cout << "Warning: push failed, stack full." << endl;
    return false;
  }
  p_arr[top++] = data;
  return true;
}

template <typename T>
T Stack<T>::pop()
{
  if (isEmpty())
    return NULL;
  return p_arr[--top];
}

template <typename T>
void Stack<T>::print()
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

#endif
