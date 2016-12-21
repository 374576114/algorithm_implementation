/*
 * quickly sort algorithm
 */

#include <stdio.h>

/*
 * swap two elements
 */
void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void print_array(int array[], int len)
{
    int i;

    for(i=0; i<len; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

/*
 * partition, return the middle index
 */
int partition(int array[], int low, int high)
{
    int pivot = array[low];
    int i = low + 1;
    int j = high;

    // make sure the array[low, high] is valid
    while(i<=j){
        // decrease j, and find an element less than pivot
        while(array[j]>pivot && j>=i) j--;

        // increase i, and find an element greater than pivot
        while(array[i]<pivot && i<=j) i++;
        if( j>i ){
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[low], &array[j]);

    return j;
}

void qsort_recursive(int array[], int low, int high)
{
    int middle;

    // the array[low, high] is valid
    if(low < high){
        middle = partition(array, low, high);
        qsort_recursive(array, low, middle-1);
        qsort_recursive(array, middle+1, high);
    }
}

void qsort_loop(int array[], int low, int high)
{
    int middle;
    // I need a stack to save the low, high and middle
    // 
    // 1.every loop is just getting an element from stack
    //  if the low and the high is vaild, then partition
    //  if the low and the high is invaild, do nothing
    // 2.after partition, we will get two new coples of
    //  low and high, just put them into the stack
    // 3.when the stack is empty, then loop is over,
    //  and the array is sorted well too
    //
    // NOTE: because the implementation of stack in C is too
    //  simple and it is not important for this coding,
    //  so I don't implement this non-recursive qsort

}

int main()
{
    //int arr[5] = {1,2,3,4,5};
    int arr[5] = {4,1,2,3,5};
    print_array(arr, 5);
    //partition(arr, 0, 4);
    qsort_recursive(arr, 0, 4);
    print_array(arr, 5);

    return 0;
}


