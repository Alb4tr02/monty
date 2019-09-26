#include "monty.h"
/**
 * push - function that push an unteger to the stack
 * @stack: a double linked list
 * @line: number of line in code to print error message.
 * @num: integer to add.
 * Return: the stack with new element
 */
stack_t *push(stack_t **stack, unsigned int line_number);
{
	stack_t *new;
	int i = 0;

	for (; num[i] != '\0'; i++)
		if (isdigit(num[i] == 0))
			break;
	if (isdigit(num[i] == 0) || num == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}
	new = malloc(stack_t);
	if (new == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
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
