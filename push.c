#include "monty.h"
/**
 * push - function that push an unteger to the stack
 * @stack: a double linked list
 * @line_number: number of line in code to print error message.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int i = 0, number;

	for (; global[1][i] != '\0'; i++)
		if (isdigit(num[i] == 0))
			break;
	if (isdigit(num[i] == 0) || num == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}
	number = atoi(global[1]);
	new = malloc(stack_t);
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new->n = number;
	new->next = NULL;
	if (stack == NULL)
		new->prev = NULL;
	else
		new->prev = stack;
	stack = new;
	return (stack);
}
