#include <stdlib.h>
#include <string.h>
#include "store.h"

void store_clear(store_t *store)
{
	node_t *current;
	node_t *next;

	if (!store)
		return;

	current = store->head;
	while (current)
	{
		next = current->next;
		if (current->sess)
		{
			session_destroy(current->sess);
		}
		free(current);
		current = next;
	}
	store->head = NULL;
}

void store_init(store_t *store)
{
	if (!store)
		return;
	store->head = NULL;
}

void store_destroy(store_t *store)
{
	if (!store)
		return;
	store_clear(store);
	free(store);
}

int store_add(store_t *store, session_t *session)
{
	node_t *new_node;

	if (!store || !session)
		return (0);

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (0);

	new_node->sess = session;
	new_node->next = store->head;
	store->head = new_node;

	return (1);
}

session_t *store_get(store_t *store, const char *id)
{
	node_t *current;

	if (!store || !id)
	{
		return (NULL);
	}

	current = store->head;
	while (current)
	{
		if (current->sess && current->sess->id &&
		    strcmp(current->sess->id, id) == 0)
		{
			return (current->sess);
		}
		current = current->next;
	}

	return (NULL);
}

int store_delete(store_t *st, const char *id, session_t **out)
{
	node_t *current;
	node_t *prev = NULL;

	if (!st || !id)
	{
		if (out)
			*out = NULL;
		return (0);
	}

	current = st->head;
	while (current)
	{
		if (current->sess && current->sess->id &&
		    strcmp(current->sess->id, id) == 0)
		{
			if (prev)
			{
				prev->next = current->next;
			}
			else
			{
				st->head = current->next;
			}

			if (out)
			{
				*out = current->sess;
			}
			else
			{
				if (current->sess)
				{
					session_destroy(current->sess);
				}
			}
			free(current);
			return (1);
		}
		prev = current;
		current = current->next;
	}

	if (out)
		*out = NULL;
	return (0);
}
