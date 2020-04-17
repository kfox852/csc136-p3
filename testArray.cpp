/***************************************************************************/
/*  Author:             Kelly Fox                                          */
/*  Major:              Information Technology                             */
/*  Creation Date:      April 10, 2020                                     */
/*  Due Date:           April 17, 2020                                     */
/*  Course:             CSC136                                             */
/*  Professor Name:     Dr. Spiegel                                        */
/*  Assignment:         #3                                                 */
/*  Filename:           testArray.cpp                                      */
/*  Purpose:            This file is for the purpose of testing Array.cpp  */
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Array.h"

using namespace std;

int main() {
    Array *list = new Array(2);

    // Add a value to the object
    int TestTerm=5;
    *list+=TestTerm;
    *list+=3;
    // Output the Array. There should be one value printed.
    cout << *list << endl;

    /*Array *list = new Array(2);
    *list += 5;
    *list += 10;*/




    // Getters and setters tested in various tests below
    // Don't need to test individually

    // Test constructor with no args and make sure capacity is 10
    Array *noArgTest = new Array();
    cout << "Capacity of noArgsTest should be 10: " << noArgTest->getCapacity() << endl;

    // Test constructor with arg and make sure capacity is correct
    Array *argTest = new Array(5);
    cout << "Capacity argTest should be 5: " << argTest->getCapacity() << endl;

    // Test copying an array
    Array *arrayOriginal = new Array(3);
    *arrayOriginal += 7;
    *arrayOriginal += 1;
    *arrayOriginal += 6;
    Array *arrayCopy = new Array(*arrayOriginal);
    //Dont forget to check for capacity and eltsInUse

    cout << "Array copy should be [7,1,6]: " << *arrayCopy << endl;

    //Test assignment of one array to another
    Array *arrayAssignmentOriginal = new Array(2);
    *arrayAssignmentOriginal += 4;
    *arrayAssignmentOriginal += 7;
    Array *arrayAssignment = new Array(3);
    *arrayAssignment = *arrayAssignmentOriginal;

    cout << "Array assignment from one array to another: " << *arrayAssignment << endl;

    // Test adding elements using overloaded +=
    Array *list2 = new Array(3);
    *list2 += 5;
    *list2 += 10;
    *list2 += 2;
    *list2 += 4;

    list2->sort();

    cout << "Test for adding elements using overloaded +=: " << *list2 <<endl;

    // Test array equality
    Array *lst1 = new Array(3);
    *lst1 += 5;
    *lst1 += 6;
    *lst1 += 6;
    Array *lst2 = new Array(3);
    *lst2 += 5;
    *lst2 += 6;
    *lst2 += 6;
    if (*lst1 == *lst2) {
        cout << "TPrint True" << endl;
    }


    // Test array inequality


    // Test retrieving an array item by subscript


    // Test sorting an array


    // Test that array counter is correct

}

    /*Array *list = new Array(3);
    *list += 5;
    *list += 10;
    *list += 2;
    *list += 7;
    *list += 8;*/

    // Add a value to the object
    //int TestTerm=5;
    //list+=TestTerm;

    // Output the Array. There should be one value printed.
    //cout << *list << endl;
    //return(0);
