#include "monty.h"
/**
 * pstr_t - function that prints the string on the stack
 * @stack: a double linked list
 * @line_number: number of line in code to print error message.
 */
void pstr_t(stack_t **stack, unsigned int line_number)
{
	stack_t *p;

	p = *stack;
	if (p == NULL)
	{
		free_stack(stack);
		free(global[0]);
		free(global[1]);
		free(global[2]);
		free(global);
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (p != NULL)
	{
		if (p->n < 1 || p->n > 127)
			break;
		printf("%c", (char)(p->n));
		p = p->prev;
	}
	putchar('\n');
}
