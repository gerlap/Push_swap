/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turksort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgiilapshin <georgiilapshin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:59:46 by georgiilaps       #+#    #+#             */
/*   Updated: 2025/03/25 01:03:00 by georgiilaps      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node *get_max(t_node *stack) {
    t_node *max = stack;
    while (stack) {
        if (stack->index > max->index)
            max = stack;
        stack = stack->next;
    }
    return max;
}

void assign_indices(t_node *stack) {
    int size = stack_size(stack);
    int *arr = malloc(sizeof(int) * size);
    t_node *cur = stack;

    for (int i = 0; cur; i++, cur = cur->next)
        arr[i] = cur->value;

    // Simple bubble sort
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if (arr[i] > arr[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }

    for (cur = stack; cur; cur = cur->next)
        for (int i = 0; i < size; i++)
            if (cur->value == arr[i]) {
                cur->index = i;
                break;
            }

    free(arr);
}

void turk_sort(t_node **a, t_node **b, int chunks) {
    assign_indices(*a);
    int size = stack_size(*a);
    int i = 0;
    int range = size / chunks;

    while (*a) {
        if ((*a)->index <= i) {
            pb(a, b);
            rb(b);
            i++;
        } else if ((*a)->index <= i + range) {
            pb(a, b);
            i++;
        } else
            ra(a);
    }

    while (*b) {
        t_node *max = get_max(*b);
        int pos = get_pos(*b, max);
        int mid = stack_size(*b) / 2;

        if (pos <= mid)
            while (*b != max)
                rb(b);
        else
            while (*b != max)
                rrb(b);

        pa(a, b);
    }
}