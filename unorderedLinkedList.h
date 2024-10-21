#ifndef H_UnorderedLinkedList
#define H_UnorderedLinkedList

//***********************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement the basic
// properties of an unordered linked list. This class is
// derived from the class linkedListType.
//***********************************************************

#include "linkedList.h"

using namespace std;

template <class Type>
class unorderedLinkedList: public linkedListType<int>
{
public:
    bool search(const Type& searchItem) const;
      //Function to determine whether searchItem is in the list.
      //Postcondition: Returns true if searchItem is in the list,
      //    otherwise the value false is returned.

    void insertFirst(const Type& newItem);
      //Function to insert newItem at the beginning of the list.
      //Postcondition: first points to the new list, newItem is
      //    inserted at the beginning of the list, last points to
      //    the last node, and count is incremented by 1.

    void insertLast(const Type& newItem);
      //Function to insert newItem at the end of the list.
      //Postcondition: first points to the new list, newItem is
      //    inserted at the end of the list, last points to the
      //    last node, and count is incremented by 1.

    void deleteNode(const Type& deleteItem);
      //Function to delete deleteItem from the list.
      //Postcondition: If found, the node containing deleteItem
      //    is deleted from the list. first points to the first
      //    node, last points to the last node of the updated
      //    list, and count is decremented by 1.

    // New functions added for lab requirements
    void deleteSmallest();
      //Function to find and delete the node with the smallest value.
      //Postcondition: The smallest node is deleted from the list.

    void deleteAllOccurrences(int value);
      //Function to delete all occurrences of the given value.
      //Postcondition: All nodes with the value are deleted.

    int getKthElement(int k);
      //Function to return the info of the kth element of the linked list.
      //Postcondition: Returns the value of the kth element.

    void deleteKthElement(int k);
      //Function to delete the kth element of the linked list.
      //Postcondition: The kth element is deleted if it exists.

    void rotate();
      //Function to rotate the list: remove the first node and move it to the end.
      //Postcondition: The first node is moved to the end of the list.
};

// Existing member function implementations

template <class Type>
bool unorderedLinkedList<Type>::search(const Type& searchItem) const
{
    nodeType<Type> *current; //pointer to traverse the list
    bool found = false;

    current = first; //set current to point to the first
                     //node in the list

    while (current != nullptr && !found)    //search the list
        if (current->info == searchItem) //searchItem is found
            found = true;
        else
            current = current->link; //make current point to
                                     //the next node
    return found;
}//end search

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    nodeType<Type> *newNode; //pointer to create the new node

    newNode = new nodeType<Type>; //create the new node

    newNode->info = newItem;    //store the new item in the node
    newNode->link = first;      //insert newNode before first
    first = newNode;            //make first point to the
                                //actual first node
    count++;                    //increment count

    if (last == nullptr)   //if the list was empty, newNode is also
                           //the last node in the list
        last = newNode;
}//end insertFirst

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
    nodeType<Type> *newNode; //pointer to create the new node

    newNode = new nodeType<Type>; //create the new node

    newNode->info = newItem;  //store the new item in the node
    newNode->link = nullptr;  //set the link field of newNode to nullptr

    if (first == nullptr)  //if the list is empty, newNode is
                           //both the first and last node
    {
        first = newNode;
        last = newNode;
        count++;        //increment count
    }
    else    //the list is not empty, insert newNode after last
    {
        last->link = newNode; //insert newNode after last
        last = newNode; //make last point to the actual
                        //last node in the list
        count++;        //increment count
    }
}//end insertLast

template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    bool found;

    if (first == nullptr)    //Case 1: the list is empty
        cout << "Cannot delete from an empty list."
             << endl;
    else
    {
        if (first->info == deleteItem) //Case 2: the node to be deleted is the first node
        {
            current = first;
            first = first->link;
            count--;
            if (first == nullptr)    //the list has only one node
                last = nullptr;
            delete current;
        }
        else //search the list for the node with the given info
        {
            found = false;
            trailCurrent = first;  //set trailCurrent to point to the first node
            current = first->link; //set current to point to the second node

            while (current != nullptr && !found)
            {
                if (current->info != deleteItem)
                {
                    trailCurrent = current;
                    current = current->link;
                }
                else
                    found = true;
            }//end while

            if (found) //Case 3: if found, delete the node
            {
                trailCurrent->link = current->link;
                count--;

                if (last == current)   //node to be deleted was the last node
                    last = trailCurrent; //update the value of last
                delete current;  //delete the node from the list
            }
            else
                cout << "The item to be deleted is not in the list." << endl;
        }//end else
    }//end else
}//end deleteNode

// Add the new function implementations

// Function to find and delete the node with the smallest value
template <class Type>
void unorderedLinkedList<Type>::deleteSmallest() {
    if (first == nullptr) {  // Empty list case
        cout << "The list is empty. No element to delete." << endl;
        return;
    }

    nodeType<Type> *current = first;
    nodeType<Type> *smallest = first;
    nodeType<Type> *prev = nullptr;  // Track previous node of current
    nodeType<Type> *smallestPrev = nullptr;  // Track previous node of smallest

    // Traverse the list to find the smallest node
    while (current != nullptr) {
        if (current->info < smallest->info) {  // Update smallest node and its previous pointer
            smallest = current;
            smallestPrev = prev;
        }
        prev = current;
        current = current->link;
    }

    // Now delete the smallest node
    if (smallest == first) {  // Special case: smallest node is the first node
        first = first->link;  // Update the first pointer to the next node
        if (first == nullptr) {  // If the list becomes empty after deletion
            last = nullptr;  // Update last to nullptr (empty list case)
        }
    } else {  // Smallest node is somewhere in the middle or end
        smallestPrev->link = smallest->link;  // Bypass the smallest node
        if (smallest == last) {  // If smallest node is the last one
            last = smallestPrev;  // Update the last pointer
        }
    }

    delete smallest;
    count--;  // Decrease the node count

    // If the list is empty after deletion, ensure count is set to 0
    if (first == nullptr) {
        count = 0;
    }
}


template <class Type>
void unorderedLinkedList<Type>::deleteAllOccurrences(int value) {
    nodeType<Type> *current = first;
    nodeType<Type> *prev = nullptr;

    while (current != nullptr) {
        if (current->info == value) {
            if (prev == nullptr) {
                // If the first node is being deleted
                first = current->link;
            } else {
                prev->link = current->link;
            }
            // Check if the deleted node was the last node
            if (current == last) {
                last = prev;
            }
            nodeType<Type> *temp = current;
            current = current->link;
            delete temp;
            count--;  // Decrease the count of nodes
        } else {
            prev = current;
            current = current->link;
        }
    }

    // If the list is empty after deletion, set count to 0
    if (first == nullptr) {
        last = nullptr;
        count = 0;
    }
}




// Function to return the kth element
template <class Type>
int unorderedLinkedList<Type>::getKthElement(int k) {
    nodeType<Type> *current = first;
    int count = 1;

    while (current != nullptr && count < k) {
        current = current->link;
        count++;
    }

    if (current == nullptr) {
        cout << "Element out of bounds!" << endl;
        return -1;  // Return -1 if out of bounds
    }

    return current->info;
}

// Function to delete the kth element
template <class Type>
void unorderedLinkedList<Type>::deleteKthElement(int k) {
    if (first == nullptr) return;  // Empty list case

    nodeType<Type> *current = first;
    nodeType<Type> *prev = nullptr;
    int countPos = 1;  // Start position at 1

    while (current != nullptr && countPos < k) {
        prev = current;
        current = current->link;
        countPos++;
    }

    if (current == nullptr) {
        cout << "Element out of bounds!" << endl;
        return;
    }

    // Deleting the first node
    if (prev == nullptr) {
        first = current->link;
    } else {
        prev->link = current->link;
    }

    // If the node being deleted is the last one, update the last pointer
    if (current == last) {
        last = prev;
    }

    delete current;
    count--;  // Decrease the count of nodes

    // If the list is now empty, set count to 0
    if (first == nullptr) {
        last = nullptr;
        count = 0;
    }
}


// Function to rotate the list (move the first node to the end)
template <class Type>
void unorderedLinkedList<Type>::rotate() {
    if (first == nullptr || first->link == nullptr) return;  // Empty list or single element case

    nodeType<Type> *current = first;
    nodeType<Type> *newFirst = first->link;

    while (current->link != nullptr) {
        current = current->link;
    }

    current->link = first;  // Move the first node to the end
    first->link = nullptr;  // Unlink the old first node
    first = newFirst;
}

#endif
