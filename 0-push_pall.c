#include "monty.h"
glo_t glo;

/**
* op_push - function that push an element to the stack
* @stack: a pointer to the head of a linked list
* @line_number: the line number
* Return: nothing
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;


	if (stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", line_number);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	
	new->next = *stack;
	new->prev = NULL;
	new->n = arg.arg;

	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}

/**
*  pall - function that prints out all the elements of a linked list
*  @stack: a pointer to the head of a linked list
*  @line_number: the line number
*  Return: nothing
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
