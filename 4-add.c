#include "monty.h"

/**
* op_add - adds the first two nodes together
* @stack: a pointer to the head of a linked list
* @line_number: the line number
* Return: nothing
*/
void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *second_node;

	if (!current || !current->next)
		add_error(line_number);

	second_node = current->next;
	second_node->n = second_node->n + current->n;
	op_pop(stack, line_number);
}
