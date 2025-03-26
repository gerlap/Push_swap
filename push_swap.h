/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgiilapshin <georgiilapshin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:00:54 by glapshin          #+#    #+#             */
/*   Updated: 2025/03/26 00:23:37 by georgiilaps      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdbool.h>
#include <limits.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
    int             value;
    int             index;
    struct s_node   *next;
    struct s_node   *prev;
}               t_node;

/* linked list utils */
t_node  *create_node(int value, int index);
t_node  *argv_to_linked_list(int argc, char **argv);
t_node  *get_tail(t_node *head);
void    free_list(t_node *head);
void    print_list(t_node *head);

/* quicksort */
t_node  *quicksort_linked_list(t_node *head, t_node *end, int *iterations);
t_node  *partition(t_node *head, t_node *end, t_node **new_head, t_node **new_end, int *iterations);

/* validation */
bool    is_valid_integer(char *str);
bool    validate_args(char **argv, int argc);
int     get_op_count(void);
void	error_exit(void);

//operators
void sa(t_node **a);
void sb(t_node **b);
void ss(t_node **a, t_node **b);
void pa(t_node **a, t_node **b);
void pb(t_node **a, t_node **b);
void ra(t_node **a);
void rb(t_node **b);
void rr(t_node **a, t_node **b);
void rra(t_node **a);
void rrb(t_node **b);
void rrr(t_node **a, t_node **b);

//add_sort
int stack_size(t_node *stack);
t_node *get_min(t_node *stack);
int get_pos(t_node *stack, t_node *target);
void sort_small(t_node **a, t_node **b);
void sort_2(t_node **a);
void sort_3(t_node **a);
void sort_4_5(t_node **a, t_node **b);
void turk_sort(t_node **a, t_node **b, int chunks);
void assign_indices(t_node *stack);

//additional for tester
void    push_back(t_node **stack, int value);
void    free_stack(t_node *stack);

#endif