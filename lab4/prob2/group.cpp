#include "group.h"

// ========== constructors and destructor ============

// default constructor
Group::Group() : students{nullptr}, nrStudents{}, name{nullptr} {}

// parameterized constructor
Group::Group(const Student** studentsValue, int nrStudentsValue, const char* nameValue)
  : nrStudents(nrStudentsValue), students(nullptr), name(nullptr) {

    if (studentsValue != nullptr && nrStudentsValue > 0) {
      students = new Student*[nrStudentsValue];

      for (int i = 0; i < nrStudentsValue; ++i) 
        students[i] = const_cast<Student*>(studentsValue[i]);
    }

    setName(nameValue);
}

// copy constructor
Group::Group(const Group& other) : nrStudents(other.nrStudents), students(nullptr), name(nullptr) {
  if (other.nrStudents > 0 && other.students != nullptr) {
    students = new Student*[other.nrStudents];

    for (int i = 0; i < other.nrStudents; ++i) 
      students[i] = other.students[i];
        
  }

  setName(other.name);
}

// destructor
Group::~Group() {
  delete[] students;
  delete[] name;
}



// ================ setters ==================

void Group::setName(const char* nameValue) {
  if (name != nullptr) 
    delete[] name;

  if (nameValue != nullptr) {
    name = new char[strlen(nameValue) + 1];
    strcpy(name, nameValue);
  } else 
    name = nullptr;
}



// =============== member functions ================

// add a student to group
void Group::addStudent(const Student* newStudent) {
  if (newStudent == nullptr) return;
    
  Student** newStudents = new Student*[nrStudents + 1];

  for (int i = 0; i < nrStudents; ++i) 
    newStudents[i] = students[i];

  newStudents[nrStudents] = const_cast<Student*>(newStudent);

  delete[] students;
  students = newStudents;
  nrStudents++;
}

// delete a student from group
void Group::deleteStudent(const Student* deletedStudent) {
  if (deletedStudent == nullptr) return;
    
  int deleteIndex = -1;
    
  for (int i = 0; i < nrStudents; ++i) 
    if (students[i] == deletedStudent) {
      deleteIndex = i;
      break;
    }

  if (deleteIndex == -1) return;

  Student** newStudents = new Student*[nrStudents - 1];
  
  for (int i = 0, j = 0; i < nrStudents; ++i) 
    if (i != deleteIndex) 
      newStudents[j++] = students[i];

  delete[] students;
  students = newStudents;
  nrStudents--;
}

// calculates the average grade in group
float Group::getAvgGrade() const {
  if (nrStudents == 0) return 0.0;
    

  float sum = 0.0;
    
  for (int i = 0; i < nrStudents; ++i) 
    if (students[i] != nullptr) 
      sum += students[i]->getAvgGrade();

  return sum / nrStudents;
}



// ====================== friend functions ================

// << overload
std::ostream& operator<<(std::ostream& os, const Group& group) {
  os << "Group Name: " << (group.name ? group.name : "N/A") << endl;
  os << "Number of Students: " << group.nrStudents << endl;
  os << "Students:" << endl;

  for (int i = 0; i < group.nrStudents; ++i) 
    if (group.students[i] != nullptr) 
      os << *group.students[i] << endl;

  return os;
}