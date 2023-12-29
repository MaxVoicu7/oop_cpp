#include <sstream>
#include "queue.h"
#include "readData.h"

// implicit constructor
Queue::Queue() {
  data = nullptr;
  size = 0;
  capacity = 0;
}


// copy constructor
Queue::Queue(const Queue &q) {
  try {
    data = new int[q.capacity];

    for (int i = 0; i < q.size; ++i)
      data[i] = q.data[i];

  } catch (std::bad_alloc& ba) {
    std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
    throw;
  }

  size = q.size;
  capacity = q.capacity;
}


// parameterized constructor
Queue::Queue(const int sizeValue, const int capacityValue) {
  // parameters are checked before calling the function
  try {
    data = new int[capacityValue];
  } catch (std::bad_alloc& ba) {
    std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
    throw;
  }

  size = sizeValue;
  capacity = capacityValue;
  initializeData();
}


// destructor 
Queue::~Queue() {
  delete [] data;
}


// displaying the queue info and the queue itself
void Queue::displayQueue() {
  std::cout << std::endl << "Queue capacity: " << capacity << std::endl;
  std::cout << "Queue size: " << size << std::endl << std::endl;
  std::cout << "Queue: ";

  for(int i = 0; i < size; i++)
    std::cout << data[i] << " ";

  std::cout << std::endl;
}


// initializing the queue with data
// all the space that is not completed by size will be completed with 0
void Queue::initializeData() {
  std::cout << std::endl;

  for (int i = 0; i < size; i++) {
    std::stringstream ss;
    ss << "Enter the " << (i + 1) << "th element of the queue: ";
    data[i] = readInt(ss.str());
  }

  for (int i = size; i < capacity; i++) {
    data[i] = 0;
  }
}


//  adding an element to the end of the queue
void Queue::addElement(int element) {
  if (size >= capacity) {
    std::cout << std::endl << "NO FREE SPACE IN THE QUEUE. INCREMENT THE CAPACITY" << std::endl;
    return;
  }

  data[size] = element;
  size++;
}


// checking if the queue is empty
bool Queue::isEmpty() {
  return (size == 0);
}


// checking if the queue is full
bool Queue::isFull() {
  return (size == capacity);
}
 

// removing the first element of the queue
void Queue::getElement() {
  if (isEmpty()) {
    std::cout << std::endl << "QUEUE IS EMPTY. IMPOSSIBLE TO GET AN ELEMENT" << std::endl;
    return;
  }

  std::cout << std::endl << "Element out of queue: " << data[0] << std::endl;

  for (int i = 1; i < size; i++) 
    data[i - 1] = data[i];

  data[size - 1] = 0;
  size--;
}


// getting the size of the queue
int Queue::getSize() {
  return size;
}


// getting the capacity of the queue
int Queue::getCapacity() {
  return capacity;
}


// extending the capacity, the capacity is checked before calling the function
void Queue::extendCapacity(int newCapacity) {
  int *newArray;

  try {
    newArray = new int[newCapacity];
  } catch (std::bad_alloc& ba) {
    std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
    throw;
  }

  for (int i = 0; i < size; i++)
    newArray[i] = data[i];

  for (int i = size; i < newCapacity; i++)
    newArray[i] = 0;

  delete [] data;
  data = newArray;
  newArray = nullptr;

  capacity = newCapacity;
}