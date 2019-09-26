#include "monty.h"

/**
 * sel_opcode - Select the opcode to use.
 * @stack: type pointer node of data struct
 * @line: line of instructions
 * Return: Retunr the funtion
 */
int sel_opcode(stack_t **stack, unsigned int line)
{
	instruction_t op[] = {
		{ "push", push }, { "pall", pall}, { "pop", pop },
		{ "add", add }, { "nop", nop }, { "sub", sub },
		{ "pint", pint }, { "swap", swap },
		{ "mul", mul }, { "div", div_m }, { "pchar", _pchar},
		{ "mod", mod_m }, { "\n", nop }, { " ", nop },
		{ "/t", nop }, { "pstr", pstr_t }, { NULL, NULL }
	};
	int i = 0;

	if (stack == NULL || global[1] == NULL)
		return (0);
	while (op[i].opcode != NULL)
	{
		if (strcmp(global[1], op[i].opcode) == 0)
		{
			op[i].f(stack, line);
			break;
		}
	}
	return(0);
}
