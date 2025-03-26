/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgiilapshin <georgiilapshin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:00:37 by glapshin          #+#    #+#             */
/*   Updated: 2025/03/26 01:36:12 by georgiilaps      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int main(int argc, char **argv) {
    if (argc == 1) {
        printf("Usage: %s <list of integers>\n", argv[0]);
        return 1;
    }

    if (!validate_args(argv, argc))
	    error_exit();
    
    int c = 0;
    c = argc / 16;
    stack_a = argv_to_linked_list(argc, argv);
    stack_b = NULL;

    if (!stack_a)
	    error_exit();

    if(argc < 7)
    {
        sort_small(&stack_a, &stack_b);
    }
    else 
    {
        turk_sort(&stack_a, &stack_b, c);
    }
    //print_list(stack_a);
    //int count = get_op_count();
    //printf("%d", count);
    free_list(stack_a);

    return 0;
}

