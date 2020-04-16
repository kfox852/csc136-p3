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
#include "Array.h"

using namespace std;

int main() {

    /*Array *list = new Array(2);
    *list += 5;
    *list += 10;*/

    Array *list = new Array(3);
    *list += 5;
    *list += 10;
    *list += 2;
    *list += 4;

    list->sort();


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
    cout << *list << endl;
    return(0);
}
