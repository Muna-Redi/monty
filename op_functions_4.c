#include "monty.h"

/**
 * op_rotl - A function that rotates the stack to the top.
 * @st: The pointer to the stack list.
 * @line_number: The line number of a Monty bytecodes file.
 * Description: The top element of the stack becomes the last one,
 * and the second top element of the stack becomes the first one.
 */
void op_rotl(stack_t **st, __attribute__((unused))unsigned int line_number)
{
	int temp;
	stack_t *pst = *st;

	if (*st)
	{
		temp = pst->n;
		while (pst->next != NULL)
		{
			pst->n = pst->next->n;
			pst = pst->next;
		}
		pst->n = temp;
	}
}
/**
 * op_rotr - A function that rotates the stack to the bottom.
 * @st: The pointer to the stack list.
 * @line_number: The line number of a Monty bytecodes file.
 * Description: The top element of the stack becomes the last one,
 * and the second top element of the stack becomes the first one.
 */
void op_rotr(stack_t **st, __attribute__((unused))unsigned int line_number)
{
	int temp;
	stack_t *pst = *st;

	if (*st)
	{
		temp = pst->n;
		while (pst->next)
			pst = pst->next;

		while (pst->prev != NULL)
		{
			pst->n = pst->prev->n;
			pst = pst->prev;
		}
		pst->n = temp;
	}
}

