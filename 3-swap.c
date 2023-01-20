#include "monty.h"

/**
* op_swap - function that swaps the first 2 nodes in a linked list
* @stack: a pointer to the head of a linked list
* @l: the line number
* Return: nothing
*/
void op_swap(stack_t **stack, unsigned int l)
{
	stack_t *current = *stack;
	stack_t *second_node;
	int temp;

	if (!(*stack))
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", l);
		free_buff();
		exit(EXIT_FAILURE);
	}

	if (current && current->next)
	{
		second_node = current->next;
		temp = current->n;
		current->n = second_node->n;
		second_node->n = temp;
	}

	else
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", l);
		free_buff();
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
