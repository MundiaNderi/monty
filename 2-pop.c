#include "monty.h"

/**
* op_pop - function that removes the top element of the stack
* @stack: a pointer to the head of a linked list
* @line_number: the line number
* Return: Nothing
*/
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *tmp;

	if (!current)
		pop_error(stack, line_number);

	tmp = current->next;
	free(current);
	*stack = tmp;
	current = *stack;
	if (current)
	{
		current->prev = NULL;
	}
}
