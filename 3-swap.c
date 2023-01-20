#include "monty.h"

/**
* op_swap - function that swaps the first 2 nodes in a linked list
* @stack: a pointer to the head of a linked list
* @n: the line number
* Return: nothing
*/
void swap(stack_t **stack, unsigned int nline)
{
	int temp;

	if (stack == NULL || *stack == NULL || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;	 
}
