#include <stdlib.h>
#include <stdio.h>

#include "Queue.h"


struct queue_container_node* queue_container_init()
{
    struct queue_container_node * queue_container = NULL;
    queue_container = (struct queue_container_node*)calloc(1, sizeof(struct queue_container_node));
    if (queue_container == NULL)
    {
        memory_error("queue_container", "queue_container_init()");
        return NULL;
    }
    queue_container->head = NULL;
    queue_container->tail = NULL;
    queue_container->queue_length = 0;
    return queue_container;
};

void push(void * node_data, struct queue_container_node *queue_container)
{
    // This will add the new node to tail position such that head
    //  is the First in and will be the First out
    if (queue_container == NULL)
    {
        memory_error("queue_container", "push()");
        return;
    }
    if (node_data == NULL)
    {
        memory_error("node_data", "push()");
        return;
    }
    struct queue_node* temp = (struct queue_node*)calloc(1, sizeof(struct queue_node));
    if (temp == NULL)
    {
        memory_error("temp", "push()");
        return;
    }

    temp->data = node_data;
    temp->next_node = NULL;

    if (queue_container->queue_length == 0)
    {
        queue_container->head = temp;
        queue_container->tail = temp;
    }
    else
    {
        queue_container->tail->next_node = temp;
        queue_container->tail = temp;
    }

    queue_container->queue_length += 1;
}

void pop(struct queue_container_node *queue_container)
{
    if (queue_container == NULL)
    {
        memory_error("queue_container", "pop()");
        return;
    }
    remove_at_location(queue_container, 0);
}

void view_nth_item(int n_item, void (*print_func_ptr)(void *), struct queue_container_node *queue_container)
{
    if (print_func_ptr==NULL)
    {
        memory_error("print_func_ptr", "view_nth_item()");
        return ;
    }
    if (queue_container==NULL)
    {
        memory_error("queue_container", "view_nth_item()");
        return ;
    }
    if (n_item > queue_container->queue_length)
    {
        printf("You are requesting to view an item that is beyond the items in the queue.\n");
    }
    else
    {
        struct queue_node * walker = queue_container->head;
        int walker_ind = 1;
        while (walker_ind < n_item)
        {
            walker_ind ++;
            // This should never occur because we checked that the item was in the range of the queue
            if (walker == NULL) 
            {
                printf("It seems we have tried to print beyond the end of the queue.\n");
                return ;
            } 
            walker = walker->next_node;
        }
        (*print_func_ptr)(walker->data);
        printf(" is the %d item value. \n", walker_ind);
    }
}

int find_item_in_queue(int (*same_func_ptr)(void *, void *) , struct queue_container_node *queue_container, void * comparison_data)
{
    if (same_func_ptr==NULL)
    {
        memory_error("same_func_ptr", "find_item_in_queue()");
        return -2;
    }
    if (queue_container==NULL)
    {
        memory_error("queue_container", "find_item_in_queue()");
        return -2;
    }
    if (comparison_data==NULL)
    {
        memory_error("comparison_data", "find_item_in_queue()");
        return -2;
    }
    struct queue_node* compare_node = queue_container->head;
    for (int walk_index = 0; walk_index < queue_container->queue_length; walk_index ++)
    {
        // same_func_ptr returns 0 if both data are the same
        if ((*same_func_ptr)(compare_node->data, comparison_data) == 0)
        {
            return walk_index;
        }
        compare_node = compare_node->next_node;
    }
    return -1;
}

void remove_at_location(struct queue_container_node *queue_container, int remove_location)
{
    if (queue_container==NULL)
    {
        memory_error("queue_container", "remove_at_location()");
        return;
    }
    // 0 index'd means if location is >= we are beyond bounds of list
    if (remove_location >= queue_container->queue_length)
    {
        printf("You are attempting to delete at an index beyond the list. \n");
        printf(" We have %d nodes and your location is %d \n", queue_container->queue_length, remove_location);
        printf("We will instead do nothing, try again. \n");
    }
    // This is the case that the tail and head point to the same single node and index requested is 0
    else if (queue_container->queue_length == 1)
    {
        struct queue_node* delete_node = queue_container->head;
        queue_container->head = NULL;
        queue_container->tail = NULL;
        queue_container->queue_length = 0;
        free(delete_node);
    }
    else
    {
        // Want to maintain trailing node to update next_node to the next_node of the deleted node
        struct queue_node* delete_node = queue_container->head;
        struct queue_node* rear_node = queue_container->tail;

        // We are already sure remove_location will not take us beyond the end
        for (int walk_index = 0; walk_index < remove_location; walk_index ++)
        {
            rear_node = delete_node;
            delete_node = delete_node->next_node;
        }

        // Here we are taking previous node's next to delete's next in preparation for removing delete
        rear_node->next_node = delete_node->next_node;
        if (delete_node == queue_container->head)
        {
            // We need to migrate the head pointer before clearing
            queue_container->head = queue_container->head->next_node;
            rear_node->next_node = NULL; // Our queue is not circular, we want tail to end on NULL
        }
        else if (delete_node == queue_container->tail)
        {
            // We need to migrate the tail pointer before clearing
            queue_container->tail = rear_node;
        }
        free(delete_node);
        queue_container->queue_length -= 1;
    }
}

void remove_first_occurrence(int (*same_func_ptr)(void *, void *) , struct queue_container_node *queue_container, void * comparison_data)
{
    if (same_func_ptr==NULL)
    {
        memory_error("same_func_ptr", "find_item_in_queue()");
        return ;
    }
    if (queue_container==NULL)
    {
        memory_error("queue_container", "find_item_in_queue()");
        return ;
    }
    if (comparison_data==NULL)
    {
        memory_error("comparison_data", "find_item_in_queue()");
        return ;
    }
    int remove_nodex_index = find_item_in_queue(same_func_ptr, queue_container, comparison_data);
    if (remove_nodex_index < 0)
    {
        printf("Trying to remove a data from the queue that is not present.\n");
    }
    else
    {
        remove_at_location(queue_container, remove_nodex_index);
    }
}

void clean_queue(struct queue_container_node *queue_container)
{
    if (queue_container == NULL)
    {
        memory_error("queue_container", "clean_queue()");
        return;
    }
    while (queue_container->queue_length != 0)
    {
        pop(queue_container);
    }
}

void clean_container(struct queue_container_node *queue_container)
{
    if (queue_container == NULL)
    {
        memory_error("queue_container", "clean_container()");
        return;
    }
    clean_queue(queue_container);
    free(queue_container);
}

void print_list(void (*print_func_ptr)(void *), struct queue_container_node *queue_container)
{
    if (print_func_ptr == NULL)
    {
        memory_error("print_func_ptr", "print_list()");
        return;
    }
    if (queue_container == NULL)
    {
        memory_error("queue_container", "print_list()");
        return;
    }
    struct queue_node * walker = queue_container->head;
    int num_checked = 0;
    while (num_checked < queue_container->queue_length)
    {
        (*print_func_ptr)(walker->data);
        walker = walker->next_node;
        num_checked ++;
    }
    printf("\n");
}



void memory_error(char * data_type, char * function_location)
{
    printf("Insufficient space or passed NULL value for %s in %s\n", data_type, function_location);
}