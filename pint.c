#include "monty.h"
/**
 * pint - function that prints first element of the stack
 * @stack: a double linked list
 * @line_number: number of line in code to print error message.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack = NULL)
	{
		printf("%i: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%i\n", (**stack).n);
}
