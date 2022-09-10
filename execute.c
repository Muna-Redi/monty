#include "monty.h"

/**
* op_func - gets the required opcode function
* @mcode: opcode instruction
* Return: int
*/
void (*op_func(const char *mcode))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{"rotl", op_rotl},
		{"rotr", op_rotr},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].opcode)
	{
		if (strcmp(mcode, ops[i].opcode) == 0)
		{
			break;
		}
		i++;
	}
	return (ops[i].f);
}
/**
* _monty - finds and performs the given instruction
* @stack: the stack address
* @linecount: file line number
* @tokens: array of tokens
* Return: void
*/
int  _monty(stack_t **stack, unsigned int linecount, char **tokens)
{
	void (*fp)(stack_t **stack, unsigned int line_number);
	const char *mcode;
	int n = 0;

	mcode = tokens[0];
	if (strcmp(mcode, "nop") == 0 || (mcode[0] == '#'))
		return (EXIT_SUCCESS);
	if (strcmp(mcode, "push") == 0)
	{
		n = op_push(stack, tokens, linecount);
		if (n == 5)
			return (EXIT_SUCCESS);
		else if (n == 0)
			fprintf(stderr, "Error: malloc failed\n");
		return (EXIT_FAILURE);
	}
	fp = op_func(mcode);
	if (fp != NULL)
	{
		fp(stack, linecount);
		if (*stack == NULL && (fp != op_pstr) && (fp != op_pall))
			return (EXIT_FAILURE);
		else
			return (EXIT_SUCCESS);
	}
	else if (fp == NULL)
		return (15);
	return (n);
}
