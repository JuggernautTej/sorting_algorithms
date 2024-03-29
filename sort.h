#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
const int n;
struct listint_s *prev;
struct listint_s *next;
} listint_t;

void swap(int *n, int *m);
void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void swap(int *a, int *b);
void quick_sort(int *array, size_t size);
int partition(int arr[], int low, int high, size_t size);
void swap(int *a, int *b);
void quick_sort_recursive(int arr[], int low, int high, size_t size);
void array_print(int arr[], size_t size);

#endif
