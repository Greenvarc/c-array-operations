#ifndef __ACTIONS_H__
#define __ACTIONS_H__

typedef enum Bool
{
    false,
    true,
} Bool;

void display_options(void);
void print_elements(int array[], int size);
int get_min_max(int arr[], int n, char type[]);
void swap(int *xp, int *yp);
int *sort(int arr[], int n);
int *init_array(int my_array[]);
int get_sum(int my_array[], int size);
Bool search_element(int my_array[], int size, int element);
float get_average(int my_array[], int size);

#endif