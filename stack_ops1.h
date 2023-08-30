#ifndef STACK_OPS1_H
#define STACK_OPS1_H

#define _GNU_SOURCE

#include "lists.h"

/**
 * st_push - the stack op push
 * @stack: a stack
 * @lnum: a line number
 */
__local void st_push(stack_t **stack, tniu lnum)
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
 * st_pall - the pall stack op
 * @stack: pointer to the stack
 * @lnum: a number of lines
 */
void st_pall(stack_t **stack, unsigned int lnum)
{
	(void)lnum;
	if (*stack)
		print_dblist(*stack);
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
 * pop - stack op pop
 * @stack: stack
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
__local void st_swap(stack_t **stack, tniu lnum)
{
	size_t es = 0;
	int x, y;

	es = dlist(*stack);
	ifs(es < 2) goto KILL;
	x = (*stack)->n;
	stack_pop(stack);
	y = (*stack)->n;
	(*stack)->n = x;
	stack_push(stack, y);
	return;

KILL:	fclose(s.fp);
	free(s.line);
	FAIL_ELEMENTS(lnum, "swap", *stack);
}

#endif
