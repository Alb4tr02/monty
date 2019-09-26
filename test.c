#include "monty.h"
/**
 * main - process Monty languaje
 * @argc: number of arguments
 * @argv: array of arguments
 * Returns: 0 on success
 */
char **global = NULL;
int main(int argc, char *argv[])
{
	int fd = 0;
	unsigned int line = 0;
	char **l = NULL;
	char *fname = NULL;
	stack_t *st = NULL;
	stack_t **stack = &st;
	(void)argc;

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
	close(fd);
	return (0);
}
