#include <iostream>
#include "group.h"

using std::cin;
using std::cout;
using std::endl;

void printStudentDetails(const Student &student, const std::string &description) {
  cout << "\nDetails of " << description << ":" << endl;
  cout << student << endl;
}

int main() {
  
  // Test Student class functionality
  Student student1;
  printStudentDetails(student1, "student1 (implicit constructor)");

  cout << "Enter details for student1:" << endl;
  cin >> student1;
  printStudentDetails(student1, "student1");

  Student student2("Valeriu Garbuz", "Tehnologii Informationale", 2, 8.3);
  printStudentDetails(student2, "student2 (parametrized constructor)");

  Student student3 = student2; // Copy constructor test
  printStudentDetails(student3, "student3 (copy of student2)");

  student3.setName("Eduard Velcev");
  student3.setStudyYear(1);
  printStudentDetails(student3, "student3 (modified)");

  Student studentA("Grigore Vieru", "Informatica Aplicata", 2, 6.5);
  Student studentB("Mihai Eminescu", "Managmentul Informatiei", 2, 9.2);
  printStudentDetails(studentA, "studentA");
  printStudentDetails(studentB, "studentB");

  cout << "\nTesting comparison operators:" << endl;
  cout << "Are studentA and studentB equal? " << (studentA == studentB ? "Yes" : "No") << endl;
  cout << "Are studentA and studentB not equal? " << (studentA != studentB ? "Yes" : "No") << endl;
  cout << "Is studentA less than studentB? " << (studentA < studentB ? "Yes" : "No") << endl;
  cout << "Is studentA greater than studentB? " << (studentA > studentB ? "Yes" : "No") << endl;
  cout << "Is studentA less than or equal to studentB? " << (studentA <= studentB ? "Yes" : "No") << endl;
  cout << "Is studentA greater than or equal to studentB? " << (studentA >= studentB ? "Yes" : "No") << endl;


  // Test Group class functionality
  Student student11("Ion Creanga", "FAF", 1, 6.5);
  Student student12("Veronica Micle", "FAF", 1, 9.2);
  Student student13("Mihail Drumes", "FAF", 1, 7.8);

  Group group;
  group.setName("FAF-101");

  group.addStudent(&student11);
  group.addStudent(&student12);
  cout << "\nGroup details after adding two students:" << endl;
  cout << group;

  group.addStudent(&student13);
  cout << "\nGroup details after adding third student:" << endl;
  cout << group;

  cout << "Average Grade of Group: " << group.getAvgGrade() << endl;

  group.deleteStudent(&student12);
  group.deleteStudent(&student11);
  cout << "\nGroup details after removing two students:" << endl;
  cout << group;

  return 0;
}
