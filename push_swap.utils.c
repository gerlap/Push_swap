/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgiilapshin <georgiilapshin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:17:24 by glapshin          #+#    #+#             */
/*   Updated: 2025/03/25 02:28:07 by georgiilaps      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Check if a string is a valid integer
bool is_valid_integer(char *str) {
    if (*str == '-' || *str == '+') str++;
    while (*str) {
        if (*str < '0' || *str > '9')
            return false;
        str++;
    }
    return true;
}

// Validate command-line arguments
bool validate_args(char **argv, int argc) {
    for (int i = 1; i < argc; i++) {
        if (!is_valid_integer(argv[i])) {
            error_exit();
            return false;
        }
    }
    return true;
}

// Print the linked list
void print_list(t_node *head) {
    t_node *current = head;
    while (current) {
        printf("%d ", current->value);
        current = current->next;
    }
}

// Function to free the linked list
void free_list(t_node *head) {
    while (head) {
        t_node *temp = head;
        head = head->next;
        free(temp);
    }
}
// Return the tail (last node) of the doubly linked list
t_node *get_tail(t_node *head) {
    if (!head)
        return NULL;
    while (head->next)
        head = head->next;
    return head;
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
