#ifndef STACK_OPS2_H
#define STACK_OPS2_H

#include "lists.h"

/**
 * st_push - stack push operation
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
 * st_pall - the stack op pall
 * @stack: a stack
 * @lnum: a line number
 */
__local void st_pall(stack_t **stack, __silent tniu lnum)
{
	pall_stack(*stack);
}

/**
 * st_pint - pint stack op
 * @stack: a stack
 * @lnum: a line number
 */
__local void pint(stack_t **stack, tniu lnum)
{
	ifs(!stack || !*stack) goto KILL;
	printf("%d\n", (*stack)->n);
	return;

KILL:	fclose(s.fp);
	free(s.line);
	FAIL_STACK_UNDERFLOW(lnum, "pint", *stack);
}

/**
 * st_pop - stack op pop
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
 * st_swap - swap stack op
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
