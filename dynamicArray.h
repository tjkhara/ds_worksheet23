//
// Created by Tajeshwar Khara on 2019-04-22.
//

#ifndef DS_WORKSHEET23_DYNAMICARRAY_H
#define DS_WORKSHEET23_DYNAMICARRAY_H

#ifndef __TYPE
#define __TYPE
# define TYPE int
# define TYPE_SIZE sizeof(int)
# endif

# ifndef LT
# define LT(A, B) ((A) < (B))
# endif

# ifndef EQ
# define EQ(A, B) ((A) == (B))
# endif

typedef struct DynArr DynArr;

typedef struct dynArrayIterator dynArrayIterator;

/* Dynamic Array Functions */
void initDynArr(DynArr *v, int capacity);
DynArr *newDynArr(int cap);

void freeDynArr(DynArr *v);
void deleteDynArr(DynArr *v);

int sizeDynArr(DynArr *v);

void addDynArr(DynArr *v, TYPE val);
TYPE getDynArr(DynArr *v, int pos);
void putDynArr(DynArr *v, int pos, TYPE val);
void swapDynArr(DynArr *v, int i, int  j);
void removeAtDynArr(DynArr *v, int idx);

/* Stack interface. */
int isEmptyDynArr(DynArr *v);
void pushDynArr(DynArr *v, TYPE val);
TYPE topDynArr(DynArr *v);
void popDynArr(DynArr *v);

/* Bag Interface */
/* Note addDynArr is already declared above*/
int containsDynArr(DynArr *v, TYPE val);
void removeDynArr(DynArr *v, TYPE val);

// Utility Function
void printDynArr(DynArr *v);

// Iterator functions
// Prototypes

// Initializes the iterator
void dynArrayIteratorInit (DynArr *da, struct dynArrayIterator *itr);

// Allocates memory for the iterator
dynArrayIterator* newDynArrItr(DynArr* da);

int dynArrayIteratorHasNext (struct dynArrayIterator *itr);


TYPE dynArrayIteratorNext (struct dynArrayIterator *itr);

TYPE currentIterValue(dynArrayIterator* itr);

void dynArrayIteratorRemove (struct dynArrayIterator *itr);

#endif //DS_WORKSHEET23_DYNAMICARRAY_H
