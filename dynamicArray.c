/* CS261- Assignment 2*/
/* Name: Tajeshwar Singh Khara
 * Date: April 13th 2019
 * Solution description:
 * Dynamic array implementation and dynamic array based stack and bag.
 */

/*	dynamicArray.c: Dynamic Array implementation. */
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "dynamicArray.h"

struct DynArr
{
	TYPE *data;		/* pointer to the data array */
	int size;		/* Number of elements in the array */
	int capacity;	/* capacity of the array */
};

struct dynArrayIterator {
    DynArr * da;
    int currentIndex;
};


/* ************************************************************************
	Dynamic Array Functions
************************************************************************ */

/* Initialize (including allocation of data array) dynamic array.

	param: 	v		pointer to the dynamic array
	param:	cap 	capacity of the dynamic array
	pre:	v is not null
	post:	internal data array can hold cap elements
	post:	v->data is not null
*/
void initDynArr(DynArr *v, int capacity)
{
	assert(capacity > 0);
	assert(v!= 0);
	v->data = (TYPE *) malloc(sizeof(TYPE) * capacity);
	assert(v->data != 0);
	v->size = 0;
	v->capacity = capacity;	
}

/* Allocate and initialize dynamic array.

	param:	cap 	desired capacity for the dyn array
	pre:	none
	post:	none
	ret:	a non-null pointer to a dynArr of cap capacity
			and 0 elements in it.		
*/
DynArr* newDynArr(int cap)
{
	assert(cap > 0);
	DynArr *r = (DynArr *)malloc(sizeof( DynArr));
	assert(r != 0);
	initDynArr(r,cap);
	return r;
}

/* Deallocate data array in dynamic array. 

	param: 	v		pointer to the dynamic array
	pre:	none
	post:	d.data points to null
	post:	size and capacity are 0
	post:	the memory used by v->data is freed
*/
void freeDynArr(DynArr *v)
{
	if(v->data != 0)
	{
		free(v->data); 	/* free the space on the heap */
		v->data = 0;   	/* make it point to null */
	}
	v->size = 0;
	v->capacity = 0;
}

/* Deallocate data array and the dynamic array ure. 

	param: 	v		pointer to the dynamic array
	pre:	none
	post:	the memory used by v->data is freed
	post:	the memory used by d is freed
*/
void deleteDynArr(DynArr *v)
{
	freeDynArr(v);
	free(v);
}

/* Resizes the underlying array to be the size cap 

	param: 	v		pointer to the dynamic array
	param:	cap		the new desired capacity
	pre:	v is not null
	post:	v has capacity newCap
*/
void _dynArrSetCapacity(DynArr *v, int newCap)
{	
	/* FIXME: You will write this function */

	// Set capacity to newCap
	v->capacity = newCap;

	// Create new array
	TYPE* newArr = malloc(sizeof(TYPE) * newCap);

	// Check if it was created properly
    assert(newArr != 0);

    // Copy old values into the new array
    int i;

    for(i = 0; i < v->size; i++)
    {
        newArr[i] = v->data[i];
    }

    // Deallocate memory of old array
    free(v->data);

    // Change pointer to reference new array
    v->data = newArr;
	
}

/* Get the size of the dynamic array

	param: 	v		pointer to the dynamic array
	pre:	v is not null
	post:	none
	ret:	the size of the dynamic array
*/
int sizeDynArr(DynArr *v)
{
	return v->size;
}

/* 	Adds an element to the end of the dynamic array

	param: 	v		pointer to the dynamic array
	param:	val		the value to add to the end of the dynamic array
	pre:	the dynArry is not null
	post:	size increases by 1
	pre:	if reached capacity, capacity is doubled
	post:	val is in the last utilized position in the array
*/
void addDynArr(DynArr *v, TYPE val)
{
	/* FIXME: You will write this function */

	// Check to see if resize is necessary
	if(v->size >= v->capacity)
    {
	    _dynArrSetCapacity(v, 2*v->capacity);
    }

	// Add element
	v->data[v->size] = val;

	// Increase size by 1
	v->size++;

}

/*	Get an element from the dynamic array from a specified position
	
	param: 	v		pointer to the dynamic array
	param:	pos		integer index to get the element from
	pre:	v is not null
	pre:	v is not empty
	pre:	pos < size of the dyn array and >= 0
	post:	no changes to the dyn Array
	ret:	value stored at index pos
*/

TYPE getDynArr(DynArr *v, int pos)
{
	/* FIXME: You will write this function */

	// Check to see if pos is legal from 0 to size - 1
	assert(pos >= 0 && pos < v->size);

	/* FIXME: you must change this return value */
	return v->data[pos];
}

/*	Put an item into the dynamic array at the specified location,
	overwriting the element that was there

	param: 	v		pointer to the dynamic array
	param:	pos		the index to put the value into
	param:	val		the value to insert 
	pre:	v is not null
	pre:	v is not empty
	pre:	pos >= 0 and pos < size of the array
	post:	index pos contains new value, val
*/
void putDynArr(DynArr *v, int pos, TYPE val)
{
	/* FIXME: You will write this function */
    // Check to see if pos is legal from 0 to size - 1
    assert(pos >= 0 && pos < v->size);

    // Add the element to that position
    v->data[pos] = val;
}

/*	Swap two specified elements in the dynamic array

	param: 	v		pointer to the dynamic array
	param:	i,j		the elements to be swapped
	pre:	v is not null
	pre:	v is not empty
	pre:	i, j >= 0 and i,j < size of the dynamic array
	post:	index i now holds the value at j and index j now holds the value at i
*/
void swapDynArr(DynArr *v, int i, int  j)
{
	/* FIXME: You will write this function */
    // Check to see if pos is legal from 0 to size - 1
    assert(i >= 0 && i < v->size);
    assert(j >= 0 && j < v->size);

    // create temp variable for swap
    int temp;

    // Store value of i in temp
    temp = v->data[i];

    // Store value of j in i
    v->data[i] = v->data[j];

    // Store value of temp in j
    v->data[j] = temp;
}

/*	Remove the element at the specified location from the array,
	shifts other elements back one to fill the gap

	param: 	v		pointer to the dynamic array
	param:	idx		location of element to remove
	pre:	v is not null
	pre:	v is not empty
	pre:	idx < size and idx >= 0
	post:	the element at idx is removed
	post:	the elements past idx are moved back one
*/
void removeAtDynArr(DynArr *v, int idx)
{
	/* FIXME: You will write this function */

	int i;

	// Starting at index idx shifting everything to the right to the left
	// by one spot
	for(i = idx; i < v->size; i++)
    {
	    v->data[i] = v->data[i+1];
    }

	// Make the vacated space the null character
	v->data[v->size-1] = '\0';

	// Decrease the size by 1
	v->size--;
}



/* ************************************************************************
	Stack Interface Functions
************************************************************************ */

/*	Returns boolean (encoded in an int) demonstrating whether or not the 
	dynamic array stack has an item on it.

	param:	v		pointer to the dynamic array
	pre:	the dynArr is not null
	post:	none
	ret:	1 if empty, otherwise 0
*/
int isEmptyDynArr(DynArr *v)
{
	/* FIXME: You will write this function */
	if(v->size == 0)
    {
	    return 1;
    }
	else
    {
	    return 0;
    }
	
	/* FIXME:  You will change this return value*/

}

/* 	Push an element onto the top of the stack

	param:	v		pointer to the dynamic array
	param:	val		the value to push onto the stack
	pre:	v is not null
	post:	size increases by 1
			if reached capacity, capacity is doubled
			val is on the top of the stack
*/
void pushDynArr(DynArr *v, TYPE val)
{
	/* FIXME: You will write this function */
    addDynArr(v, val);
}

/*	Returns the element at the top of the stack 

	param:	v		pointer to the dynamic array
	pre:	v is not null
	pre:	v is not empty
	post:	no changes to the stack
*/
TYPE topDynArr(DynArr *v)
{
	/* FIXME: You will write this function */
	
	/* FIXME: You will change this return value*/
	return v->data[v->size - 1];
}

/* Removes the element on top of the stack 

	param:	v		pointer to the dynamic array
	pre:	v is not null
	pre:	v is not empty
	post:	size is decremented by 1
			the top has been removed
*/
void popDynArr(DynArr *v)
{
	/* FIXME: You will write this function */
	v->size--;
}

/* ************************************************************************
	Bag Interface Functions
************************************************************************ */

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0

	param:	v		pointer to the dynamic array
	param:	val		the value to look for in the bag
	pre:	v is not null
	pre:	v is not empty
	post:	no changes to the bag
*/
int containsDynArr(DynArr *v, TYPE val)
{
	/* FIXME: You will write this function */
	
	/* FIXME:  You will change this return value */

	// Iterate through the array
	int i;

	for(i = 0; i < v->size; i++)
    {
	    if(v->data[i] == val)
        {
	        return 1;
        }
    }

	return 0;

}

/*	Removes the first occurrence of the specified value from the collection
	if it occurs

	param:	v		pointer to the dynamic array
	param:	val		the value to remove from the array
	pre:	v is not null
	pre:	v is not empty
	post:	val has been removed
	post:	size of the bag is reduced by 1
*/
void removeDynArr(DynArr *v, TYPE val)
{
	/* FIXME: You will write this function */

	// Find at which position the first element occurs

	int position = -1;

	int i;

	for(i=0; i < v->size; i++)
    {
	    if(v->data[i] == val)
        {
	        position = i;
	        break;
        }
    }

	if(position != -1) // If the element has been found
    {
	    removeAtDynArr(v, position);
    }
}

// Utility Function
void printDynArr(DynArr* v)
{
    // Iterate through the array
    int i;

    for(i = 0; i < v->size; i++)
    {
        printf(" %d \n", v->data[i]);
    }
}

// Iterator functions

// Initializes the iterator
void dynArrayIteratorInit (DynArr *da, dynArrayIterator *itr)
{

    // Point the da pointer in the iterator to the structure pointer sent in
    itr->da = da;

    // Set current index to 0
    itr->currentIndex = 0;
}

// Allocates memory for the iterator
dynArrayIterator* newDynArrItr(DynArr* da)
{
    dynArrayIterator* itr = (dynArrayIterator*)malloc(sizeof(dynArrayIterator));
    assert(itr != 0);
    dynArrayIteratorInit(da, itr);
    return itr;
}

// Return 1 if it has next
// Return 0 if it does not
int dynArrayIteratorHasNext (dynArrayIterator *itr)
{
    if(itr->currentIndex < (itr->da->size))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Returns the value of the current index
// Moves the index forward
TYPE dynArrayIteratorNext (dynArrayIterator *itr)
{
    int currIndex = itr->currentIndex;
    itr->currentIndex++;
    return itr->da->data[currIndex];
}

// Returns value in the array at current index of iterator
TYPE currentIterValue(dynArrayIterator* itr)
{
    return itr->da->data[itr->currentIndex];
}


// Removes the value at the current index
void dynArrayIteratorRemove (dynArrayIterator *itr)
{
//    itr->currentIndex--;
    removeAtDynArr(itr->da, itr->currentIndex);
}
