#include "monty.h"

/**
* op_mod - computes the rest of the division of the second top
* element of the stack by the top element of the stack
* @stack: stack
* @lnum: line number
* Return: void
*/
void op_mod(stack_t **stack, unsigned int lnum)
{
stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", lnum);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", lnum);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n %= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp)
}
/**
* op_pchar - prints the char at the top of the stack
* @stack: stack
* @lnum: line number
* Return: void
*/
void op_pchar(stack_t **stack, unsigned int lnum)
{
	stack_t *temp = *stack;
	int num;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", lnum);
		free_global();
		exit(EXIT_FAILURE);
	}

	for (; temp->next; temp = temp->next)
		;
	num = temp->n;
	if (num < 0 || num > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", lnum);
		free_global();
		exit(EXIT_FAILURE);
	}

	putchar(num);
	putchar('\n');
}

/**
* op_pstr - prints the string starting from the top
* @stack: stack
* @lnum: line number
* Return:void
*/
void op_pstr(stack_t **stack, unsigned int lnum)
{
	stack_t *temp = *stack;
	int num;

	if (!(*stack))
		putchar('\n');
	else
	{
		for (; temp->next; temp = temp->next)
			;

		for (; temp; temp = temp->prev)
		{
			num = temp->n;
			if (num == 0 || num < 0 || num > 127)
				break;

			putchar(num);
		}
		putchar('\n');
	}
	(void)lnum;
}

/**
* op_rotl - rotates the stack to the top
* the top element of the stack becomes the bottom and the second top element.
* becomes the top element
* @stack: stack
* @lnum: line number
* Return: void
*/
void op_rotl(stack_t **stack, unsigned int lnum)
{
	stack_t *temp = *stack, *prev;

	if (*stack && (*stack)->next)
	{
		for (; temp->next; temp = temp->next)
			;

		if (temp->prev == *stack)
		{
			prev = *stack;
			prev->prev = temp;
			prev->next = NULL;
			temp->prev = NULL;
			temp->next = prev;
			*stack = temp;
		}
		else
		{
			prev = temp->prev;
			prev->next = NULL;

			temp->next = *stack;
			temp->prev = NULL;
			(*stack)->prev = temp;
			*stack = temp;
		}
	}
	(void)lnum;
}

/**
* op_rotr - rotates the stack to the bottom
* the last element of the stack becomes the top element of the stack
* @stack: stack
* @lnum: line number
* Return: void
*/
void op_rotr(stack_t **stack, unsigned int lnum)
{
	stack_t *temp = *stack, *prev;

	if (*stack && (*stack)->next)
	{
		prev = temp;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;

		for (temp = *stack; temp->next; temp = temp->next)
			;

		prev->prev = temp;
		prev->next = NULL;
		temp->next = prev;
	}
	(void)lnum;
}
