#include "stack.h"

// ================= CONSTRUCTORS AND DESTRUCTOR =====================

// parameterized constructor
Stack::Stack(int capacity) : capacity{capacity}, top{-1} {
  data = new int[capacity];
}

Stack::Stack(int value1, int value2) : capacity{2}, top{1} {
  data = new int[capacity];
  data[0] = value1;
  data[1] = value2;
}

// copy constructor
Stack::Stack(const Stack &other) : capacity{other.capacity}, top{other.top} {
  data = new int[capacity];

  for (int i = 0; i <= top; i++) 
    data[i] = other.data[i];
}

// destructor 
Stack::~Stack() {
  delete [] data;
}



// ==================== OPERATORS =======================

// = operator
Stack& Stack::operator=(const Stack &other) {
  if (this != &other) {
    delete[] data;

    capacity = other.capacity;
    top = other.top;
    data = new int[capacity];

    for (int i = 0; i <= top; i++) 
      data[i] = other.data[i];
  }

  return *this;
}

// << operator
ostream& operator<<(ostream& os, const Stack& stack) {
  os << "[ ";
  
  for (int i = 0; i <= stack.top; i++) {
    os << stack.data[i];
    
    if (i < stack.top)
      os << ", ";
  }
  
  os << " ]";

  return os;
}



// ================ VIRTUAL FUNCTIONS TO BE OVERWRITTEN ================

// implementation of push function, inserts element into the stack
void Stack::insert(int value) {
  if (this->isFull()) {
    cout << "STACK IS FULL! TO INSERT NEW ELEMENTS, PLEASE EXTEND THE CAPACITY!" << endl;
    return;
  } else
    data[++top] = value;
}

// implementation of pop function, eliminates an element from the stack
int Stack::extract() {
  if (this->isEmpty()) {
    cout << "NO ELEMENTS IN THE STACK!" << endl;
    return -1;
  }
  
  return data[top--];
}

// function that displays the queue
void Stack::display() {
  cout << "Stack: ";

  for (int i = 0; i <= top; i++)
    cout << data[i] << " ";

  cout << endl;
}



// =============== OTHER STACK FUNCTIONS ================

// implementation of the top function, returns the top element of the stack
int Stack::topElement() const {
  if (this->isEmpty()) {
    cout << "NO ELEMENTS IN THE STACK!" << endl;
    return -1;
  }
  
  return data[top];
}

// checks if the stack is empty (0 elements)
bool Stack::isEmpty() const {
  return top == -1;
}

// checks if the stack is full (top == capacity - 1)
bool Stack::isFull() const {
  return top == capacity - 1;
}

// returns the number of elements in the stack
int Stack::size() const {
  return top + 1;
}

// returns the capacity of the stack
int Stack::getCapacity() const {
  return capacity;
}

// extends the capacity twice
void Stack::extendCapacity() {
  if (capacity == 0)
    capacity = 2;
  else
    capacity = capacity * 2;
  
  int *newData = new int[capacity];

  for (int i = 0; i <= top; i++) 
    newData[i] = data[i];

  delete[] data;
  data = newData;
}