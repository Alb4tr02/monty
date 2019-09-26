#include "monty.h"
/**
 * error_malloc - prints the error when malloc fails
 */
void error_malloc(void)
{
	fprintf(stderr, "Error: malloc failed");
	exit(EXIT_FAILURE);
}
