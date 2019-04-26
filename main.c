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

    int count = 0;

    while(dynArrayIteratorHasNext(itr))
    {
        if(count == 1)
        {
            dynArrayIteratorRemove(itr);
        }

        printf("%d\n", dynArrayIteratorNext(itr));
        count++;
    }



    return 0;
}

