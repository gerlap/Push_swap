/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgiilapshin <georgiilapshin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:53:27 by georgiilaps       #+#    #+#             */
/*   Updated: 2025/03/25 00:54:39 by georgiilaps      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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