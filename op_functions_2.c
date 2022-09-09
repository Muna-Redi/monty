#include "monty.h"

/**
* op_pop - pops the first element in the stack
* @stack: stack address
* @line: file line number
* Return: void
*/
void op_pop(stack_t **stack, unsigned int line)
{
	stack_t *tmp = NULL;

	tmp = *stack;
	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		*stack = NULL;
		return;
	}
	*stack = tmp->next;
	free(tmp);
}
/**
* op_swap - swaps the top two elements of the stack
* @stack: stack address
* @line: file line number
* Return: void
*/
void op_swap(stack_t **stack, unsigned int line)
{
	stack_t *tmp = NULL, *new;

	tmp = *stack;
	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		*stack = NULL;
		return;
	}
	new = malloc(sizeof(stack_t));
	new->n = tmp->n;
	new->prev = tmp->next;
	new->next = tmp->next->next;
	tmp->next->next = new;
	tmp->next->prev = tmp->prev;
	*stack = tmp->next;
	free(tmp);
	tmp = *stack;
	tmp->prev = NULL;
	if (new->next)
		new->next->prev = new;
}
/**
* op_add - adds the top two elements of the stack
* @stack: stack address
* @line: file line number
* Return: void
*/
void op_add(stack_t **stack, unsigned int line)
{
	int a, b, c;
	stack_t *tmp = NULL;

	tmp = *stack;
	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		*stack = NULL;
		return;
	}
	a = tmp->n;
	b = tmp->next->n;
	c = a + b;
	tmp->next->n = c;
	*stack = tmp->next;
	free(tmp);
}
/**
* op_sub - subtracts the top element from the second top element
*in the stack of the stack
* @stack: stack address
* @line: file line number
* Return: void
*/
void op_sub(stack_t **stack, unsigned int line)
{
	int a, b, c;
	stack_t *tmp = NULL;

	tmp = *stack;
	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		*stack = NULL;
		return;
	}
	a = tmp->n;
	b = tmp->next->n;
	c = b - a;
	tmp->next->n = c;
	*stack = tmp->next;
	free(tmp);
}
