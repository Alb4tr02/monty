#include "monty.h"
/**
 * error_malloc - prints the error when malloc fails
 * @stack: a double linked list
 */
void error_malloc(stack_t **stack)
{
	free_stack(stack);
	free(global[0]);
	free(global[1]);
	free(global[2]);
	free(global);
	fprintf(stderr, "Error: malloc failed");
	exit(EXIT_FAILURE);
}
