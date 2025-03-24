
# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_node //A container of data enclosed in {} braces. `s_` for struct
{
	int					value; //The number to sort
	int					index; //The number's position in the stack
	struct s_node	*next; //A pointer to the next node
	struct s_node	*prev; //A pointer to the previous node
}	t_node; //The "shortened name", "t_node". `t_` for type
// Function to create a new node
t_node *create_node(int value, int index)
{
    t_node *new_node = malloc(sizeof(t_node));
    if (!new_node)
        return NULL;  // Handle memory allocation failure
    new_node->value = value;
    new_node->index = index;
    new_node->next = NULL; //Initializes the next pointer to NULL, indicating that this node does not point to any other node yet.
    new_node->prev = NULL; //Initializes the prev pointer to NULL, indicating that this node does not point to any previous node yet.
    return new_node;
}

// Function to convert argv to a linked list
t_node *argv_to_linked_list(int argc, char **argv)
{
    if (argc < 2) {
        printf("Error: No arguments provided.\n");
        return NULL;
    }
    t_node *head = NULL;  // Head of the linked list
    t_node *tail = NULL;  // Tail of the linked list

    for (int i = 1; i < argc; i++) {
        // Convert the argument to an integer
        int value = atoi(argv[i]);
        // Create a new node
        t_node *new_node = create_node(value, i - 1);
        if (!new_node) {
            printf("Error: Memory allocation failed.\n");
            return NULL;
        }
        // Add the new node to the linked list
        if (!head) {
            head = new_node;  // If the list is empty, set the new node as the head
            tail = new_node;
        } else {
            tail->next = new_node;  // Append the new node to the end of the list
            tail = new_node;
        }
    }

    return head;  // Return the head of the linked list
}

t_node *partition(t_node *head, t_node *end, t_node **new_head, t_node **new_end)
{
    t_node *pivot = end;
    t_node *prev = NULL, *cur = head, *tail = pivot;

    while (cur != pivot) {
        if (cur->value < pivot->value) {
            if (*new_head == NULL)
                *new_head = cur;
            prev = cur;
            cur = cur->next;
        } else {
            if (prev)
                prev->next = cur->next;
            t_node *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if (*new_head == NULL)
        *new_head = pivot;

    *new_end = tail;

    return pivot;
}

t_node *quicksort_linked_list(t_node *head, t_node *end)
{
    if (!head || head == end)
        return head;

    t_node *new_head = NULL, *new_end = NULL;
    t_node *pivot = partition(head, end, &new_head, &new_end);

    if (new_head != pivot) {
        t_node *tmp = new_head;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;

        new_head = quicksort_linked_list(new_head, tmp);

        tmp = new_head;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = pivot;
    }

    pivot->next = quicksort_linked_list(pivot->next, new_end);

    return new_head;
}

// Check if a string is a valid integer
bool is_valid_integer(char *str)
{
    if (*str == '-' || *str == '+') str++;  // Skip optional sign
    while (*str) {
        if (*str < '0' || *str > '9')
            return false;
        str++;
    }
    return true;
}

// Validate command-line arguments
bool validate_args(char **argv, int argc)
{
    for (int i = 1; i < argc; i++) {
        if (!is_valid_integer(argv[i])) {
            return false;
        }
        for (int j = i + 1; j < argc; j++) {
            if (atoi(argv[i]) == atoi(argv[j])) {
                return false;
            }
        }
    }
    return true;
}

void print_list(t_node *head)
{
    t_node *current = head;
    while (current) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free the linked list
void free_list(t_node *head)
{
    t_node *current = head;
    t_node *next;
    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main(int argc, char **argv)
{
    if (argc == 1) {
        printf("Usage: %s <list of integers>\n", argv[0]);
        return 1;
    }

    if (!validate_args(argv, argc)) {
        printf("Error: Invalid arguments\n");
        return 1;
    }

    // Convert argv to a linked list
    t_node *head = argv_to_linked_list(argc, argv);
    if (!head) {
        printf("Error: Failed to create linked list\n");
        return 1;
    }
    head = quicksort_linked_list(head, NULL);
    // Print the linked list
    printf("Linked List: ");
    print_list(head);

    // Free the linked list
    free_list(head);

    return 0;
}
