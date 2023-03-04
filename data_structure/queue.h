#ifndef _QUEUE_HEADER
#define _QUEUE_HEADER

#include <iostream>

using namespace std;

template <typename T>
class Queue
{
public:
  Queue(int capacity);
  ~Queue();
  // 队列的元素个数
  int size();
  // 队列的容量
  int getCapacity();
  bool isEmpty();
  bool isFull();
  bool enQueue(T data);
  bool deQueue(T &data);
  void print();

private:
  // 数组指针
  T *p_arr;
  int ARRAY_SIZE;
  // 队列容量
  int capacity;
  // 队首
  int front;
  // 队尾
  int rear;
};

template <typename T>
Queue<T>::Queue(int capacity)
{
  // 循环队列，多申请1个数据单元
  ARRAY_SIZE = capacity + 1;
  p_arr = new T[ARRAY_SIZE];
  this->capacity = capacity;
  front = rear = 0;
}

template <typename T>
Queue<T>::~Queue()
{
  delete[] p_arr;
}

template <typename T>
int Queue<T>::size()
{
  return (rear - front + ARRAY_SIZE) % ARRAY_SIZE;
}

template <typename T>
int Queue<T>::getCapacity()
{
  return capacity;
}

template <typename T>
bool Queue<T>::isEmpty()
{
  return rear == front;
}

template <typename T>
bool Queue<T>::isFull()
{
  return (rear + 1) % ARRAY_SIZE == front;
}

template <typename T>
bool Queue<T>::enQueue(T data)
{
  if (isFull())
  {
    cout << "Warning: enQueue failed, already full." << endl;
    return false;
  }
  p_arr[rear] = data;
  rear = (rear + 1) % ARRAY_SIZE;
  return true;
}

template <typename T>
bool Queue<T>::deQueue(T &data)
{
  if (isEmpty())
    return false;
  data = p_arr[front];
  front = (front + 1) % ARRAY_SIZE;
  return true;
}

template <typename T>
void Queue<T>::print()
{
  cout << "capacity: " << getCapacity() << endl;
  cout << "data size: " << size() << endl;
  cout << "data:" << endl;
  int index = front;
  while (index != rear)
  {
    cout << " " << p_arr[index];
    index = (index + 1) % ARRAY_SIZE;
  }
  cout << endl;
}

#endif
