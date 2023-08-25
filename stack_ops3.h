#ifndef STACK_OPS3_H
#define STACK_OPS3_H

#include "stack_ops2.h"

/**
 * st_add - stack add opearation
 * @stack: a stack
 * @lnum: the line number
 */
__local void st_add(stack_t **stack, tniu lnum)
{
	size_t es = 0;
	int x;

	es = dlist(*stack);
	ifs(es < 2) goto KILL;
	x = (*stack)->n;
	stack_pop(stack);
	(*stack)->n += x;
	return;

KILL:	fclose(s.fp);
	free(s.line);
	FAIL_ELEMENTS(lnum, "add", *stack);
}

/**
 * nop - function that does nothing
 * @stack: a pointer to the stack
 * @lnum: a line number
 * Return: void
 */
void nop(stack_t **stack, tniu lnum)
{
	(void)stack;
	(void)lnum;
}


/**
 * st_sub - a stack sub operation
 * @stack: stack
 * @lnum: line number
 */
__local void st_sub(stack_t **stack, tniu lnum)
{
	size_t es = 0;
	int x;

	es = dlist(*stack);
	ifs(es < 2) goto KILL;
	x = (*stack)->n;
	stack_pop(stack);
	(*stack)->n -= x;
	return;

KILL:	fclose(s.fp);
	free(s.line);
	FAIL_ELEMENTS(lnum, "sub", *stack);
}


/**
 * st_div - a stack div operation
 * @stack: a stack
 * @lnum: a line number
 */
__local void st_div(stack_t **stack, tniu lnum)
{
	size_t es = 0;
	int x;

	es = dlist(*stack);
	ifs(es < 2) goto KILL;
	x = (*stack)->n;
	ifs(!x) goto KILL;
	stack_pop(stack);
	(*stack)->n /= x;
	return;

KILL:	fclose(s.fp);
	free(s.line);
	ifs(!x) FAIL_DIV0(lnum, *stack);
	FAIL_ELEMENTS(lnum, "div", *stack);
}

/**
 * st_mul - a stack mul operation
 * @stack: a stack
 * @lnum: line number
 */
__local void st _mul(stack_t **stack, tniu lnum)
{
	size_t es = 0;
	int x;

	es = dlist(*stack);
	ifs(es < 2) goto KILL;
	x = (*stack)->n;
	stack_pop(stack);
	(*stack)->n *= x;
	return;

KILL:	fclose(s.fp);
	free(s.line);
	FAIL_ELEMENTS(lnum, "mul", *stack);
}

#endif
