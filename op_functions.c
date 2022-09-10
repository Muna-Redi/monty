#include "monty.h"
#include <string.h>

/**
* op_push - this pushes an integer on to the stack
* @stack: the stack
* @tokens: an array containing integer value
* @linecount: file line number
* Return: void
*/
int op_push(stack_t **stack, char **tokens, unsigned int linecount)
{
	stack_t *new;
	int i = 0, num;
	char *value;

	value = tokens[1];
	if (!value)
	{
		fprintf(stderr, "L%d: usage: push integer\n", linecount);
		free_stack(stack);
		return (EXIT_FAILURE);
	}
	while (value[i])
	{
		if (value[0] == '-')
		{
			i++;
			continue;
		}
		if ((value[i] < '0') || (value[i] > '9'))
		{
			fprintf(stderr, "L%d: usage: push integer\n", linecount);
			free_stack(stack);
			return (EXIT_FAILURE);
		}
		i++;
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		free(new);
	if (!new)
		return (0);
	num = atoi(value);
	new->prev = NULL;
	new->n = num;
	if (*stack || stack)
		new->next = *stack;
	else
		new->next = NULL;
	*stack = new;
	return (5);
}

/**
* op_pall - this prints all value in the stack
* @stack: the stack
* @linecount: file line number
* Return: void
*/
void op_pall(stack_t **stack, __attribute__((unused))unsigned int linecount)
{
	stack_t *tmp = NULL;

	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
* op_pint - this prints the value at the top of the stack
* @stack: the stack
* @linecount: file line number
* Return: void
*/
void op_pint(stack_t **stack, unsigned int linecount)
{

	stack_t *tmp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", linecount);
		free_stack(stack);
	}
	else
	{
		tmp = *stack;
		printf("%d\n", tmp->n);
	}
}
