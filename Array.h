/***************************************************************************/
/*  Author:             Kelly Fox                                          */
/*  Major:              Information Technology                             */
/*  Creation Date:      April 10, 2020                                     */
/*  Due Date:           April 17, 2020                                     */
/*  Course:             CSC136                                             */
/*  Professor Name:     Dr. Spiegel                                        */
/*  Assignment:         #3                                                 */
/*  Filename:           Array.h                                            */
/*  Purpose:            This is the header file for Array.cpp              */
/***************************************************************************/

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

using namespace std;

class Array {

public:
    Array(int arraySize= 10);              // default constructor
    Array(const Array &init);              // copy constructor
    ~Array();                              // destructor

    // Functions updated to use term 'capacity' to better describe use
    void setCapacity(int);		    // set the capacity
    int getCapacity() const;                 // return capacity

    int getEltsInUse() const; //Function to get the elements in use

    const Array &operator=(const Array & ); // assign arrays
    const Array &operator+=(const int); // append array
    bool operator==( const Array & ) const;  // compare equal
    bool operator!=(const Array &right) const;   // Determine if two arrays are not equal

    int &operator[](int);              // l-value subscript operator
    const int &operator[](int) const;  // r-value subscript operator
    static int getArrayCount();          // Return count of arrays instantiated.

    void sort(); //sort function

private:
    int capacity, 		// capacity of the array
            numElts;  		// Elements in the array in use
    int *ptr;     		// pointer to first element of array
    static int arrayCount;  	// # of Arrays instantiated

    int eltsInUse; // how many elements are in use in the array
};


ostream &operator<<(ostream &output, const Array &a); //outstream operator

#endif
