#include "monty.h"
/**
 * _getopc - function that push an unteger to the stack
 * @fd: file to process
 * Return: the opcode and the argument
 */
char **_getopc(int fd)
{
	int i = 0, size = 100, fl = 1, inw = 0, cont = 0;
	char *opc = NULL, *arg = NULL, *end = NULL;
	char **l = NULL;
	char c = 0;

	opc = malloc(size);
	arg = malloc(size);
	end = malloc(1);
	l = (char **)malloc(sizeof(char **) * 3);
	if (opc == NULL || arg == NULL || end == NULL || l == NULL)
		error_malloc();
	end[0] = '0';
	for (; i < size; opc[i] = 0, arg[i] = 0, i++)
		;
	for (l[0] = opc, l[1] = arg, l[2] = end, i = 0; fl; i++)
	{
		read(fd, &c, 1);
		if (c == '\n' || c == EOF || c == 0)
		{
			if (c == EOF || c == 0)
				end[0] = '1';
			return (l);
		}
		if (c == ' ' || c == '\t')
		{
			i = -1;
			if (inw)
			{
				inw = 0;
				cont++;
			}
		}
		else
			inw = 1;
		if (inw && cont == 0)
			opc[i] = c;
		if (inw && cont == 1)
			arg[i] = c;
	}
	return (l);
}
