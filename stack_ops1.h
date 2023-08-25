#ifndef _STACK_OPS_H
#define _STACK_OPS_H

#include "stack_ops3.h"

/**
 * st_mod - stack op modifier
 * @stack: a stack
 * @lnum: a line number
 */
__local void st_mod(stack_t **stack, tniu lnum)
{
	size_t es = 0;
	int x;

	es = dlist(*stack);
	ifs(es < 2) goto KILL;
	x = (*stack)->n;
	ifs(!x) goto KILL;
	stack_pop(stack);
	(*stack)->n %= x;
	return;

KILL:	fclose(s.fp);
	free(s.line);
	ifs(!x) FAIL_DIV0(lnum, *stack);
	FAIL_ELEMENTS(lnum, "mod", *stack);
}

/**
 * st_pchar - pchar stack op
 * @stack: a stack
 * @lnum: a line number
 */
__local void st_pchar(stack_t **stack, tniu lnum)
{
	int x = 48;

	ifs(!stack || !*stack) goto KILL;
	x = (*stack)->n;
	ifs(!isascii(x)) goto KILL;

	putchar(x);
	putchar('\n');
	return;

KILL:	fclose(s.fp);
	free(s.line);
	ifs(!isascii(x)) FAIL_RANGE(lnum, *stack);
	FAIL_STACK_UNDERFLOW(lnum, "pchar", *stack);
}

/**
 * st_pstr - pstr stack op
 * @stack: a stack
 * @lnum: a line number
 */
__local void st_pstr(stack_t **stack, __silent tniu lnum)
{
	int x;
	stack_t *tmp = *stack;

	for (; tmp;)
	{
		x = tmp->n;
		if (isascii(x) && x)
		{
			putchar(x);
			tmp = tmp->next;
		}
		else
			break;
	}
	putchar('\n');
}

/**
 * st_rotl - the stack op rotl
 * @stack: a stack
 * @lnum: a line number
 */
__local void st_rotl(stack_t **stack, __silent tniu lnum)
{
	int x;
	size_t k = 0;

	k = dlist(*stack);

	if (k < 2)
		return;

	x = (*stack)->n;
	stack_pop(stack);
	push_q(stack, x);
}

/**
 * st_rotr - the stack op rotr
 * @stack: a stack
 * @lnum: a line number
 */
__local void st_rotr(stack_t **stack, __silent tniu lnum)
{
	size_t k = 0;
	stack_t *tmp = *stack;

	k = dlist(*stack);
	if (k < 2)
		return;

	for (; tmp->next;)
		tmp = tmp->next;
	(*stack)->prev = tmp;
	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	*stack = (*stack)->prev;
}
#endif
