#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "action.h"

void display_options(void)
{
    // system("cls");
    printf("\n=========== menu ================\n");
    printf("a. initialize an array\n");
    printf("b. Print the array\n");
    printf("c. Find maximum element in the array\n");
    printf("d. Finf the minimum of all elements in the array\n");
    printf("e. calculate the sum of all elements in the array\n");
    printf("f. calculate the average of all elements in the array\n");
    printf("g. Search for a specific element in the Array\n");
    printf("h. exit the program\n");
}

// print array elements
void print_elements(int array[], int size)
{
    printf("elememts are: \n");
    for (int i = 0; i < size; i++)
    {
        printf(" %d |", array[i]);
    }
    printf("\n");
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int get_min_max(int arr[], int n, char type[])
{
    int i, j, min_idx;

    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element
        // with the first element
        swap(&arr[min_idx], &arr[i]);
    }

    return strcmp(type, "max") == 0 ? arr[n - 1] : arr[0];
}

int *init_array(int my_array[])
{
    int size;
    printf("enter the array size\n-->");
    scanf("%d", &size);
    // init the array
    int array[size];

    // ask user to enter array items
    printf("input the numbers :");
    int i = 0;
    do
    {
        scanf("%d", &array[i++]);
    } while (getchar() != '\n' && i > size);
    print_elements(array, size);
    // for (int i = 0; i < size; i++)
    // {
    //     // nadom value between 1-99
    //     int randomValue = (rand() % 99) + 1;
    //     array[i] = randomValue;
    //     my_array[i] = randomValue;
    // }
    return my_array;
}

int get_sum(int my_array[], int size)
{
    // int arr = my_array;
    // int size = sizeof my_array;
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += my_array[i];
    }
    return sum;
}

float get_average(int my_array[], int size)
{
    return (float)get_sum(my_array, size) / size;
}

// return tue if element exist false if not
// take the (array,array size,and element to search ) a argument
Bool search_element(int my_array[], int size, int element)
{
    for (int i = 0; i < size + 1; i++)
    {
        print_elements(my_array, size);
        return *(my_array + i) == element ? true : false;
    }
}