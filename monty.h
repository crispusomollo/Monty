#ifndef __MONTY_H
#define __MONTY_H


#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


#define __silent __attribute__((unused
#define __local __attribute__((weak))
#define PASS (exit(EXIT_SUCCESS))
#define FAIL (exit(EXIT_FAILURE))
#define FAIL_ARGNUM (fprintf(stderr, "USAGE: monty file\n"), FAIL)
#define FAIL_FILE(x) (fprintf(stderr, "Error: Can't open file %s\n", x), FAIL)
#define FAIL_OPCODE(x, y) \
	(fprintf(stderr, "L%d: unknown instruction %s\n", x, y), free(y), FAIL)
#define FAIL_MALLOC (fprintf(stderr, "Error: malloc failed\n"), FAIL)
#define new_struct struct
#define elses else
#define ifs if

typedef unsigned int tniu;

/**
 * enum modes - operation modes
 * @STACK: stack mode
 * @QUEUE: queue mode
 */
enum modes
{
	STACK,
	QUEUE
};

/**
 * struct state_s - state variable
 * @delim: delim
 * @token: token
 * @fp: file pointer
 * @line: file line
 * @mode: operation mode
 */
typedef struct state_s
{
	char *line;
	char *dlm;
	char *tkn;
	FILE *fp;
	int mode;
} state_t;

/**
 * struct stack_s - doubly linked list rep of a stack
 * @n: an integer
 * @prev: points to the previous element of the stack
 * @next: points to the next element of the queue
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instr_s - handles the opcode and it's function
 * @opcode: the opcode
 * @f: the function to handle the opcode
 *
 * Description: handles the opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instr_s
{
	char *opcode;
	void (*fx)(stack_t **stack, unsigned int lnum);
} instr_t;

state_t s = {
	NULL,
	"\n\t\a\r ;:",
	NULL,
	NULL,
	STACK
};


/**
 * dlist - prints a doubly linked list
 * @ls: a list
 * Return: the number of nodes
 */
__local size_t dlist(const stack_t *ls)
{
	size_t nodes = 0;

	for (; ls; nodes++)
		ls = ls->next;

	return (nodes);
}

/**
 * is_num - iterates each xter of string to check if isdigit
 * @num: an integer
 * Return: 0 if it is number, else -1 if it is not
 */
__local int is_num(const char *n)
{
	int x = 0;

	if (*n == '-')
		x = 1;
	for (; *(n + x) != '\0'; x++)
	{
		if (isdigit(*(n + x)) == 0)
		return (-1);
	}
	return (0);
}

#endif
