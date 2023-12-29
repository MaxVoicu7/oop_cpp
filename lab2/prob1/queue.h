#include <iostream>

class Queue {
  private:
    int *data;      // keeps the pointer to the array allocated dinamically
    int size;       // keeps the size of the queue
    int capacity;   // keeps the maximum amount of elements we can have in a queue

  public:
    // constructors
    Queue();
    Queue(const Queue &q);
    Queue(const int sizeValue, const int capacityValue);

    // destructor
    ~Queue();

    void displayQueue();
    void initializeData();

    void addElement(int element);
    void getElement();

    bool isEmpty();
    bool isFull();

    int getSize();
    int getCapacity();

    void extendCapacity(int newCapacity);
};