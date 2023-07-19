#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "action.h"

int main(void)
{
    char option;
    Bool isRuning = true;
    Bool isInitialized = false;
    // generate an array with dummy value,
    // just in can if not initialized
    int *numbers = calloc(0, sizeof(int));
    // size of number array;
    int numbers_size = 0;

    while (isRuning)
    {
        printf("Enter an option(from a-h only)\n-->");
        scanf(" %c", &option);
        //! isInitialized && (option != 'a')
        if (!isInitialized && (option != 'a'))
        {
            printf("****************** ERROR ****************\n");
            printf("array must be initialized first == (enter a) ==\n");
            printf("******************************************\n");
        }
        else
        {
            switch (option)
            {
            case 'a':
                int size;
                printf("Enter number of elements: ");
                scanf("%d", &size);
                numbers_size = size;
                int *tempArray = malloc(size * sizeof(int));

                printf("Enter the numbers: ");
                for (int i = 0; i < size; i++)
                {
                    scanf("%d", &tempArray[i]);
                }

                numbers = realloc(numbers, size * sizeof(int));
                if (numbers == NULL)
                {
                    // Handle memory allocation error
                    printf("Memory allocation failed!\n");
                    free(tempArray); // Free dynamically allocated memory
                    return 1;
                }

                // Copy values from tempArray to numbers
                for (int i = 0; i < size; i++)
                {
                    numbers[i] = tempArray[i];
                }

                free(tempArray); // delete the temporary array from the memory
                printf("Array initialized with %d and ends with %d\n", numbers[0], numbers[size - 1]);
                // set initialization to true
                isInitialized = true;
                break;
            case 'b':
                system("cls");
                // isRuning = false;
                print_elements(numbers, numbers_size);
                // isRuning = true;
                break;
            case 'c':
                system("cls");
                printf("the maximum element is %d\n", get_min_max(numbers, numbers_size, "max"));
                break;
            case 'd':
                system("cls");
                printf("the minum element is %d\n", get_min_max(numbers, numbers_size, "min"));
                break;
            case 'e':
                system("cls");
                printf("the sum of all numbers is %d\n", get_sum(numbers, numbers_size));
                break;
            case 'f':
                system("cls");
                printf("the average of elements is %.2f\n", get_average(numbers, numbers_size));
                break;
            case 'g':
                printf("Search : ");
                int search;
                scanf("%d", &search);
                search_element(numbers, numbers_size, search) ? printf("element %d exists in the array !\n", search) : printf("Oups!! ,element %d could not be founded\n", search);
                break;
            case 'h':
                printf("== quitting ==\n");
                isRuning = false;
                break;
            default:
                printf("you enter wrong option: Enter only letter from a to h (a-h)\n");
                break;
            }
        }
    }
    free(numbers);
}
