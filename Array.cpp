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
#include "SortSearch.h"

using namespace std;

// Initialize static data member at file scope
int Array::arrayCount = 0;   // no objects yet


/***************************************************************************/
/*                                                                         */
/*  Constructor Name:  Default Constructor                                 */
/*  Description:       Default Array description                           */
/*  Parameters:        int arraySize: passed by value                      */
/*  Return Value:      none                                                */
/*                                                                         */
/***************************************************************************/
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

/***************************************************************************/
/*                                                                         */
/*  Constructor Name:   Copy Constructor                                   */
/*  Description:        Copies one array to another                        */
/*  Parameters:         const Array &init - passed by reference            */
/*  Return Value:       none                                               */
/*                                                                         */
/***************************************************************************/
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

/***************************************************************************/
/*                                                                         */
/*  Constructor Name:   Destructor                                         */
/*  Description:        Deletes an object                                  */
/*  Parameters:         none                                               */
/*  Return Value:       none                                               */
/*                                                                         */
/***************************************************************************/
// Destructor for class Array
Array::~Array()
{
    delete [] ptr;            // reclaim space for array
    --arrayCount;             // one fewer objects
}

/***************************************************************************/
/*                                                                         */
/*  Method:             setCapacity()                                      */
/*  Description:        sets Array's capacity                              */
/*  Parameters:         int elts - passed by value                         */
/*  Return Value:       void                                               */
/*                                                                         */
/***************************************************************************/
// Set the Array's size
void Array::setCapacity(int elts)
{ capacity=elts;
}

/***************************************************************************/
/*                                                                         */
/*  Method:             getCapacity()                                      */
/*  Description:        gets Array's capacity                              */
/*  Parameters:         none                                               */
/*  Return Value:       int                                                */
/*                                                                         */
/***************************************************************************/
// Get the size of the array
int Array::getCapacity() const
{ return capacity; }

/***************************************************************************/
/*                                                                         */
/*  Method:             getEltsInUse()                                     */
/*  Description:        gets the number of elements in the array           */
/*  Parameters:         nonw                                               */
/*  Return Value:       int                                                */
/*                                                                         */
/***************************************************************************/
// Get the elements in use
int Array::getEltsInUse() const
{return eltsInUse;}

/***************************************************************************/
/*                                                                         */
/*  Operator:           Overloaded assignment                              */
/*  Description:        This operator copies values from one array to      */
/*                      another. If they are different sized, it           */
/*                      de-allocates and re-sizes.                         */
/*  Parameters:         const Array &right - passed by reference           */
/*  Return Value:       void                                               */
/*                                                                         */
/***************************************************************************/
// Overloaded assignment operator
// const return avoids: ( a1 = a2 ) = a3
const Array &Array::operator=(const Array &right)
{
    if ( &right != this ) {  // check for self-assignment

        // for arrays of different sizes, deallocate original
        // left side array, then allocate new left side array.
        if ( getCapacity() != right.getCapacity() ) {
            delete [] ptr;         // reclaim space
            eltsInUse = right.getEltsInUse();
            setCapacity(right.getCapacity());     // resize this object
            ptr = new int[getCapacity()]; // create space for array copy
            assert( ptr != 0 );    // terminate if not allocated
        }

        for ( int i = 0; i < getCapacity(); i++ )
            ptr[ i ] = right[ i ];  // copy array into object
    }

    return *this;   // enables x = y = z;
}

/***************************************************************************/
/*                                                                         */
/*  Operator:           == operator                                        */
/*  Description:        This operator determines if two arrays are equal   */
/*  Parameters:         const Array &right - passed by reference           */
/*  Return Value:       bool                                               */
/*                                                                         */
/***************************************************************************/
// Determine if two arrays are equal and
// return true, otherwise return false.
bool Array::operator==(const Array &right) const
{
    if ( getCapacity() != right.getCapacity() )
        return false;    // arrays of different sizes

    if(getEltsInUse() != right.getEltsInUse())
        return false; //arrays have different number of elements

    for ( int i = 0; i < getEltsInUse(); i++ )
        if ( ptr[ i ] != right[ i ] )
            return false; // arrays are not equal

    return true;        // arrays are equal
}

/***************************************************************************/
/*                                                                         */
/*  Operator:           != operator                                        */
/*  Description:        This operator determines if two arrays are not     */
/*                      equal                                              */
/*  Parameters:         const Array &right - passed by reference           */
/*  Return Value:       bool                                               */
/*                                                                         */
/***************************************************************************/
// Determine if two arrays are not equal and
// return true, otherwise return false (uses operator==).
bool Array::operator!=(const Array &right) const
{  return ! ( *this == right ); }

/***************************************************************************/
/*                                                                         */
/*  Operator:           Overloaded Subscript for non-constant arrays       */
/*  Description:        This operator checks for an index value to make    */
/*                      sure it is not bigger than the array capacity      */
/*  Parameters:         int subscript - passed by value                    */
/*  Return Value:       int                                                */
/*                                                                         */
/***************************************************************************/
// Overloaded subscript operator for non-const Arrays
// reference return creates an lvalue
int &Array::operator[](int subscript)
{
    // check for subscript out of range error
    assert( 0 <= subscript && subscript < getCapacity() );

    return ptr[subscript]; // reference return
}

/***************************************************************************/
/*                                                                         */
/*  Operator:           Overloaded Subscript for constant arrays           */
/*  Description:        This operator checks for an index value to make    */
/*                      sure it is not bigger than the array capacity      */
/*  Parameters:         int subscript - passed by value                    */
/*  Return Value:       int                                                */
/*                                                                         */
/***************************************************************************/
// Overloaded subscript operator for const Arrays
// const reference return creates an rvalue
const int &Array::operator[](int subscript) const
{
    // check for subscript out of range error
    assert( 0 <= subscript && subscript < getCapacity() );

    return ptr[ subscript ]; // const reference return
}

/***************************************************************************/
/*                                                                         */
/*  Operator:           getArrayCount                                      */
/*  Description:        This operator keeps track of how many arrays have  */
/*                      been created                                       */
/*  Parameters:         none                                               */
/*  Return Value:       int arrayCount                                     */
/*                                                                         */
/***************************************************************************/
// Return the number of Array objects instantiated
// static functions cannot be const
int Array::getArrayCount() { return arrayCount; }

/***************************************************************************/
/*                                                                         */
/*  Operator:           += assignment()                                    */
/*  Description:        This operator is for appending an element onto the */
/*                      array. It checks if an index needs to be added to  */
/*                      the array or the element can go in an empty spot   */
/*                      in the array                                       */
/*  Parameters:         const int right - passed by value                  */
/*  Return Value:       Array                                              */
/*                                                                         */
/***************************************************************************/
// Overloaded += assignment operator
const Array &Array::operator+=( const int right ) {
    if (getEltsInUse() == getCapacity()) { //if elements in use is equal to capacity
        int *temp; //assign temporary
        temp = new int[getCapacity() + 1]; //create new array with one more element

        for (int i = 0; i < getCapacity(); i++) { //loop through to copy each element out of ptr
            temp[i] = ptr[i];
        }
        capacity++;
        ptr = temp; //array ptr now equals the temporary created array

    }
    ptr[getEltsInUse()] = right; //append element

    eltsInUse++; //increment eltsInUse

    return *this;   // enables x = y = z;
}

/***************************************************************************/
/*                                                                         */
/*  Function:           Sort()                                             */
/*  Description:        This funcion sorts the array from smallest integer */
/*                      to largest                                         */
/*  Parameters:         int subscript - passed by value                    */
/*  Return Value:       int                                                */
/*                                                                         */
/***************************************************************************/
//sort function
void Array::sort() {
    selSort <int> (ptr,eltsInUse);
}

/***************************************************************************/
/*                                                                         */
/*  Operator:           Overloaded output                                  */
/*  Description:        This operator outputs the array with formatting    */
/*  Parameters:         ostream &output - passed by reference, const Array */
/*                      &a - passed by reference                           */
/*  Return Value:       ostream                                            */
/*                                                                         */
/***************************************************************************/
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