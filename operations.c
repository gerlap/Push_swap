/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glapshin <glapshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:46:04 by glapshin          #+#    #+#             */
/*   Updated: 2025/03/24 19:46:07 by glapshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void swap(t_node **stack) {
    if (*stack && (*stack)->next) {
        t_node *first = *stack;
        t_node *second = first->next;

        first->next = second->next;
        if (second->next)
            second->next->prev = first;

        second->prev = NULL;
        second->next = first;
        first->prev = second;

        *stack = second;
    }
}

void sa(t_node **a) { swap(a); write(1, "sa\n", 3); }
void sb(t_node **b) { swap(b); write(1, "sb\n", 3); }
void ss(t_node **a, t_node **b) { swap(a); swap(b); write(1, "ss\n", 3); }

// Push from src to dest
static void push(t_node **src, t_node **dest) {
    if (*src) {
        t_node *node = *src;
        *src = node->next;
        if (*src)
            (*src)->prev = NULL;

        node->next = *dest;
        if (*dest)
            (*dest)->prev = node;

        node->prev = NULL;
        *dest = node;
    }
}

void pa(t_node **a, t_node **b) { push(b, a); write(1, "pa\n", 3); }
void pb(t_node **a, t_node **b) { push(a, b); write(1, "pb\n", 3); }

// Rotate stack up
static void rotate(t_node **stack) {
    if (*stack && (*stack)->next) {
        t_node *first = *stack;
        t_node *last = *stack;

        *stack = first->next;
        (*stack)->prev = NULL;

        while (last->next)
            last = last->next;

        last->next = first;
        first->prev = last;
        first->next = NULL;
    }
}

void ra(t_node **a) { rotate(a); write(1, "ra\n", 3); }
void rb(t_node **b) { rotate(b); write(1, "rb\n", 3); }
void rr(t_node **a, t_node **b) { rotate(a); rotate(b); write(1, "rr\n", 3); }

// Reverse rotate stack
static void reverse_rotate(t_node **stack) {
    if (*stack && (*stack)->next) {
        t_node *last = *stack;
        while (last->next)
            last = last->next;

        if (last->prev)
            last->prev->next = NULL;

        last->next = *stack;
        (*stack)->prev = last;
        last->prev = NULL;
        *stack = last;
    }
}

void rra(t_node **a) { reverse_rotate(a); write(1, "rra\n", 4); }
void rrb(t_node **b) { reverse_rotate(b); write(1, "rrb\n", 4); }
void rrr(t_node **a, t_node **b) { reverse_rotate(a); reverse_rotate(b); write(1, "rrr\n", 4); }
