#include "monty.h"

/**
 * sel_opcode - Select the opcode to use.
 * @opcode: opcode
 * @stack: type pointer node of data struct
 * @args: argument for opcode
 * @line: line of instructions
 * Return: Retunr the funtion
 */
int *sel_opcode(char *opcode, stack_t **stack, char *args, int line)
{
	instruction_t op[] = {
		{ "push", push }, { "pall", pall}, { "pop", pop },
		{ "add", add }, { "nop", nop }, { "sub", sub },
		{ "pall", pall }, { "pint", pint }, { "swap", swap },
		{ "mul", mul }, { "div", div_m }, { "pchar", pchar },
		{ "mod", mod_m }, { "\n", nop }, { " ", nop },
		{ "/t", nop }, { "pstr", pstr_t }, { NULL, NULL }
	};
	int flag = 0, i = 0;

	if (stack == NULL || opcode == NULL)
		return (0);
	while (op[i].opcode != NULL)
	{
		if (strcmp(opcode, op_built[i].opcode) == 0)
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
