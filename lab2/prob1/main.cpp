#include <iostream>
#include <vector>
#include "queue.h"
#include "readData.h"

using std::cout;
using std::endl;

bool isQueueArrayEmpty(const std::vector<Queue> &queueArray, const std::string &message);
bool isValidSize(const int size, const int capacity);
int selectQueueFromArray(const std::vector<Queue> &queueArray);

int main() {
  std::vector<Queue> queueArray;
  int selectedMenuOption, selectedQueue, queueCapacity, queueSize, newElement;

  do {
    // displaying menu options
    cout << endl << " ===================== Menu =====================" << endl << endl;
    cout << "\t1.  Create queue using implicit constructor" << endl;
    cout << "\t2.  Create queue using parameterized constructor" << endl;
    cout << "\t3.  Create queue using copy constructor" << endl;
    cout << "\t4.  Display a queue" << endl;
    cout << "\t5.  Check if a queue is empty" << endl;
    cout << "\t6.  Check if a queue is full" << endl;
    cout << "\t7.  Extend the capacity of a queue" << endl;
    cout << "\t8.  Add an element to the queue" << endl;
    cout << "\t9.  Get an element from the queue" << endl;
    cout << "\t10. Leave program" << endl << endl;

    selectedMenuOption = readInt("Your choice: ");
    cout << endl << " ================================================" << endl << endl;

    switch (selectedMenuOption)
    {
      case 1: 
        // using the default constructor
        queueArray.push_back(Queue());
        break;

      case 2:
        // using the parameterized constructor
        queueCapacity = readPositiveInt("Enter the capacity of the queue: ");
        queueSize = readPositiveInt("Enter the size of the queue: ");

        // checking if the entered values are valid
        if (!isValidSize(queueSize, queueCapacity)) break;

        queueArray.push_back(Queue(queueSize, queueCapacity));
        break;

      case 3:
        // using the copy constructor by selecting a refference queue
        if (isQueueArrayEmpty(queueArray, "NO QUEUE REFFERENCES. ENTER A QUEUE BEFORE USING THE COPY CONSTRUCTOR")) break;
        selectedQueue = selectQueueFromArray(queueArray);

        queueArray.push_back(Queue(queueArray[selectedQueue]));
        break;

      case 4:
        // selecting a queue and displaying it
        if (isQueueArrayEmpty(queueArray, "NO QUEUE AVAILABLE. ENTER A QUEUE BEFORE TRYING TO DISPLAY")) break;
        selectedQueue = selectQueueFromArray(queueArray);

        queueArray[selectedQueue].displayQueue();
        break;

      case 5: 
        // selecting a queue and checkinf if it is empty
        if (isQueueArrayEmpty(queueArray, "NO QUEUE AVAILABLE. ENTER A QUEUE BEFORE CHECKING")) break;
        selectedQueue = selectQueueFromArray(queueArray);
        
        if (queueArray[selectedQueue].isEmpty()) 
          cout << endl << "The selected queue is empty" << endl;
        else
          cout << endl << "The queue has " << queueArray[selectedQueue].getSize() << " elements" << endl;

        break;

      case 6:
        // selecting a queue and checking if it is full
        if (isQueueArrayEmpty(queueArray, "NO QUEUE AVAILABLE. ENTER A QUEUE BEFORE CHECKING")) break;
        selectedQueue = selectQueueFromArray(queueArray);
        
        if (queueArray[selectedQueue].isFull()) 
          cout << endl << "The selected queue is full" << endl;
        else
          cout << endl << "The queue has " << queueArray[selectedQueue].getCapacity() - queueArray[selectedQueue].getSize() << " free elements" << endl;

        break;

      case 7:
        // selecting a queue and extending its capacity
        if (isQueueArrayEmpty(queueArray, "NO QUEUE AVAILABLE. ENTER A QUEUE BEFORE EXTENDING CAPACITY")) break;
        selectedQueue = selectQueueFromArray(queueArray);

        queueCapacity = readInt("Enter the new capacity of the queue: ");

        // checking that new capacity is larger than old capacity
        if (queueCapacity <= queueArray[selectedQueue].getCapacity()) {
          cout << endl << "NEW CAPACITY SHOULD BE LARGER THAN THE OLD CAPACITY" << endl;
          break;
        }

        queueArray[selectedQueue].extendCapacity(queueCapacity);
        break;

      case 8:
        // selecting a queue to enter a new element
        if (isQueueArrayEmpty(queueArray, "NO QUEUE AVAILABLE. CREATE A QUEUE BEFORE ENTERING ELEMENTS")) break;
        selectedQueue = selectQueueFromArray(queueArray);

        // it is checked if the queue has free space, if not, the element will not be added
        newElement = readInt("Enter the element to be added to the queue: ");
        queueArray[selectedQueue].addElement(newElement);
        break;

      case 9:
        // selecting a queue and removing an element from it
        if (isQueueArrayEmpty(queueArray, "NO QUEUE AVAILABLE. CREATE A QUEUE BEFORE GETTING ELEMENTS")) break;
        selectedQueue = selectQueueFromArray(queueArray);

        queueArray[selectedQueue].getElement();
        break;  

      case 10:
        break;

      default:
        cout << "WRONG OPTION ENTERED. TRY AGAIN" << endl;
    }
  } while (selectedMenuOption != 10);

  return 0;
}


// FUNCTION THAT RETURNS THE INDEX OF ONE QUEUE FROM THE AVAILABLE QUEUES FROM THE VECTOR
int selectQueueFromArray(const std::vector<Queue> &queueArray) {

  // the values are displayed from 1, so when we return, we return the value - 1
  cout << "Select one queue from the following:" << endl;
  for (int i = 0; i < queueArray.size(); i++) 
    std::cout << "\t" << i + 1 << ".  Queue nr. " << i + 1 << endl;

  cout << endl;

  int selectedQueue;

  // read index till the entered value is between borders
  do {
    selectedQueue = readPositiveInt("Enter the selected queue: ");
  } while (selectedQueue < 1 || selectedQueue > queueArray.size());

  return selectedQueue - 1;
}


// FUNCTION THAT RETURNS TRUE IF THE QUEUE VECTOR IS EMPTY AND FALSE IF NOT
bool isQueueArrayEmpty(const std::vector<Queue> &queueArray, const std::string &message) {
  if (queueArray.empty()) {
    cout << message << endl;
    return 1;
  }

  return 0;
}

// FUNCTION THAT RETURNS TRUE IF SIZE <= CAPACITY AND FALSE OTHERWISE
bool isValidSize(const int size, const int capacity) {
  if (size > capacity) {
    cout << endl << "CAPACITY OF THE QUEUE SHOULD BE BIGGER OR EQUAL TO SIZE OF THE QUEUE" << endl;
    return 0;
  }

  return 1;
}