/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glapshin <glapshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:00:54 by glapshin          #+#    #+#             */
/*   Updated: 2025/03/24 23:12:32 by glapshin         ###   ########.fr       */
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
void sort_small(t_node **a, t_node **b);

#endif