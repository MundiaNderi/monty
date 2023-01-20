#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
* swap - function that swaps the first 2 nodes in a linked list
* @stack: a pointer to the head of a linked list
* @size: size of the stack.
* @line_number - indicates the current line number where
* the function is being called.
* Return: nothing
*/
void swap(int *stack, int size, int line_number)
{
	if (size < 2)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		int temp = stack[size - 1];
		stack[size - 1] = stack[size - 2];

		stack[size - 2] = temp;
	}
}

