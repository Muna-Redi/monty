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
void _monty(stack_t **stack, unsigned int linecount, char **tokens)
{
	void (*fp)(stack_t **stack, unsigned int line_number);
	const char *mcode;
	char *ivalue;

	mcode = tokens[0];
	ivalue = tokens[1];

	if (strcmp(mcode, "push") == 0)
	{
		op_push(stack, ivalue, linecount, tokens);
		return;
	}
	fp = op_func(mcode);
	if (fp)
	{
		fp(stack, linecount);
		return;
	}
	printf("L%d: unknown instruction %s\n", linecount, tokens[0]);
	free_stack(stack);
	free_array(tokens);
	exit(EXIT_FAILURE);
}
