/***************************************************************************/
/*  Author:             Kelly Fox                                          */
/*  Major:              Information Technology                             */
/*  Creation Date:      April 10, 2020                                     */
/*  Due Date:           April 17, 2020                                     */
/*  Course:             CSC136                                             */
/*  Professor Name:     Dr. Spiegel                                        */
/*  Assignment:         #3                                                 */
/*  Filename:           Array.cpp                                          */
/*  Purpose:            This program update the Array class to be able     */
/*                      to handle partially-filled arrays.                 */
/***************************************************************************/

// File: Array.cpp
// Member function definitions for class Array
#include <iostream>
#include <iomanip>
#include <assert.h>
#include "Array.h"

using namespace std;

// Initialize static data member at file scope
int Array::arrayCount = 0;   // no objects yet

// Default constructor for class Array (default size 10)
Array::Array(int arraySize)
{
    setCapacity(( arraySize > 0 ? arraySize : 10 ));
    ptr = new int[getCapacity()]; // create space for array
    assert( ptr != 0 );    // terminate if memory not allocated
    ++arrayCount;          // count one more object

    for ( int i = 0; i < getCapacity(); i++ )
        ptr[ i ] = 0;          // initialize array
}

// Copy constructor for class Array
// must receive a reference to prevent infinite recursion
Array::Array(const Array &init)
{  setCapacity(init.getCapacity());
   eltsInUse = init.getEltsInUse(); //copy eltsInUse from the original array to the new array
    ptr = new int[getCapacity()]; // create space for array
    assert( ptr != 0 );    // terminate if memory not allocated
    ++arrayCount;          // count one more object

    for ( int i = 0; i < getEltsInUse(); i++ )
        ptr[ i ] = init.ptr[ i ];  // copy init into object
}

// Destructor for class Array
Array::~Array()
{
    delete [] ptr;            // reclaim space for array
    --arrayCount;             // one fewer objects
}

// Set the Array's size
void Array::setCapacity(int elts)
{ capacity=elts;
}

// Get the size of the array
int Array::getCapacity() const
{ return capacity; }

// Get the elements in use
int Array::getEltsInUse() const
{return eltsInUse;}

// Overloaded assignment operator
// const return avoids: ( a1 = a2 ) = a3
const Array &Array::operator=(const Array &right)
{
    if ( &right != this ) {  // check for self-assignment

        // for arrays of different sizes, deallocate original
        // left side array, then allocate new left side array.
        if ( getCapacity() != right.getCapacity() ) {
            delete [] ptr;         // reclaim space
            setCapacity(right.getCapacity());     // resize this object
            ptr = new int[getCapacity()]; // create space for array copy
            assert( ptr != 0 );    // terminate if not allocated
        }

        for ( int i = 0; i < getCapacity(); i++ )
            ptr[ i ] = right[ i ];  // copy array into object
    }

    return *this;   // enables x = y = z;
}

// Determine if two arrays are equal and
// return true, otherwise return false.
bool Array::operator==(const Array &right) const
{
    if ( getCapacity() != right.getCapacity() )
        return false;    // arrays of different sizes

    for ( int i = 0; i < getCapacity(); i++ )
        if ( ptr[ i ] != right[ i ] )
            return false; // arrays are not equal

    return true;        // arrays are equal
}

// Determine if two arrays are not equal and
// return true, otherwise return false (uses operator==).
bool Array::operator!=(const Array &right) const
{  return ! ( *this == right ); }

// Overloaded subscript operator for non-const Arrays
// reference return creates an lvalue
int &Array::operator[](int subscript)
{
    // check for subscript out of range error
    assert( 0 <= subscript && subscript < getCapacity() );

    return ptr[subscript]; // reference return
}

// Overloaded subscript operator for const Arrays
// const reference return creates an rvalue
const int &Array::operator[](int subscript) const
{
    // check for subscript out of range error
    assert( 0 <= subscript && subscript < getCapacity() );

    return ptr[ subscript ]; // const reference return
}

// Return the number of Array objects instantiated
// static functions cannot be const
int Array::getArrayCount() { return arrayCount; }


// Overloaded += assignment operator
const Array &Array::operator+=( const int right ) {

    if (getEltsInUse() == getCapacity()) {
        int *temp;
        temp = new int[getCapacity() + 1];

        for (int i = 0; i < getCapacity(); i++) {}
            temp[i] = ptr[i];
            ptr = temp;
    }
        //return *this;
    if (ptr[eltsInUse] == right) {
        eltsInUse++;
    }

    return *this;   // enables x = y = z;
}

// Overloaded output operator for class Array
ostream &operator<<(ostream &output, const Array &a) {
    int i;
    output << '\t';
    for (i = 0; i < a.getEltsInUse(); i++) {
        output << setw(12) << a[i];

        if ((i + 1) % 4 == 0) // 4 numbers per row of output
            output << endl;
    }

    if (i % 4 != 0)
        output << endl;

    return output;   // enables cout << x << y;

}
