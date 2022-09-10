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

	file = argv[1];
	if (argc != 2)
	{
		ex_code = errors(linecount, fname, tokens, 0);
		return (EXIT_FAILURE);
	}
	fd = fopen(file, "r");
	if (fd == NULL)
	{
		ex_code = errors(linecount, fname, tokens, 1);
		free(fd);
		return (EXIT_FAILURE);
	}
	while ((getline(&buff, &n, fd)) != EOF)
	{
		linecount++;
		if (buff == NULL || (if_empty_line(buff)) != 0)
			continue;
		tokens = _strtok(buff);
		if (tokens)
		{
			ex_code = _monty(&stack, linecount, tokens);
			if  (ex_code == EXIT_SUCCESS)
				continue;
			else if (ex_code == 15)
				ex_code = errors(linecount, fname, tokens, 2);
			break;
		}
		errors(linecount, fname, tokens, -1);
		break;
	}
	clean(fd, tokens, buff, &stack);
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
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	return (EXIT_FAILURE);
}
/**
* clean - cleans the interpreter
* @stack: pointer to stack
* @fd: file stream
* @tokens: double array
* @buff: buffer to be freed
* Return: void
*/
void clean(FILE *fd, char **tokens, char *buff, stack_t **stack)
{
	free_stack(stack);
	free_array(tokens);
	free(buff);
	fclose(fd);
}
