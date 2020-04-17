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
/***************************************************************************/
/*                                                                         */
/*  Constructor Name:  Default Constructor                                 */
/*  Description:       Default Array description                           */
/*  Parameters:        int arraySize: passed by value                      */
/*  Return Value:      none                                                */
/*                                                                         */
/***************************************************************************/
    Array(int arraySize= 10);              // default constructor

/***************************************************************************/
/*                                                                         */
/*  Constructor Name:   Copy Constructor                                   */
/*  Description:        Copies one array to another                        */
/*  Parameters:         const Array &init - passed by reference            */
/*  Return Value:       none                                               */
/*                                                                         */
/***************************************************************************/
    Array(const Array &init);              // copy constructor

/***************************************************************************/
/*                                                                         */
/*  Constructor Name:   Destructor                                         */
/*  Description:        Deletes an object                                  */
/*  Parameters:         none                                               */
/*  Return Value:       none                                               */
/*                                                                         */
/***************************************************************************/
    ~Array();                              // destructor

    // Functions updated to use term 'capacity' to better describe use
/***************************************************************************/
/*                                                                         */
/*  Method:             setCapacity()                                      */
/*  Description:        sets Array's capacity                              */
/*  Parameters:         int elts - passed by value                         */
/*  Return Value:       void                                               */
/*                                                                         */
/***************************************************************************/
    void setCapacity(int);		    // set the capacity

/***************************************************************************/
/*                                                                         */
/*  Method:             getCapacity()                                      */
/*  Description:        gets Array's capacity                              */
/*  Parameters:         none                                               */
/*  Return Value:       int                                                */
/*                                                                         */
/***************************************************************************/
    int getCapacity() const;                 // return capacity

/***************************************************************************/
/*                                                                         */
/*  Method:             getEltsInUse()                                     */
/*  Description:        gets the number of elements in the array           */
/*  Parameters:         nonw                                               */
/*  Return Value:       int                                                */
/*                                                                         */
/***************************************************************************/
    int getEltsInUse() const; //Function to get the elements in use

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
    const Array &operator=(const Array & ); // assign arrays

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
    const Array &operator+=(const int); // append array

/***************************************************************************/
/*                                                                         */
/*  Operator:           == operator                                        */
/*  Description:        This operator determines if two arrays are equal   */
/*  Parameters:         const Array &right - passed by reference           */
/*  Return Value:       bool                                               */
/*                                                                         */
/***************************************************************************/
    bool operator==( const Array & ) const;  // compare equal

/***************************************************************************/
/*                                                                         */
/*  Operator:           != operator                                        */
/*  Description:        This operator determines if two arrays are not     */
/*                      equal                                              */
/*  Parameters:         const Array &right - passed by reference           */
/*  Return Value:       bool                                               */
/*                                                                         */
/***************************************************************************/
    bool operator!=(const Array &right) const;   // Determine if two arrays are not equal

/***************************************************************************/
/*                                                                         */
/*  Operator:           Overloaded Subscript for non-constant arrays       */
/*  Description:        This operator checks for an index value to make    */
/*                      sure it is not bigger than the array capacity      */
/*  Parameters:         int subscript - passed by value                    */
/*  Return Value:       int                                                */
/*                                                                         */
/***************************************************************************/
    int &operator[](int);              // l-value subscript operator

/***************************************************************************/
/*                                                                         */
/*  Operator:           Overloaded Subscript for constant arrays           */
/*  Description:        This operator checks for an index value to make    */
/*                      sure it is not bigger than the array capacity      */
/*  Parameters:         int subscript - passed by value                    */
/*  Return Value:       int                                                */
/*                                                                         */
/***************************************************************************/
    const int &operator[](int) const;  // r-value subscript operator

/***************************************************************************/
/*                                                                         */
/*  Operator:           getArrayCount                                      */
/*  Description:        This operator keeps track of how many arrays have  */
/*                      been created                                       */
/*  Parameters:         none                                               */
/*  Return Value:       int arrayCount                                     */
/*                                                                         */
/***************************************************************************/
    static int getArrayCount();          // Return count of arrays instantiated.

/***************************************************************************/
/*                                                                         */
/*  Function:           Sort()                                             */
/*  Description:        This funcion sorts the array from smallest integer */
/*                      to largest                                         */
/*  Parameters:         int subscript - passed by value                    */
/*  Return Value:       int                                                */
/*                                                                         */
/***************************************************************************/
    void sort(); //sort function

private:
    int capacity, 		// capacity of the array
            numElts;  		// Elements in the array in use
    int *ptr;     		// pointer to first element of array
    static int arrayCount;  	// # of Arrays instantiated

    int eltsInUse; // how many elements are in use in the array
};

/***************************************************************************/
/*                                                                         */
/*  Operator:           Overloaded output                                  */
/*  Description:        This operator outputs the array with formatting    */
/*  Parameters:         ostream &output - passed by reference, const Array */
/*                      &a - passed by reference                           */
/*  Return Value:       ostream                                            */
/*                                                                         */
/***************************************************************************/
ostream &operator<<(ostream &output, const Array &a); //outstream operator

#endif
