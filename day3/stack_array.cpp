#include <iostream>
#include <stdlib.h>

using namespace std;

class Stack {
private:
  int top;
  int size;
  int *stack;

public:
  Stack(int);
  ~Stack();
  bool isEmpty();
  void push(int);
  int pop();
};

Stack::Stack(int size) {
  stack = new int[size];
  this->size = size;
  top = -1;
}

Stack::~Stack() { delete[] stack; }

bool Stack::isEmpty() { return top == -1; }

void Stack::push(int value) {
  top++;
  if (top >= size) {
    cout << "Overflow" << endl;
    exit(1);
  }
  stack[top] = value;
}

int Stack::pop() {
  if (this->isEmpty()) {
    cout << "Underflow" << endl;
    exit(1);
  }
  top--;
  return stack[top + 1];
}

int main() {
  int size = 5;
  Stack *s = new Stack(size);
  int errCode = 0;
  int result;

  for (int i = 0; i < size; i++) {
    s->push(i + 1);
  }

  for (int i = size; i > 0; i--) {
    result = s->pop();
    if (result != i) {
      errCode = 1;
      cout << "expected value" << size - i + 1 << "x pop to be " << i
           << " but found " << result << endl;
    }
  }

  if (!errCode) {
    cout << "Passed tests" << endl;
  }

  return errCode;
}
