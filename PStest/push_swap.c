
# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

static int counter = 0;
void swap(int *a, int *b);
int partition(int *arr, int low, int high);
void quicksort(int *arr, int low, int high);
bool is_valid_integer(char *str);
bool validate_args(char **argv, int argc);

// Swap two integerss
void swap(int *a, int *b)
{
    counter++;
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for Quicksort
int partition(int *arr, int low, int high)
{
    int pivot = arr[high];  // Choose the last element as the pivot
    int i = low - 1;        // Index of the smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);  // Place the pivot in the correct position
    return i + 1;
}
// Quicksort function
void quicksort(int *arr, int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);  // Partition index
        quicksort(arr, low, pi - 1);         // Sort the left sub-array
        quicksort(arr, pi + 1, high);        // Sort the right sub-array
    }
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

int main(int argc, char **argv)
{
    if (argc == 1) {
        printf("Usage: %s <list of integers>\n", argv[0]);
        return 1;
    }
    t_node	*a; //To store a pointer to stack `a`
	t_node	*b; //To store a pointer to stack `b`
    if (!validate_args(argv, argc)) {
        printf("Error: Invalid arguments\n");
        return 1;
    }

    int *arr = malloc((argc - 1) * sizeof(int));
    if (!arr) {
        printf("Error: Memory allocation failed\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        arr[i - 1] = atoi(argv[i]);
    }
    quicksort(arr, 0, argc - 2);

    printf("Sorted array: ");
    for (int i = 0; i < argc - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("%d",counter);

    free(arr);

    return 0;
}
