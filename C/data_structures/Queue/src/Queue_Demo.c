#include <stdlib.h>
#include <stdio.h>

#include "Queue.h"

/**
 * @brief print_int function which is capable of printing the contents of a node with int data type
 *
 * The print_int function has as it's input the pointer to the int data being printed
 * It makes use of printf() with a dereference for int data.
 *
 * @p void * int_print
 *
 * Simple usage example
 * @code
 * print_list(print_int, queue_container_int);
 * @endcode
 *
 * Function is void, returning NULL
 * @note The print_list function will pass the int pointer to the int helper function
 */
void print_int(void *int_print)
{
    printf(" %d ", *(int*)int_print);
}

/**
 * @brief print_float function which is capable of printing the contents of a node with float data type
 *
 * The print_float function has as it's input the pointer to the float data being printed
 * It makes use of printf() with a dereference for float data.
 *
 * @p void * int_print
 *
 * Simple usage example
 * @code
 * print_list(print_float, queue_container_float);
 * @endcode
 *
 * Function is void, returning NULL
 * @note The print_list function will pass the float pointer to the int helper function
 */
void print_float(void *float_print)
{
    printf(" %f ", *(float *)float_print);
}

/* Helper function for same check integer data types
 *
 * The same_int function casts the void data passed it as int values. It then
 *  checks the two for equality. On a 0 the values are the same and anything else
 *  they are 1. This is to mimic the cmpstr functionality if a same_string function is desired.
 *
 * param int1: The first value in comparison, type casted to int
 * type int1: void *  
 * param int2: The second value in comparison, type casted to int
 * type int2: void * 
 * returns success: 0 if same or 1 not.
 * rtype success: int
 * rtype failure: int
 */
int same_int(void * int1, void* int2)
{
    if (*(int*)int1 == *(int*)int2)
    {
        return 0;
    }
    return 1;
}

int main()
{
    int * int_array = (int*)calloc(5, sizeof(int));
    if (int_array == NULL)
    {
        memory_error("int_array", "Demo main");
        return 1;
    }
    for (int init_arr = 0; init_arr < 4; init_arr ++)
    {
        int_array[init_arr] = (init_arr + 1) *5;
    }
    int_array[4] = 99;
    struct queue_container_node * queue_container_int = queue_container_init();
    if (queue_container_int == NULL)
    {
        memory_error("queue_container_int", "Demo main");
        free(int_array);
        return 1;
    }

    for (int i=3; i >= 0; i--)
    {
        push(&int_array[i], queue_container_int);
    }
    /**
     * The reverse order and then the late 99 are to demonstrate how the head is
     * moved and how the queue is maintaining First in First out.
     * The following series of pop() are to demonstrate the order in which the
     * nodes are removed.
     */
    push(&int_array[4], queue_container_int);

    printf("Queue list Ints \n");
    print_list(print_int, queue_container_int);

    remove_first_occurrence(same_int, queue_container_int, &int_array[2]); 
    printf("Queue list Ints with %d removed. \n", int_array[2]);
    print_list(print_int, queue_container_int);   

    view_nth_item(3, print_int, queue_container_int);

    while (queue_container_int->head != NULL )
    {
        pop(queue_container_int);
        printf("Popped first in. ");
        print_list(print_int, queue_container_int);
    }

    clean_container(queue_container_int);
    free(int_array);

    /**
     * This is to demonstrate the queue works with any data type.
     */
    float *float_array = (float*)calloc(4, sizeof(float));
    if (float_array == NULL)
    {
        memory_error("float_array", "Demo main");
        return 1;
    }

    for (int init_float = 0; init_float < 4; init_float++)
    {
        float_array[init_float] = init_float * 5.0;
    }
    struct queue_container_node * queue_container_float = queue_container_init();
    if (queue_container_float == NULL)
    {
        memory_error("queue_container_float", "Demo main");
        free(float_array);
        return 1;
    }

    for (int j=3; j>=0; j--)
    {
        push(&float_array[j], queue_container_float);
    }
    printf("\n Queue List Floats \n");
    print_list(print_float, queue_container_float);
    clean_container(queue_container_float);
    free(float_array);

    return 0;
}
