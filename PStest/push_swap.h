#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

// Define the node structure for the linked list
typedef struct s_node //A container of data enclosed in {} braces. `s_` for struct
{
	int					value; //The number to sort
	int					index; //The number's position in the stack
	struct s_node	*next; //A pointer to the next node
	struct s_node	*prev; //A pointer to the previous node
}	t_node; //The "shortened name", "t_node". `t_` for type
// Function to create a new node
#endif