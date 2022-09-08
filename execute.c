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
/*
*		{"pop", op_pop},
*		{"add", op_add},
*		{"sub", op_sub},
*		{"div", op_div},
*		{"mul", op_mul},
*		{"swap", op_swap},
*		{"nop", op_nop},
*		{"mod", op_mod},
*		{"pchar", op_pchar},
*		{"pstr", op_pstr},
*		{"rotl", op_rotl},
*		{"rotr", op_rotr},
*/		{NULL, NULL}
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
	int ex_code = EXIT_FAILURE;

	mcode = tokens[0];
	if (strcmp(mcode, "push") == 0)
	{
		if ((op_push(stack, tokens, linecount)) == 0)
			return (0);
	}
	fp = op_func(mcode);
	if (fp)
	{
		fp(stack, linecount);
		if (linecount == 0)
			return (EXIT_FAILURE);
		else
			return (0);
	}
	return (ex_code);
}
