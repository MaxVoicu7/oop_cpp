#include "container.h"
#include "stack.h"
#include "queue.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
  Stack myStack;

  cout << "Inserting elements into the stack." << endl;
  myStack.insert(10);
  myStack.insert(20);
  myStack.insert(30);

  cout << "Current stack: " << myStack << endl;
  cout << "Top element: " << myStack.topElement() << endl;

  cout << "Removing top element: " << myStack.extract() << endl;
  cout << "After removal, stack: " << myStack << endl;
	cout << "Is stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << endl;

  cout << "Inserting additional elements." << endl;
  myStack.insert(40);
  myStack.insert(50);

  cout << "Current stack: " << myStack << endl;
	cout << "Stack size: " << myStack.size() << endl;

	cout << "Extending stack capacity." << endl;
	myStack.extendCapacity();
	cout << "Stack capacity: " << myStack.getCapacity() << endl;


	cout << endl << "==========================================" << endl << endl;


	Queue myQueue;

  cout << "Inserting elements into the queue." << endl;
  myQueue.insert(10);
  myQueue.insert(20);
  myQueue.insert(30);

  cout << "Current queue: " << myQueue << endl;
  cout << "Front element: " << myQueue.frontElement() << endl;
  cout << "Back element: " << myQueue.backElement() << endl;

  cout << "Removing front element: " << myQueue.extract() << endl;
  cout << "After removal, queue: " << myQueue << endl;
  cout << "Is queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << endl;

  cout << "Inserting additional elements." << endl;
  myQueue.insert(40);
  myQueue.insert(50);

  cout << "Current queue: " << myQueue << endl;
  cout << "Queue size: " << myQueue.size() << endl;

  cout << "Extending queue capacity." << endl;
  myQueue.extendCapacity();
  cout << "Queue capacity: " << myQueue.getCapacity() << endl;

	cout << endl << "==========================================" << endl << endl;




  Container* containers[2];
  containers[0] = new Stack();
  containers[1] = new Queue();

	cout << "Inserting elements into the stack." << endl;
	containers[0]->insert(10);
	containers[0]->insert(20);
	containers[0]->insert(30);
	containers[0]->insert(40);
	containers[0]->insert(50);

	cout << "Current ";
	containers[0]->display();
	cout << endl;

	cout << "Removing top element";
	containers[0]->extract();
	cout << endl;

	cout << "After removal, ";
	containers[0]->display();
	cout << endl;

	cout << "Removing top element";
	containers[0]->extract();
	cout << endl;

	cout << "After removal, ";
	containers[0]->display();
	cout << endl;

	cout << "Inserting elements into the queue." << endl;
  containers[1]->insert(10);
  containers[1]->insert(20);
  containers[1]->insert(30);
  containers[1]->insert(40);
  containers[1]->insert(50);

	cout << "Current ";
	containers[1]->display();
	cout << endl;

	cout << "Removing front element";
	containers[1]->extract();
	cout << endl;

	cout << "After removal, ";
	containers[1]->display();
	cout << endl;

	cout << "Removing front element";
	containers[1]->extract();
	cout << endl;

	cout << "After removal, ";
	containers[1]->display();
	cout << endl;

  return 0;
}