#include <stdio.h>
#include "dynamicArray.h"



int main()
{

    DynArr *dyn;
    dyn = newDynArr(2);

    dynArrayIterator* itr;
    itr = newDynArrItr(dyn);

    // Add values to the array
    addDynArr(dyn, 10);
    addDynArr(dyn, 20);
    addDynArr(dyn, 30);
    addDynArr(dyn, 40);
    addDynArr(dyn, 50);

    int value;

    while(dynArrayIteratorHasNext(itr))
    {

        if(currentIterValue(itr) == 30)
        {
            dynArrayIteratorRemove(itr);
        }

        printf(" %d \n", dynArrayIteratorNext(itr));

    }



    return 0;
}

