#include "monty.h"

/**
* op_div - divides the first two nodes together
* @stack: a pointer to the head of a linked list
* @line_number: the line number
* Return: nothing
*/
void op_div(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *second_node;

	if (!current || !current->next)
		div_error(line_number);

	if (current->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	second_node = current->next;
	second_node->n = second_node->n / current->n;
	op_pop(stack, line_number);
}
