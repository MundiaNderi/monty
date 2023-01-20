#include "monty.h"

/**
* op_pint - function that prints the value at the top of the stack
* @stack: a pointer to the head of a linked list
* @line_number: the line number
* Return: nothing
*/
void op_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (current)
	{
		printf("%d\n", current->n);
	}
	else
	{
		pint_error(line_number);
	}
}
