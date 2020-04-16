/***************************************************************
Author:
Assignment:     #3
Filename:       tst.cpp

Other stuff

Purpose:
***************************************************************/

#include <iostream>
#include "Array.h"

using namespace std;

int main() {

    /*Array *list = new Array(2);
    *list += 5;
    *list += 10;*/

    Array *list = new Array(5);
    *list += 5;
    *list += 10;
    *list += 2;


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
