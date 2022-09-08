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
	char *buff = NULL, **tokens = NULL;
	stack_t *stack = NULL;
	unsigned int linecount = 0;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = argv[1];
	fd = fopen(file, "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((getline(&buff, &n, fd)) != EOF)
	{
		linecount++;
		if (buff == NULL || (if_empty_line(buff)) != 0)
			continue;
		tokens = tokenize(buff);
		if (tokens)
		{
			_monty(&stack, linecount, tokens);
			continue;
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", linecount, tokens[0]);
			fclose(fd);
			exit(EXIT_FAILURE);
		}
	}
	free_stack(&stack);
	free_array(tokens);
	fclose(fd);
	return (EXIT_SUCCESS);
}
/**
* _error - prints error messages
* @c: error specifier
* @filename: name of file
* @linecount: file line number
* @command: opcode instruction
* Return: void
*/
