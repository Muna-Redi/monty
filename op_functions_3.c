#include "monty.h"

/**
* op_div - subtracts the second top element of the stack by the second
*top element in the stack
* @stack: stack address
* @line: file line number
* Return: void
*/
void op_div(stack_t **stack, unsigned int line)
{
	int a, b, c;
	stack_t *tmp = NULL;

	tmp = *stack;
	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line);
		*stack = NULL;
		return;
	}
	a = tmp->n;
	b = tmp->next->n;
	if (a == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		free_stack(stack);
		return;
	}
	c = b / a;
	tmp->next->n = c;
	*stack = tmp->next;
	free(tmp);
}
/**
* op_mul - multiplies the second top element of the stack with the
*top element in the stack
* @stack: stack address
* @line: file line number
* Return: void
*/
void op_mul(stack_t **stack, unsigned int line)
{
	int a, b, c;
	stack_t *tmp = NULL;

	tmp = *stack;
	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line);
		*stack = NULL;
		return;
	}
	a = tmp->n;
	b = tmp->next->n;
	c = b * a;
	tmp->next->n = c;
	*stack = tmp->next;
	free(tmp);
}
/**
* op_mod - computes the rest of the divsion of the second top element
*of the stack with the top element of the stack
* @stack: stack address
* @line: file line number
* Return: void
*/
void op_mod(stack_t **stack, unsigned int line)
{
	int a, b, c;
	stack_t *tmp = NULL;

	tmp = *stack;
	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line);
		*stack = NULL;
		return;
	}
	a = tmp->n;
	b = tmp->next->n;
	if (a == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		free_stack(stack);
		return;
	}
	c = b % a;
	tmp->next->n = c;
	*stack = tmp->next;
	free(tmp);
}
/**
* op_pchar - prints the char at the top of the stack
* @stack: stack address
* @line: file line number
* Return: void
*/
void op_pchar(stack_t **stack, unsigned int line)
{
	stack_t *tmp = NULL;

	tmp = *stack;
	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		*stack = NULL;
		return;
	}
	if (tmp->n < 0 || tmp->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
		free_stack(stack);
		return;
	}
	printf("%c\n", tmp->n);
}
/**
* op_pstr - prints string starting from the top of the stack
* @stack: stack address
* @line: file line number
* Return: void
*/
void op_pstr(stack_t **stack, __attribute__((unused))unsigned int line)
{
	stack_t *tmp = NULL;

	tmp = *stack;
	if (tmp == NULL)
	{
		printf("\n");
		return;
	}
	while (tmp)
	{
		if (tmp->n <= 0 || tmp->n > 127)
		{
			printf("\n");
			return;
		}
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}
