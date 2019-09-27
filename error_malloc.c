#include "monty.h"
/**
 * error_malloc - prints the error when malloc fails
 * @stack: a double linked list
 */
void error_malloc(stack_t **stack, char *opc, char *arg, char *end)
{
	free_stack(stack);
	if (global)
	{
		if (global[0])
			free(global[0]);
		if (global[1])
			free(global[1]);
		if (global[2])
			free(global[2]);
		free(global);
	}
	if (opc)
		free(opc);
	if (arg)
		free(arg);
	if (end)
		free(end);
	fprintf(stderr, "Error: malloc failed");
	exit(EXIT_FAILURE);
}
