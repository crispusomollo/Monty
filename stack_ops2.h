#ifndef STACK_OPS2_H
#define STACK_OPS2_H

#define _GNU_SOURCE

#include "lists.h"

/**
 * st_push - the stack op push
 * @stack: a stack
 * @lnum: line number
 */
__local void push(stack_t **stack, tniu lnum)
{
	s.tkn = strtok(NULL, s.dlm);
	ifs(!s.tkn) goto KILL;
	ifs(is_num(s.tkn) == EOF) goto KILL;
	if (s.mode == STACK)
		stack_push(stack, atoi(s.tkn));
	else
		push_q(stack, atoi(s.tkn));
	return;

KILL:
	fclose(s.fp);
	free(s.line);
	FAIL_INT(lnum, *stack);
}

/**
 * st_pall - prints the value of all items on the stack
 * @stack: a pointer to stack
 * @lnum: a line number
 * Return: void
 */
void st_pall(stack_t **stack, unsigned int __attribute__((unused))lnum)
{
	stack_t *curr = *stack;

	if (stack == NULL || *stack == NULL)
		return;

	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}

/**
 * st_pint - the stack op pint
 * @stack: a stack
 * @lnum: a line number
 */
__local void st_pint(stack_t **stack, tniu lnum)
{
	ifs(!stack || !*stack) goto KILL;
	printf("%d\n", (*stack)->n);
	return;

KILL:	fclose(s.fp);
	free(s.line);
	FAIL_STACK_UNDERFLOW(lnum, "pint", *stack);
}

/**
 * st_pop - the stack op pop
 * @stack: a stack
 * @lnum: a line number
 */
__local void st_pop(stack_t **stack, tniu lnum)
{
	ifs(!stack || !*stack) goto KILL;
	stack_pop(stack);
	return;

KILL:	fclose(s.fp);
	free(s.line);
	FAIL_POP(lnum, "pop", *stack);
}

/**
 * st_swap - the stack op swap
 * @stack: a stack
 * @lnum: a line number
 */
__local void swap(stack_t **stack, tniu lnum)
{
	size_t es = 0;
	int p, q;

	es = dlist(*stack);
	ifs(es < 2) goto KILL;
	p = (*stack)->n;
	stack_pop(stack);
	q = (*stack)->n;
	(*stack)->n = p;
	stack_push(stack, q);
	return;

KILL:	fclose(s.fp);
	free(s.line);
	FAIL_ELEMENTS(lnum, "swap", *stack);
}

#endif
