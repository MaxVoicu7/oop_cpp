#ifndef QUEUE_H
#define QUEUE_H

#include "container.h"
#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

class Queue : public Container {
  private:
    int *data;
    int capacity;
    int front;
    int back;

  public:
    // constructors
    Queue(int capacity = 10);
    Queue(const Queue& other);

    // destructor
    ~Queue();

    // operators
    Queue& operator=(const Queue& other);
    friend ostream& operator<<(ostream& os, const Queue& queue);

    // functions to be overwritten
    void insert(int value) override;
    int extract() override;
    void display() override;

    // additional functions
    int frontElement() const;
    int backElement() const;
    int size() const;
    int getCapacity() const;
    bool isFull() const;
    bool isEmpty() const;
    void extendCapacity();
};

#endif