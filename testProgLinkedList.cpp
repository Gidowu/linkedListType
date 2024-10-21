// This program tests various operations of an unordered linked list
//34 62 21 90 66 53 88 24 10 -999

#include <iostream>                                 //Line 1
#include "unorderedLinkedList.h"                    //Line 2

using namespace std;                                //Line 3

int main() {                                        //Line 4
    unorderedLinkedList<int> list1, list2;          //Line 5
    int num;                                        //Line 6

    // Insert elements into list1
    cout << "Enter integers ending with -999: ";    //Line 7
    cin >> num;                                     //Line 8

    while (num != -999) {                           //Line 9
        list1.insertLast(num);                      //Line 10
        cin >> num;                                 //Line 11
    }                                               //Line 12

    // Print list1
    cout << "\nlist1: ";                            //Line 13
    list1.print();                                  //Line 14
    cout << "\nLength of list1: " << list1.length() << endl;  //Line 15

    // Test the assignment operator by assigning list1 to list2
    list2 = list1;                                  //Line 16

    cout << "\nlist2 (after assignment): ";         //Line 17
    list2.print();                                  //Line 18
    cout << "\nLength of list2: " << list2.length() << endl;  //Line 19

    // Test deleteNode
    cout << "\nEnter the number to be deleted from list2: ";  //Line 20
    cin >> num;                                     //Line 21
    list2.deleteNode(num);                          //Line 22
    cout << "\nAfter deleting " << num << " from list2: ";    //Line 23
    list2.print();                                  //Line 24
    cout << "\nLength of list2: " << list2.length() << endl;  //Line 25

    // Test deleteSmallest
    cout << "\nTesting deleteSmallest() on list2..." << endl;  //Line 26
    list2.deleteSmallest();                         //Line 27
    cout << "list2 after deleting the smallest element: ";     //Line 28
    list2.print();                                  //Line 29
    cout << "\nLength of list2: " << list2.length() << endl;   //Line 30

    // Test deleteAllOccurrences
    cout << "\nEnter a number to delete all occurrences from list2: ";  //Line 31
    cin >> num;                                     //Line 32
    list2.deleteAllOccurrences(num);                //Line 33
    cout << "\nlist2 after deleting all occurrences of " << num << ": ";  //Line 34
    list2.print();                                  //Line 35
    cout << "\nLength of list2: " << list2.length() << endl;   //Line 36

    // Test getKthElement
    cout << "\nEnter the position (k) of the element you want to retrieve from list2: ";  //Line 37
    int k;                                          //Line 38
    cin >> k;                                       //Line 39
    int kthElement = list2.getKthElement(k);        //Line 40
    if (kthElement != -1)                           //Line 41
        cout << "The " << k << "th element is: " << kthElement << endl;  //Line 42

    // Test deleteKthElement
    cout << "\nEnter the position (k) of the element you want to delete from list2: ";  //Line 43
    cin >> k;                                       //Line 44
    list2.deleteKthElement(k);                      //Line 45
    cout << "\nlist2 after deleting the " << k << "th element: ";  //Line 46
    list2.print();                                  //Line 47
    cout << "\nLength of list2: " << list2.length() << endl;   //Line 48

    // Test rotate
    cout << "\nTesting rotate() on list2..." << endl;  //Line 49
    list2.rotate();                                   //Line 50
    cout << "list2 after rotation: ";                 //Line 51
    list2.print();                                    //Line 52
    cout << "\nLength of list2: " << list2.length() << endl;   //Line 53

    // Output list1 using an iterator
    cout << "\nOutput list1 using an iterator: ";      //Line 54
    linkedListIterator<int> it;                        //Line 55

    for (it = list1.begin(); it != list1.end(); ++it)  //Line 56
        cout << *it << " ";                            //Line 57
    cout << endl;                                      //Line 58

    return 0;                                          //Line 59
}                                                      //Line 60
