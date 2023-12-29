#include "queue.h"

// ================= CONSTRUCTORS AND DESTRUCTOR =====================

// parameterized constructor
Queue::Queue(int capacity) : capacity{capacity}, front{-1}, back{-1} {
  data = new int[capacity];
}

// copy constructor
Queue::Queue(const Queue &other) : capacity{other.capacity}, front{other.front}, back{other.back} {
  data = new int[capacity];

  for (int i = 0; i <= back; i++) 
    data[i] = other.data[i];
}

// destructor 
Queue::~Queue() {
  delete [] data;
}



// ==================== OPERATORS =======================

// = operator
Queue& Queue::operator=(const Queue &other) {
  if (this != &other) {
    delete[] data;

    capacity = other.capacity;
    front = other.front;
    back = other.back;
    data = new int[capacity];

    for (int i = 0; i <= back; i++) 
      data[i] = other.data[i];
  }

  return *this;
}

// << operator
ostream& operator<<(ostream& os, const Queue& queue) {
  os << "[ ";
  
  for (int i = 0; i <= queue.back; i++) {
    os << queue.data[i];
    
    if (i < queue.back)
      os << ", ";
  }
  
  os << " ]";

  return os;
}



// ================ VIRTUAL FUNCTIONS TO BE OVERWRITTEN ================

// implementation of push function, inserts element into the queue
void Queue::insert(int value) {
  if (this->isFull()) {
    cout << "QUEUE IS FULL! TO INSERT NEW ELEMENTS, PLEASE EXTEND THE CAPACITY!" << endl;
    return;
  }

  if (front == -1)
    front++;

  data[++back] = value;
}

// implementation of pop function, eliminates an element from the queue
int Queue::extract() {
  if (this->isEmpty()) {
    cout << "NO ELEMENTS IN THE QUEUE!" << endl;
    return -1;
  }
  
  int value = data[front];

  if (back == -1)
    front = -1;
  
  for(int i = 0; i < back; i++)
    data[i] = data[i + 1];

  back--;

  return value;
}

// function that displays the queue
void Queue::display() {
  cout << "Queue: ";

  for (int i = 0; i <= back; i++)
    cout << data[i] << " ";

  cout << endl;
}



// =============== OTHER STACK FUNCTIONS ================

// implementation of the front function, returns the top element of the queue
int Queue::frontElement() const {
  if (this->isEmpty()) {
    cout << "NO ELEMENTS IN THE QUEUE!" << endl;
    return -1;
  }
  
  return data[front];
}

int Queue::backElement() const {
  if (this->isEmpty()) {
    cout << "NO ELEMENTS IN THE QUEUE!" << endl;
    return -1;
  }
  
  return data[back];
}

// checks if the queue is empty (0 elements)
bool Queue::isEmpty() const {
  return back == -1;
}

// checks if the queue is full (top == capacity - 1)
bool Queue::isFull() const {
  return back == capacity - 1;
}

// returns the number of elements in the queue
int Queue::size() const {
  return back + 1;
}

// returns the capacity of the queue
int Queue::getCapacity() const {
  return capacity;
}

// extends the capacity twice
void Queue::extendCapacity() {
  if (capacity == 0)
    capacity = 2;
  else
    capacity = capacity * 2;
  
  int *newData = new int[capacity];

  for (int i = 0; i <= back; i++) 
    newData[i] = data[i];

  delete[] data;
  data = newData;
}