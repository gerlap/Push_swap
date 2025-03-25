/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glapshin <glapshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 22:44:46 by glapshin          #+#    #+#             */
/*   Updated: 2025/03/24 23:21:29 by glapshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// === Core sorting dispatcher ===

void sort_small(t_node **a, t_node **b) {
    int size = stack_size(*a);

    if (size == 2)
        sort_2(a);
    else if (size == 3)
        sort_3(a);
    else if (size == 4 || size == 5)
        sort_4_5(a, b);
}

// === Sort 2 ===

void sort_2(t_node **a) {
    if ((*a)->value > (*a)->next->value)
        sa(a);
}

// === Sort 3 ===

void sort_3(t_node **a) {
    int x = (*a)->value;
    int y = (*a)->next->value;
    int z = (*a)->next->next->value;

    if (x > y && y < z && x < z)
        sa(a);
    else if (x > y && y > z) {
        sa(a);
        rra(a);
    }
    else if (x > y && y < z && x > z)
        ra(a);
    else if (x < y && y > z && x < z) {
        sa(a);
        ra(a);
    }
    else if (x < y && y > z && x > z)
        rra(a);
}

// === Sort 4 or 5 ===

void sort_4_5(t_node **a, t_node **b) {
    while (stack_size(*a) > 3) {
        t_node *min = get_min(*a);
        int pos = get_pos(*a, min);
        if (pos <= stack_size(*a) / 2)
            while (*a != min)
                ra(a);
        else
            while (*a != min)
                rra(a);
        pb(a, b);
    }
    sort_3(a);
    while (*b)
        pa(a, b);
}

// === Helper Functions ===

int stack_size(t_node *stack) {
    int i = 0;
    while (stack) {
        stack = stack->next;
        i++;
    }
    return i;
}

t_node *get_min(t_node *stack) {
    t_node *min = stack;
    while (stack) {
        if (stack->value < min->value)
            min = stack;
        stack = stack->next;
    }
    return min;
}

int get_pos(t_node *stack, t_node *target) {
    int i = 0;
    while (stack) {
        if (stack == target)
            return i;
        stack = stack->next;
        i++;
    }
    return -1;
}
