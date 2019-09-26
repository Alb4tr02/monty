#include "monty.h"
void free_stack(stack_t **head)
{
	stack_t *cpy = NULL;
	stack_t *aux = NULL;
	if (*head == NULL)
		return;
	cpy = *head;
	while (cpy)
	{
		aux = cpy->prev;
		free(cpy);
		cpy = aux;
	}
}
