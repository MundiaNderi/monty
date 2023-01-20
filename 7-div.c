#include "monty.h"

/**
<<<<<<< HEAD
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
=======
 * subop - subtracts the top two elements and stores it in second element
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void subop(stack_t **stack, unsigned int nline)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n -= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
>>>>>>> 8bd2961cb63db6e1a0a3a5d0abc724dc4b47334d
}
