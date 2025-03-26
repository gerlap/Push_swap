/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgiilapshin <georgiilapshin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 00:21:22 by georgiilaps       #+#    #+#             */
/*   Updated: 2025/03/26 00:40:46 by georgiilaps      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "push_swap.h"

#define SIZE 500
#define RUNS 10

int op_count = 0;

void counted_pb(t_node **a, t_node **b) { pb(a, b); op_count++; }
void counted_pa(t_node **a, t_node **b) { pa(a, b); op_count++; }
void counted_ra(t_node **a) { ra(a); op_count++; }
void counted_rb(t_node **b) { rb(b); op_count++; }
void counted_rrb(t_node **b) { rrb(b); op_count++; }

t_node *generate_random_stack(int size) {
    int *arr = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) arr[i] = i;
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
    }
    t_node *stack = NULL;
    for (int i = 0; i < size; i++) push_back(&stack, arr[i]);
    free(arr);
    return stack;
}

t_node *tester_create_node(int value) {
    t_node *new_node = malloc(sizeof(t_node));
    if (!new_node)
        return NULL;
    new_node->value = value;
    new_node->index = -1;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void push_back(t_node **stack, int value) {
    t_node *new = tester_create_node(value);
    if (!new)
        return;

    if (!*stack) {
        *stack = new;
        return;
    }

    t_node *cur = *stack;
    while (cur->next)
        cur = cur->next;
    cur->next = new;
    new->prev = cur;
}

int main(void) {
    srand(time(NULL));
    printf("Chunks,AverageOperations\n");

    for (int chunks = 5; chunks <= 30; chunks++) {
        int total_ops = 0;

        for (int run = 0; run < RUNS; run++) {
            t_node *a = generate_random_stack(SIZE);
            t_node *b = NULL;
            op_count = 0;

            #define pb counted_pb
            #define pa counted_pa
            #define ra counted_ra
            #define rb counted_rb
            #define rrb counted_rrb
            turk_sort(&a, &b, chunks);
            #undef pb
            #undef pa
            #undef ra
            #undef rb
            #undef rrb

            total_ops += op_count;
            free_list(a);
            free_list(b);
        }

        double avg = (double)total_ops / RUNS;
        printf("%d,%.2f\n", chunks, avg);
    }

    return 0;
}