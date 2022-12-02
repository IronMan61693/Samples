/**
 * @file Queue.h
 * @author Dominic Pontious
 * @date 10 Jan 2022
 * @brief Header file containing Queue structs and queue prototype functions.
 *
 * Header contains two structs, queue_node is the struct used for the actual
 * data and pointers within the queue, and the queue_container_node maintains the
 * length of the queue and head, tail pointers.
 * Expected queue functionality is prototyped in the header as well
 * This includes: an init for the container, push, pop, clean (delete),
 * and prints. The print_list accepts a print function pointer, currently
 * implemented are print_int and print_float but we can do any data type.
 */

 #ifndef QUEUE_H_
 #define QUEUE_H_

/**
 * @brief struct queue_node has two members, a void pointer to the data and struct pointer to next_node
 *
 */

struct queue_node
{
    void * data;                /**< Void pointer to the location where the data is in the heap */
    struct queue_node* next_node; /**< The pointer to the next node in the queue. */
};

  /**
   * @brief struct queue_container_node has three members, a struct pointer to the head of the queue, one to the tail and the length.
   *
   */

struct queue_container_node
{
    struct queue_node * head;  /**< The head pointer to the first node in the queue. */
    struct queue_node * tail;  /**< The tail pointer to the final node in the queue. */
    int queue_length;
};


  /**
   * @brief Initialization function for the queue_container
   *
   * The init function allocates memory for the queue_container, sets the queue_length
   * to 0, and sets the head and tail pointers to NULL. It returns a pointer to the container
   *
   * @p no parameters
   *
   * Usage example
   * @code
   * struct queue_container_node * queue_containerInt = queue_container_init();
   * @endcode
   * Function is struct queue_container_node pointer, returning this pointer
   * @warning This function allocates memory and copies the data to the heap
   * ensure you make use of free from one of the provided functions
   */
struct queue_container_node * queue_container_init();


/**
 * @brief Push function which creates a node, points to the data, and moves the tail
 *
 * The push functions uses a pointer to the data being added to the queue, 
 * and a struct pointer to the queue container, then adds the new node which points to the now copied data
 * to the tail of the queue, which is contained in the queue_container which we
 * passed a pointer to. This functionality makes it a First in First out which
 * is the definition of a queue.
 *
 * @p void * node_data, @p struct queue_container_node* queue_container
 *
 * Simple usage example
 * @code
 * push(&intArray[i], queue_containerInt);
 * @endcode
 *
 * Function is void, returning NULL
 * @warning This function allocates memory 
 * ensure you make use of free from one of the provided functions
 */
void push(void* node_data, struct queue_container_node *queue_container);

/**
 * @brief pop function which removes the last element from the queue
 *
 * The pop function has as it's input the pointer to the queue_container.
 * It navigates to the head node, which if not NULL is free'd and passes the
 * head pointer to the next node in the queue. This ensures proper heap memory cleaning
 * and maintains the properties of a queue.
 *
 * @p struct queue_container_node* queue_container
 *
 * Simple usage example
 * @code
 * pop(queue_containerInt);
 * @endcode
 *
 * Function is void, returning NULL
 * @warning This function frees memory previously allocated in the heap
 */
void pop(struct queue_container_node *queue_container);

/** 
 * @brief view_nth_item function which prints the nth item in the queue as long as it within the length.
 *
 * The view_nth_item function has as its input the nth item requested to be printed, the pointer function
 * for the appropriate variable type, and the queue_container_node which holds the queue request to search.
 * It uses a walker from the head of the queue n times and then uses the pointer function to print the value
 * pointed at by the node in the point in the queue.
 *
 * @p int n_item, @p void (*print_func_ptr)(void *), @p struct queue_container_node *queue_container
 *
 * Simple usage example
 * @code
 * view_nth_item(4, print_int, queue_container_int);
 * @endcode
 *
 * Function is void, returning NULL
 */
void view_nth_item(int n_item, void (*print_func_ptr)(void *), struct queue_container_node *queue_container);

/** 
 * @brief find_item_in_queue function which returns the item index if the item is found in the queue, -1 if not, -2 on a failure.
 *
 * The find_item_in_queue function has as its input the data being looked for, the pointer function 
 * for the appropriate variable type, and the queue_container_node which holds the queue request to search.
 * It uses a walker from the head of the queue, checks to see if the current data is the same as the comparison,
 * if it is not it moves to the next node until it reaches the length. If data is found breaks loop and returns the index, else -1.
 *
 * @p int (*same_func_ptr)(void *, void *), 
 * @p struct queue_container_node *queue_container @p void* comparison_data
 *
 * Simple usage example
 * @code
 * find_item_in_queue(same_int, queue_container_int, &int_array[5]);
 * @endcode
 *
 * Function is int, returning -2,-1, or index location
 */
int find_item_in_queue(int (*same_func_ptr)(void *, void *) , struct queue_container_node *queue_container, void * comparison_data);

/**
 * @brief Removes the specified index element from the queue
 *
 * The remove_at_location function has as its input the pointer to the queue_container
 *  and the index for the item requested to be removed.
 *  The function uses a walker node to navigate to the requested index location, after
 *  verifying that the requested index is not beyond the bounds of the list.
 *  Once at the location the function adjusts the pointers on either side of the
 *  soon to be deleted node. The function then frees the node. Decrements count 
 *  of the container if successful.
 *
 * @p struct queue_container_node* queue_container @p int remove_location
 *
 * Simple usage example
 * @code
 * remove_at_location(queue_container_int, 0);
 * @endcode
 *
 * Function is void, returning NULL
 * @warning This function frees memory previously allocated in the heap
 */
void remove_at_location(struct queue_container_node *queue_container, int remove_location);


/** 
 * @brief Removes the first instance matching the comparison data from the queue.
 * 
 * The remove_first_occurrence function has as it's input: a pointer function for comparison,
 *  the pointer to the queue_container and the data which to be found and removed.
 *  The function uses find_item_in_queue and remove_at_location to remove the item if it is found.
 *
 * @p int (*same_func_ptr)(void *, void *), 
 * @p struct queue_container_node* queue_container @p int remove_location
 *
 * Simple usage example
 * @code
 * remove_first_occurrence(same_int, queue_container_int, &int_array[5]);
 * @endcode
 *
 * Function is void, returning NULL
 * @warning This function frees memory previously allocated in the heap
 */
void remove_first_occurrence(int (*same_func_ptr)(void *, void *) , struct queue_container_node *queue_container, void * comparison_data);


/**
 * @brief clean_queue function which removes every element from the queue
 *
 * The clean_queue function has as it's input the pointer to the queue_container.
 * It navigates to the head node, which if not NULL is free'd and passes the
 * head pointer to the next node in the queue. This is repeated until every
 * element in the queue is removed
 *
 * @p struct queue_container_node* queue_container
 *
 * Simple usage example
 * @code
 * clean_queue(queue_containerInt);
 * @endcode
 *
 * Function is void, returning NULL
 */
void clean_queue(struct queue_container_node *queue_container);


/**
 * @brief clean_container function which removes every element from the queue
 *
 * The clean_container function has as it's input the pointer to the queue_container.
 * It calls clean_queue and then the queue_container itself
 * is also free'd
 *
 * @p struct queue_container_node* queue_container
 *
 * Simple usage example
 * @code
 * clean_container(queue_containerInt);
 * @endcode
 *
 * Function is void, returning NULL
 * @warning This function frees everything, if you wish to use the queue again
 * you will need to initialize again.
 */
void clean_container(struct queue_container_node *queue_container);


/**
 * @brief print_list function which prints every element in the queue beginning with head
 *
 * The print_list function has as it's input the function pointer for
 * the data type contained in the queue and the pointer to the queue_container.
 * It navigates to the head node, and uses the passed print function to print the item
 * it then navigates to the next element in the queue and repeats until
 * the next pointer is NULL.
 *
 * @p void(*print_func_ptr)(void *) , @p struct queue_container_node* queue_container
 *
 * Simple usage example
 * @code
 * print_list(print_int, queue_containerInt);
 * @endcode
 *
 * Function is void, returning NULL
 */
void print_list(void (*print_func_ptr)(void *), struct queue_container_node *queue_container);

/**
 * @brief memory_error helper function which indicates where a memory error is found
 *
 * The memory_error function has as it's input two strings, the data type that led to the error
 * and the function in which the error occurred. 
 *
 * @p char* data_type @p char* function_location
 *
 * Simple usage example
 * @code
 * memory_error("temp", "push()");
 * @endcode
 *
 * Function is void, returning NULL
 */
void memory_error(char * data_type, char * function_location);

#endif  /* QUEUE_H_ */
