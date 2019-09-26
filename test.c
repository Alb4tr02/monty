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
	for (l[0] = opc, l[1] = arg, i = 0; fl; i++)
	{
		read(fd, &c, 1);
		if (c == '\n' || c == EOF)
		{
			if (c == EOF)
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
	char *fname = NULL;
	int fd = 0;
	char **l = NULL;

	fname = argv[1];
	fd = open(fname, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n");
		return (-1);
	}
	l = _getopc(fd);
	close(fd);
	printf("%s\n", l[0]);
	printf("%s\n", l[1]);
	free(l[0]);
	free(l[1]);
	free(l);
	//clfy_opc(opc);
	return (0);
}
