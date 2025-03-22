#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "push_swap.h"

t_node *create_node(int value, int index)
{
    t_node *new_node = malloc(sizeof(t_node));
    if (!new_node)
        return NULL;  // Handle memory allocation failure
    new_node->value = value;
    new_node->index = index;
    new_node->next = NULL; //Initializes the next pointer to NULL, indicating that this node does not point to any other node yet.
    new_node->prev = NULL; //Initializes the prev pointer to NULL, indicating that this node does not point to any previous node yet.
    return new_node;
}

// Function to convert argv to a linked list
t_node *argv_to_linked_list(int argc, char **argv)
{
    if (argc < 2) {
        printf("Error: No arguments provided.\n");
        return NULL;
    }

    t_node *head = NULL;  // Head of the linked list
    t_node *tail = NULL;  // Tail of the linked list

    for (int i = 1; i < argc; i++) {
        // Convert the argument to an integer
        int value = atoi(argv[i]);

        // Create a new node
        t_node *new_node = create_node(value, i - 1);
        if (!new_node) {
            printf("Error: Memory allocation failed.\n");
            return NULL;
        }

        // Add the new node to the linked list
        if (!head) {
            head = new_node;  // If the list is empty, set the new node as the head
            tail = new_node;
        } else {
            tail->next = new_node;  // Append the new node to the end of the list
            tail = new_node;
        }
    }

    return head;  // Return the head of the linked list
}

// Function to print the linked list
void print_list(t_node *head)
{
    t_node *current = head;
    while (current) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free the linked list
void free_list(t_node *head)
{
    t_node *current = head;
    t_node *next;
    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
}

// Main function to test the implementation
int main(int argc, char **argv)
{
    // Convert argv to a linked list
    t_node *head = argv_to_linked_list(argc, argv);
    if (!head)
        return 1;

    // Print the linked list
    print_list(head);

    // Free the linked list
    free_list(head);

    return 0;
}