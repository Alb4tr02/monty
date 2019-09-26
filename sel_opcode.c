#include "monty.h"

/**
 * sel_opcode - Select the opcode to use.
 * @stack: type pointer node of data struct
 * @line: line of instructions
 * Return: Retunr the funtion
 */
int *sel_opcode(stack_t **stack, unsigned int line)
{
	instruction_t op[] = {
		{ "push", push }, { "pall", pall}, { "pop", pop },
		{ "add", add }, { "nop", nop }, { "sub", sub },
		{ "pint", pint }, { "swap", swap },
		{ "mul", mul }, { "div", div_m }, { "pchar", pchar },
		{ "mod", mod_m }, { "\n", nop }, { " ", nop },
		{ "/t", nop }, { "pstr", pstr_t }, { NULL, NULL }
	};
	int flag = 0, i = 0;

	if (stack == NULL || opcode == NULL)
		return (0);
	while (op[i].opcode != NULL)
	{
		if (strcmp(global, op[i].opcode) == 0)
		{
			flag = 1;
			op_built[i].f(stack, line);
			break;
		}
	}
	if (flag == 0)
		stderr_unknown(token, line_number);
	return (0);
}
