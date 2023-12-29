#ifndef STACK_H
#define STACK_H

#include "container.h"
#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

class Stack : public Container {
  private:
    int *data;
    int capacity;
    int top;

  public:
    // constructors
    Stack(int capacity = 10);
    Stack(int value1, int value2);
    Stack(const Stack& other);

    // destructor
    ~Stack();

    // operators
    Stack& operator=(const Stack& other);
    friend ostream& operator<<(ostream& os, const Stack& stack);

    // functions to be overwritten
    void insert(int value) override;
    int extract() override;
    void display() override;

    // additional functions
    void extendCapacity();
    int topElement() const;
    bool isEmpty() const;
    bool isFull() const;
    int size() const;
    int getCapacity() const;
};

#endif