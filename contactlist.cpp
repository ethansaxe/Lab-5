/*
LAB 5
CIS 22B

GROUP 1:
Maria Contreras: Person 1: Created Main Function
Zeth Tang: Person 2: Created Insert and Delete Functions
Ethan Saxe: Person 3: Created Constructor, Destructor, and Display

DATE: 3/12/21
*/
#include <stdio.h>
#include "Contact.h"
#include <iostream>
using namespace std;

void Node::display() {
    cout << data << endl;
}

void List::print() const { //Print using display function looping through all objects
    Node* currObj = head;
    while (currObj != nullptr) {
        currObj->display();
        currObj = currObj->next;
    }
}

List::~List() //Destructor for list
{
    while (head) {
       Node* next = head->next;
       delete head;
       head = next;
    }
}


void List::insert(const Contact value) {
    if (head == nullptr) {
        // List is empty.  Just set head to new node.
        head = new Node(value);
    } else {
        Node* prevNode = nullptr;
        for (Node* thisNode = head; thisNode != nullptr; thisNode = thisNode->next) {
            int lastNameCompareResult = thisNode->data.lastName.compare(value.lastName);
            if (lastNameCompareResult > 0) {
                // New node should be inserted before thisNode in list.
                Node* newNode = new Node(value);
                if (prevNode == nullptr) {
                    head = newNode;
                } else {
                    prevNode->next = newNode;
                }
                newNode->next = thisNode;
                break;
            }
             else if (lastNameCompareResult < 0) {
                if (thisNode->next == nullptr) {
                   // Insert new node at end of list.
                   thisNode->next = new Node(value);
                    break;
                }
             } else {
                // Last name of thisNode is the same as that of the node we're inserting.
                // Compare first names.
                int firstNameCompareResult = thisNode->data.firstName.compare(value.firstName);
                if (firstNameCompareResult > 0) {
                    // New node should be inserted before thisNode in list.
                    Node* newNode = new Node(value);
                    if (prevNode == nullptr) {
                        head = newNode;
                    } else {
                        prevNode->next = newNode;
                    }
                    newNode->next = thisNode;
                    break;
                 } else if (firstNameCompareResult < 0) {
                     // Insert new node at end of list.
                     if (thisNode->next == nullptr) {
                        thisNode->next = new Node(value);
                         break;
                     }
                 } else {
                    // First name and last name are both the same.
                    cout << "Error! The contact is already in the phone book." << endl;
                    break;
                 }
             }
             prevNode = thisNode;
         } // for...
      } // else ...
  }
         
  
void List::deleteContact(std::string name)
{
    string firstName,lastName;
    std::size_t pos=name.find(" ");
    if(pos < 0){
        cout << "Error: No last name" << endl;
        return;
    }
    firstName = name.substr(0,pos);
    lastName = name.substr(pos+1,std::string::npos);
    
    bool foundNode = false;
    Node* prevNode = nullptr;
    for (Node* thisNode = head; thisNode != nullptr; thisNode = thisNode->next) {
        if ((firstName == thisNode->data.firstName) && (lastName == thisNode->data.lastName)) {
            // thisNode is the node we want to remove.
            foundNode = true;
            if (prevNode == nullptr) {
                // We're removing the first element in the list.
                // Set list head to skip this element.
                head = thisNode->next;
            } else {
                // Set prevNode next to skip over thisNode.
                prevNode->next = thisNode->next;
            }
            delete thisNode;
            break;
        }
        prevNode = thisNode;
     }
     if (!foundNode) {
        cout << "Name not found in phone book." << endl;
     }
}


