/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glapshin <glapshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:00:37 by glapshin          #+#    #+#             */
/*   Updated: 2025/03/24 20:10:36 by glapshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to create a new node
t_node *stack_a = NULL;
t_node *stack_b = NULL;

t_node *create_node(int value, int index) {
    t_node *new_node = malloc(sizeof(t_node));
    if (!new_node)
        return NULL;
    new_node->value = value;
    new_node->index = index;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// Function to convert argv to a doubly linked list
t_node *argv_to_linked_list(int argc, char **argv) {
    if (argc < 2) {
        printf("Error: No arguments provided.\n");
        return NULL;
    }

    t_node *head = NULL, *tail = NULL;
    for (int i = 1; i < argc; i++) {
        int value = atoi(argv[i]);
        t_node *new_node = create_node(value, i - 1);
        if (!new_node) {
            printf("Error: Memory allocation failed.\n");
            return NULL;
        }

        if (!head) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }
    return head;
}

// Partition function for quicksort
t_node *partition(t_node *head, t_node *end, t_node **new_head, t_node **new_end, int *iterations) {
    t_node *pivot = end;
    t_node *prev = NULL, *cur = head, *tail = pivot;

    while (cur != pivot) {
        if (cur->value < pivot->value) {
            if (!*new_head)
                *new_head = cur;
            prev = cur;
            cur = cur->next;
        } else {
            if (prev)
                prev->next = cur->next;
            if (cur->next)
                cur->next->prev = prev;

            t_node *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            cur->prev = tail;
            tail = cur;
            cur = tmp;
        }
    }

    if (!*new_head)
        *new_head = pivot;
    *new_end = tail;

    (*iterations)++; // Increment the iteration counter

    return pivot;
}

// Recursive quicksort for doubly linked list
t_node *quicksort_linked_list(t_node *head, t_node *end, int *iterations) {
    if (!head || head == end)
        return head;

    t_node *new_head = NULL, *new_end = NULL;
    t_node *pivot = partition(head, end, &new_head, &new_end, iterations);

    if (new_head != pivot) {
        t_node *tmp = new_head;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
        pivot->prev = NULL;

        new_head = quicksort_linked_list(new_head, tmp, iterations);
        tmp = get_tail(new_head);
        tmp->next = pivot;
        pivot->prev = tmp;
    }

    pivot->next = quicksort_linked_list(pivot->next, new_end, iterations);
    if (pivot->next)
        pivot->next->prev = pivot;

    return new_head;
}

int main(int argc, char **argv) {
    if (argc == 1) {
        printf("Usage: %s <list of integers>\n", argv[0]);
        return 1;
    }

    if (!validate_args(argv, argc)) {
        return 1;
    }

    // Convert argv to a linked list
    t_node *head = argv_to_linked_list(argc, argv);
    if (!head) {
        return 1;
    }

    t_node *end = get_tail(head);
    int iterations = 0; // Local variable to track iterations

    head = quicksort_linked_list(head, end, &iterations);

    // Print the sorted linked list
    printf("Sorted List: ");
    print_list(head);

    // Print the number of iterations
    printf("Quicksort Iterations: %d\n", iterations);

    // Free the linked list
    free_list(head);

    return 0;
}

