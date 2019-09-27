#include "monty.h"
/**
 * rotr -rotates the stack to the top.
 * @stack: a double linked list
 * @line_number: number of line in code to print error message.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *p = NULL;
	(void)line_number;

	if (*stack == NULL)
		return;
	if ((*stack)->prev == NULL)
		return;
	do {
		p = (*stack)->prev;
		(*stack)->prev = (*stack)->next;
		(*stack)->next = p;
		if (p != NULL)
			*stack = p;
	} while (p != NULL);
}
