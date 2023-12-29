#include <iostream>
#include <vector>
#include "bool.h"

using std::cout;
using std::endl;
using std::vector;
using std::string;

int readInt(const std::string &message);
int readPositiveInt(const std::string &message);

bool isBoolArrayEmpty(const vector<Bool> &boolArray);
int selectBoolVarFromArray(const vector<Bool> &boolArray);
int getBoolForUsage(const vector<Bool> &boolArray, const string &message);

int main() {
  vector<Bool> boolArray;
  int selectedMenuOption, exitOption = 14;

  do {
    // displaying menu options
    cout << endl << " ===================== Menu =====================" << endl << endl;
    cout << "\t1.  Create a false boolean object" << endl;
    cout << "\t2.  Create a true boolean object" << endl;
    cout << "\t3.  Display a bool object" << endl;
    cout << "\t4.  OR operation between two bool objects" << endl;
    cout << "\t5.  OR operation between an int and a bool object" << endl;
    cout << "\t6.  AND operation between two bool objects" << endl;
    cout << "\t7.  AND operation between an int and a bool object" << endl;
    cout << "\t8.  XOR operation between two bool objects" << endl;
    cout << "\t9.  XOR operation between an int and a bool object" << endl;
    cout << "\t10. == operation between two bool objects" << endl;
    cout << "\t11. == operation between an int and a bool object" << endl;
    cout << "\t12. != operation between two bool objects" << endl;
    cout << "\t13. != operation between an int and a bool object" << endl;
    cout << "\t14. Exit" << endl << endl;

    selectedMenuOption = readInt("Your choice: ");
    cout << endl << " ================================================" << endl << endl;

    switch (selectedMenuOption) {
      case 1:
        // using the default constructor
        boolArray.emplace_back();
        break;

      case 2:
        // using the parameterized constructor
        boolArray.emplace_back(true);
        break;

      case 3: {
        // selecting a bool and displaying it
        int selectedBool = getBoolForUsage(boolArray, "CREATE A BOOL OBJECT BEFORE TRYING TO DISPLAY ONE");
        if (selectedBool == -1) break;

        boolArray[selectedBool].displayValue();
        break;
      }

      case 4: {
        // selecting two bools and performing the or operation
        int firstBool = getBoolForUsage(boolArray, "CREATE A BOOL OBJECT BEFORE TRYING TO PERFORM OR");
        if (firstBool == -1) break;

        int secondBool = getBoolForUsage(boolArray, "CREATE A BOOL OBJECT BEFORE TRYING TO PERFORM OR");
        if (secondBool == -1) break;

        boolArray.emplace_back(boolArray[firstBool] + boolArray[secondBool]);
        cout << std::boolalpha;
        cout << boolArray[firstBool].getValue() << " || " << boolArray[secondBool].getValue() << " = " << boolArray[boolArray.size() - 1].getValue();
        cout << endl;
        break;
      }

      case 5: {
        // selecting a bool and reading an int to perform a bool oepration
        int firstBool = getBoolForUsage(boolArray, "CREATE A BOOL OBJECT BEFORE TRYING TO PERFORM OR");
        if (firstBool == -1) break;

        int intValue = readInt("Enter the integer value for OR operation: ");
        cout << endl;

        boolArray.emplace_back(boolArray[firstBool] + intValue);
        cout << std::boolalpha;
        cout << boolArray[firstBool].getValue() << " || " << intValue << " = " << boolArray[boolArray.size() - 1].getValue();
        cout << endl;
        break;
      }

      case 6: {
        // selecting two bools to perform and operation
        int firstBool = getBoolForUsage(boolArray, "CREATE A BOOL OBJECT BEFORE TRYING TO PERFORM AND");
        if (firstBool == -1) break;

        int secondBool = getBoolForUsage(boolArray, "CREATE A BOOL OBJECT BEFORE TRYING TO PERFORM AND");
        if (secondBool == -1) break;

        boolArray.emplace_back(boolArray[firstBool] * boolArray[secondBool]);
        cout << std::boolalpha;
        cout << boolArray[firstBool].getValue() << " && " << boolArray[secondBool].getValue() << " = " << boolArray[boolArray.size() - 1].getValue();
        cout << endl;
        break;
      }

      case 7: {
        // selecting a bool and an int to perform and operation
        int firstBool = getBoolForUsage(boolArray, "CREATE A BOOL OBJECT BEFORE TRYING TO PERFORM AND");
        if (firstBool == -1) break;

        int intValue = readInt("Enter the integer value for AND operation: ");
        cout << endl;

        boolArray.emplace_back(boolArray[firstBool] * intValue);
        cout << std::boolalpha;
        cout << boolArray[firstBool].getValue() << " && " << intValue << " = " << boolArray[boolArray.size() - 1].getValue();
        cout << endl;
        break;
      }

      case 8: {
        // selecting two bools to perform xor operation
        int firstBool = getBoolForUsage(boolArray, "CREATE A BOOL OBJECT BEFORE TRYING TO PERFORM XOR");
        if (firstBool == -1) break;

        int secondBool = getBoolForUsage(boolArray, "CREATE A BOOL OBJECT BEFORE TRYING TO PERFORM XOR");
        if (secondBool == -1) break;

        boolArray.emplace_back(boolArray[firstBool] ^ boolArray[secondBool]);
        cout << std::boolalpha;
        cout << boolArray[firstBool].getValue() << " ^ " << boolArray[secondBool].getValue() << " = " << boolArray[boolArray.size() - 1].getValue();
        cout << endl;
        break;
      }

      case 9: {
        // selecting a bool and an int to perform xor operation
        int firstBool = getBoolForUsage(boolArray, "CREATE A BOOL OBJECT BEFORE TRYING TO PERFORM XOR");
        if (firstBool == -1) break;

        int intValue = readInt("Enter the integer value for XOR operation: ");
        cout << endl;

        boolArray.emplace_back(boolArray[firstBool] ^ intValue);
        cout << std::boolalpha;
        cout << boolArray[firstBool].getValue() << " ^ " << intValue << " = " << boolArray[boolArray.size() - 1].getValue();
        cout << endl;
        break;
      }

      case 10: {
        // selectiong two bools to perform ==
        int firstBool = getBoolForUsage(boolArray, "CREATE A BOOL OBJECT BEFORE TRYING TO PERFORM ==");
        if (firstBool == -1) break;

        int secondBool = getBoolForUsage(boolArray, "CREATE A BOOL OBJECT BEFORE TRYING TO PERFORM ==");
        if (secondBool == -1) break;

        boolArray.emplace_back(boolArray[firstBool] == boolArray[secondBool]);
        cout << std::boolalpha;
        cout << boolArray[firstBool].getValue() << " == " << boolArray[secondBool].getValue() << endl;
        boolArray[boolArray.size() - 1].displayValue();
        cout << endl;
        break;
      }

      case 11: {
        // selecting a bool and an int to perform ==
        int firstBool = getBoolForUsage(boolArray, "CREATE A BOOL OBJECT BEFORE TRYING TO PERFORM ==");
        if (firstBool == -1) break;

        int intValue = readInt("Enter the integer value for == comparison: ");
        cout << endl;

        boolArray.emplace_back(boolArray[firstBool] == intValue);
        cout << std::boolalpha;
        cout << boolArray[firstBool].getValue() << " == " << intValue << endl;
        boolArray[boolArray.size() - 1].displayValue();
        cout << endl;
        break;
      }

      case 12: {
        // selecting two ools to perform !=
        int firstBool = getBoolForUsage(boolArray, "CREATE A BOOL OBJECT BEFORE TRYING TO PERFORM !=");
        if (firstBool == -1) break;

        int secondBool = getBoolForUsage(boolArray, "CREATE A BOOL OBJECT BEFORE TRYING TO PERFORM !=");
        if (secondBool == -1) break;

        boolArray.emplace_back(boolArray[firstBool] != boolArray[secondBool]);
        cout << std::boolalpha;
        cout << boolArray[firstBool].getValue() << " != " << boolArray[secondBool].getValue() << endl;
        boolArray[boolArray.size() - 1].displayValue();
        cout << endl;
        break;
      }

      case 13: {
        // selecting a bool and an int to perform !=
        int firstBool = getBoolForUsage(boolArray, "CREATE A BOOL OBJECT BEFORE TRYING TO PERFORM !=");
        if (firstBool == -1) break;

        int intValue = readInt("Enter the integer value for != comparison: ");
        cout << endl;

        boolArray.emplace_back(boolArray[firstBool] != intValue);
        cout << std::boolalpha;
        cout << boolArray[firstBool].getValue() << " != " << intValue << endl;
        boolArray[boolArray.size() - 1].displayValue();
        cout << endl;
        break;
      }

      case 14:
        break;

      default:
        cout << "ENTER AN AVAILABLE MENU OPTION" << endl;
        break;
    }

  } while (selectedMenuOption != exitOption);



  return 0;
}



// FUNCTION THAT DISPLAYS THE MESSAGE SENT AS PARAMETER, READS A SINGLE INT AND RETURNS IT
int readInt(const string &message) {
  int value;
  std::cout << message;
  std::cin >> value;

  return value;
}


// FUNCTION THAT READS AND RETURNS A POSITIVE INTEGER
int readPositiveInt(const std::string &message) {
  int value;

  do {
    std::cout << message;
    std::cin >> value;

    if (value < 0)
      std::cout << "Value should be positive" << std::endl;
  } while(value < 0);

  return value;
}



// checking it the matrix array is empty
bool isBoolArrayEmpty(const vector<Bool> &boolArray) {
  return boolArray.empty();
}



// selecting a matrix from the array and returning the index
int selectBoolVarFromArray(const vector<Bool> &boolArray) {
  // the values are displayed from 1, array is indexed from 0
  cout << "Select one bool object from the following:" << endl;
  for (int i = 0; i < boolArray.size(); i++)
    std::cout << "\t" << i + 1 << ".  Bool " << i + 1 << endl;

  cout << endl;

  int selectedBool;

  // read index till the entered value is between borders 1 and array.size
  do {
    selectedBool = readPositiveInt("Enter the selected bool obj: ");
  } while (selectedBool < 1 || selectedBool > boolArray.size());

  cout << endl;

  // return the value - 1, because the options were displayed indexed from 1
  return selectedBool - 1;
}



// if no matrices in array, -1 returned, else the index of matrix is returned
int getBoolForUsage(const vector<Bool> &boolArray, const string &message) {
  if (isBoolArrayEmpty(boolArray)) {
    cout << message << endl;
    return -1;
  }

  return selectBoolVarFromArray(boolArray);
}