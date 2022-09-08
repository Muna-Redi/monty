#include "monty.h"

/**
* main - Entry point of the program
* @argc: argument count
* @argv: variable arguments to main
* Description: interprete for the monty bytecodes
* Return: 0 success
*/
int main(int argc, char **argv)
{
	FILE *fd;
	const char *file;
	size_t n = 0;
	char *buff = NULL, **tokens = NULL, *fname = argv[1];
	stack_t *stack = NULL;
	unsigned int linecount = 0, ex_code = EXIT_SUCCESS;

	if (argc != 2)
	{
		ex_code = errors(linecount, fname, tokens, 0);
	}
	file = argv[1];
	fd = fopen(file, "r");
	if (fd == NULL)
	{
		ex_code = errors(linecount, fname, tokens, 1);
	}
	while ((getline(&buff, &n, fd)) != EOF)
	{
		linecount++;
		if (buff == NULL || (if_empty_line(buff)) != 0)
			continue;
		tokens = tokenize(buff);
		if (tokens)
		{
			if ((_monty(&stack, linecount, tokens) == 0))
				continue;
			ex_code = errors(linecount, fname, tokens, 2);
			break;
		}
		else
		{
			ex_code = errors(linecount, fname, tokens, -1);
			break;
		}
	}
	free_stack(&stack);
	free_array(tokens);
	fclose(fd);
	return (ex_code);
}
/**
* errors - prints error messages
* @fname: name of file
* @line: file line number
* @tokens: opcode instruction array
* @f: flag
* Return: void
*/
int errors(unsigned int line, char *fname, char **tokens, int f)
{
	if (f == 0)
		fprintf(stderr, "USAGE: monty file\n");

	else if (f == 1)
		fprintf(stderr, "Error: Can't open file %s\n", fname);

	else if (f == 2)
		fprintf(stderr, "L%d: unknown instruction %s\n", line, tokens[0]);
	else if (f == -1)
		fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}
