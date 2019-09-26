#include "monty.h"
char **_getopc(int fd)
{
	int i = 0, size = 100, fl = 1, inw = 0, cont = 0;
	char *opc = NULL;
	char *arg = NULL;
	char *end = NULL;
	char **l = NULL;
	char c = 0;

	opc = malloc(size);
	arg = malloc(size);
	end = malloc(1);
	end[0] = '0';
	l = (char **)malloc(sizeof(char **) * 3);
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
int main(int argc, char *argv[])
{
	int fd = 0;
	unsigned int line = 0;
	char **l = NULL;
	char *fname = NULL;
	char **global = NULL;
	stack_t *st = NULL;
	stack_t **stack = &st;

	global = (char **)malloc(sizeof(char **) * 3);
	fname = argv[1];
	global[0] = fname;
	fd = open(fname, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fname);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		line++;
		l = _getopc(fd);
		global[1] = l[0];
		global[2] = l[1];
		sel_opcode(stack, line);
		free(l[0]);
		free(l[1]);
		if (l[2][0] != '0')
		{
			free(l[2]);
			free(l);
			break;
		}
		free(l[2]);
		free(l);
	}
	free(global);
	//printf("lines: %i\n", line);
	close(fd);
	//clfy_opc(opc);
	return (0);
}
