#ifndef _STACK_HEADER
#define _STACK_HEADER

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
  bool push(int data);
  int pop();
  void print();

private:
  // 数组指针
  int *p_arr;
  // 容量
  int capacity;
  // 栈底
  int bottom;
  // 栈顶
  int top;
};

#endif
