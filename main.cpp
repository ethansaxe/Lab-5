/*
 LAB 5
 CIS 22B
 
 GROUP 1:
 Maria Contreras: Person 1: Created Main Function
 Zeth Tang: Person 2: Created Insert and Delete Functions
 Ethan Saxe: Person 3: Created Constructor, Destructor, and Display
 
 DATE: 3/12/21
 */

#include <iostream>

#include <cstddef>

#include "Contact.h"

using namespace std;
int main() {
  string firstName;
  string lastName;
  string tel;
  List phoneBook;
  while (true) {
    // Ask the user if they want to exit, display, insert, or remove a contact
    // Do it here
      cout << "Do you want to 1: Exit, 2: Display, 3: Insert, or 4: Remove contact?" << endl;

    // create a string variable called choice and cin >> choice

    int choice;

    cin >> choice;

    // Do if statements to check if it is 1,2,3, or 4

    if (choice == 1) {

      return 0;

    } else if (choice == 2) {

      phoneBook.print();

    } else if (choice == 3) {

      Contact temp;

      cout << "Please enter First Name: ";

      cin >> temp.firstName;

      cout << "Please enter Last Name: ";

      cin >> temp.lastName;

      cout << "Please enter phone number: ";

      cin >> temp.tel;

      // Right here

      phoneBook.insert(temp);

    } else if (choice == 4) {

  string name1;
  string name2;
  cout << "Enter the first name you want to delete: ";
  cin >> name1;
  cout << "Enter the last name you want to delete: ";
  cin >> name2;
  phoneBook.deleteContact(name1 + " " + name2);
    }
  }
}

/*
 OUTPUT:
 Do you want to 1: Exit, 2: Display, 3: Insert, or 4: Remove contact?
 3
 Please enter First Name: Ethan
 Please enter Last Name: Saxe
 Please enter phone number: 4083864433
 Do you want to 1: Exit, 2: Display, 3: Insert, or 4: Remove contact?
 2
 Ethan    Saxe    4083864433
 Do you want to 1: Exit, 2: Display, 3: Insert, or 4: Remove contact?
 3
 Please enter First Name: John
 Please enter Last Name: Doe
 Please enter phone number: 4087765432
 Do you want to 1: Exit, 2: Display, 3: Insert, or 4: Remove contact?
 2
 John    Doe    4087765432
 Ethan    Saxe    4083864433
 Do you want to 1: Exit, 2: Display, 3: Insert, or 4: Remove contact?
 3
 Please enter First Name: Zeth
 Please enter Last Name: Tang
 Please enter phone number: 4089873211
 Do you want to 1: Exit, 2: Display, 3: Insert, or 4: Remove contact?
 2
 John    Doe    4087765432
 Ethan    Saxe    4083864433
 Zeth    Tang    4089873211
 Do you want to 1: Exit, 2: Display, 3: Insert, or 4: Remove contact?
 4
 Enter the first name you want to delete: Zeth
 Enter the last name you want to delete: Tang
 Do you want to 1: Exit, 2: Display, 3: Insert, or 4: Remove contact?
 2
 John    Doe    4087765432
 Ethan    Saxe    4083864433
 Do you want to 1: Exit, 2: Display, 3: Insert, or 4: Remove contact?
 4
 Enter the first name you want to delete: John
 Enter the last name you want to delete: Doe
 Do you want to 1: Exit, 2: Display, 3: Insert, or 4: Remove contact?
 2
 Ethan    Saxe    4083864433
 Do you want to 1: Exit, 2: Display, 3: Insert, or 4: Remove contact?
 4
 Enter the first name you want to delete: Ethan
 Enter the last name you want to delete: Saxe
 Do you want to 1: Exit, 2: Display, 3: Insert, or 4: Remove contact?
 2
 Do you want to 1: Exit, 2: Display, 3: Insert, or 4: Remove contact?
 1
 Program ended with exit code: 0
 */
