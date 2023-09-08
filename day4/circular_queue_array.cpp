#include <iostream>
#include <stdlib.h>

using namespace std;

class CircularQueue {
private:
  int head;
  int tail;
  int *queue;
  int length;
  int size;

public:
  CircularQueue(int);
  ~CircularQueue();
  int getLength();
  void enqueue(int);
  int dequeue();
};

CircularQueue::CircularQueue(int size) {
  queue = new int[size];
  this->size = size;
  length = 0;
  head = -1;
  tail = -1;
}

CircularQueue::~CircularQueue() { delete[] queue; }

int CircularQueue::getLength() { return length; }

void CircularQueue::enqueue(int value) {
  if (length == 0) {
    head = 0;
  }

  length++;

  if (length > size) {
    cout << "Overflow" << endl;
    exit(1);
  }

  tail++;
  tail %= size;

  queue[tail] = value;
}

int CircularQueue::dequeue() {
  int temp;

  if (length <= 0) {
    cout << "Underflow" << endl;
    exit(1);
  }

  temp = queue[head];

  head++;
  head %= size;
  length--;

  return temp;
}

int main() {
  int size = 5;
  CircularQueue *q = new CircularQueue(size);
  int errCode = 0;
  int result;
  int length;
  int trueLength;

  trueLength = 0;

  // Test: Enqueue increases length
  for (int i = 0; i < size; i++) {
    q->enqueue(i + 1);
    trueLength++;
  }

  length = q->getLength();
  if (length != trueLength) {
    errCode = 1;
    cout << "expected length to be " << trueLength << "but found " << length
         << endl;
  }

  // Test: Dequeue decreases length
  for (int i = 0; i < 3; i++) {
    q->dequeue();
    trueLength--;
  }

  length = q->getLength();
  if (length != trueLength) {
    errCode = 1;
    cout << "expected length to be " << trueLength << "but found " << length
         << endl;
  }

  // Test: Circular Nature of Queue
  for (int i = 1; i <= 2; i++) {
    q->enqueue(size + i);
    trueLength++;
  }

  length = q->getLength();
  if (length != trueLength) {
    errCode = 1;
    cout << "expected length to be " << trueLength << "but found " << length
         << endl;
  }

  for (int i = 0; i < trueLength; i++) {
    result = q->dequeue();
    if (result != i + 4) {
      errCode = 1;
      cout << "expected value" << i << "x dequeue to be " << i + 4
           << " but found " << result << endl;
    }
  }

  if (!errCode) {
    cout << "Passed tests" << endl;
  }

  return errCode;
}
