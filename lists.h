#ifndef LISTS_H
#define LISTS_H

#include "monty.h"

/**
 * stack_push - add a node to the head of a list
 * @hd: a pointer to the head
 * @n: a new node to add
 * Return: new list
 */
__local stack_t *stack_push(stack_t **hd, const int n)
{
	stack_t *new;

	if (!hd)
		return (NULL);

	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	new->next = *hd;
	if (*hd)
		(*hd)->prev = new;
	*hd = new;

	return (new);
}

/**
 * free_dblist - Frees a linked stack_t list.
 * @hd: The head of the stack_t list.
 */
__local void empty_stack(stack_t *hd)
{
	stack_t *tmp;

	while (hd)
	{
		tmp = hd->next;
		free(hd);
		hd = tmp;
	}
}

/**
 * stack_pop - deletes node at end of doubly linked list
 * @hd: pointer to head of doubly linked list
 */
void stack_pop(stack_t **hd)
{
	stack_t *rm = NULL;

	rm = *hd;
	if ((*hd)->next == NULL)
	{
		*hd = NULL;
		free(rm);
	}
	else
	{
		*hd = (*hd)->next;
		(*hd)->prev = NULL;
		free(rm);
	}
}

/**
 * print_dblist - print doubly linked list
 * @ls: alist
 * Return: number of nodes
 */
__local size_t pall_stack(const stack_t *ls)
{
	size_t nodes = 0;

	for (; ls; nodes++, ls = ls->next)
		printf("%d\n", ls->n);

	return (nodes);
}

/**
 * push_q - adds a new node to the end of a list
 * @hd: pointer to the list head
 * @n: integer for the new node
 *
 * Return: If the function fails - NULL.
 *	Otherwise - the address of the new node.
 */
__local stack_t *push_q(stack_t **hd, const int n)
{
	stack_t *new, *end;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*hd == NULL)
	{
		new->prev = NULL;
		*hd = new;
		return (new);
	}

	end = *hd;
	while (end->next != NULL)
		end = end->next;
	end->next = new;
	new->prev = end;

	return (new);
}

#define FAIL_INT(p, q) \
	(fprintf(stderr, "L%u: usage: push integer\n", p), \
	 empty_stack(q), FAIL)

#define FAIL_STACK_UNDERFLOW(p, q, r) \
	(fprintf(stderr, "L%u: can't %s, stack empty\n", p, q), \
	 empty_stack(r), FAIL)

#define FAIL_POP(p, q, r) \
	(fprintf(stderr, "L%u: can't %s an empty stack\n", p, q), \
	empty_stack(r), FAIL)

#define FAIL_ELEMENTS(p, q, r) \
	(fprintf(stderr, "L%u: can't %s, stack too short\n", p, q), \
	 empty_stack(r), FAIL)

#define FAIL_DIV0(p, q) \
	(fprintf(stderr, "L%u: division by zero\n", p), \
	empty_stack(q), FAIL)

#define FAIL_RANGE(p, q) \
	(fprintf(stderr, "L%u: can't pchar, value out of range\n", p), \
	empty_stack(q), FAIL)

#endif
