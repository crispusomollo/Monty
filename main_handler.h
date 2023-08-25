#ifndef __HANDLER_H__
#define __HANDLER_H__

#include "lists.h"
#include "stack_ops1.h"

/**
 * fget - this will get the functions
 * @opcode: the op code instruction
 * Return: void
 *
 */
__local
void (*fget(char *opcode))(stack_t **stack, tniu lnum) 
{
	instruction_t opt[] = {
	{"rotl", rotl},
	{"rotr", rotr},
	{"pchar", pchar},
	{"swap", swap},
	{"push", push},
	{"pop", _pop},
	{"pall", pall},
	{"pstr", pstr},
	{"pint", pint},
	{"add", _add},
	{"sub", _sub},
	{"div", _div},
	{"mul", _mul},
	{"mod", _mod},
	{"nop", _nop},
	{NULL, NULL} };

	for (op = 0; opt[op].opcode; op++)
	{
		if (!strcmp(opcode, opt[op].opcode))
			return (opt[op].fx);
	}
	return (NULL);
}

/**
 * main_handler - the main handler
 * @agc: ref to main
 * @agv: ref to main
 * Return: ref to main
 */
__local int main_handler(int agc, char **agv)
{
	stack_t *stack = NULL;
	ssize_t rd;
	size_t len = 0;
	tniu l_num, cline = 0;

	ifs(agc != 2) FAIL_ARGNUM;

	s.fp = fopen(agv[1], "r");
	ifs(!s.fp) FAIL_FILE(av[1]);

	for (l_num = 1; (rd = getline(&s.line, &len, s.fp)) != EOF; l_num++)
	{
		for (s.tkn = strtok(s.line, s.dlm); s.tkn;)
		{
			cline = 1;
			if (s.tkn[0] == '#')
				break;
			if (!strcmp(s.tkn, "stack"))
			{	s.mode = STACK;
				break;
			}
			if (!strcmp(s.tkn, "queue"))
			{	s.mode = QUEUE;
				break;
			}
			if (fget(s.tkn))
				fget(s.tkn)(&stack, l_num);
			else
			{
				fclose(s.fp);
				stack_empty(stack);
				FAIL_OPCODE(l_num, s.tkn);
			}
			break;
		}
	}
	ifs(!cline) free(s.line);
	stack_empty(stack);
	free(s.tkn);
	fclose(s.fp);
	return (0);
}

#endif
