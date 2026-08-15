#include <stdlib.h>
#include <string.h>
#include "session.h"

session_t *session_create(const char *id, int data)
{
	session_t *sess;

	if (!id)
		return (NULL);

	sess = malloc(sizeof(*sess));
	if (!sess)
		return (NULL);

	sess->id = strdup(id);
	if (!sess->id)
	{
		free(sess);
		return (NULL);
	}
	sess->data = data;
	return (sess);
}

void session_destroy(session_t *sess)
{
	if (!sess)
		return;

	if (sess->id)
	{
		free(sess->id);
		sess->id = NULL;
	}
	free(sess);
}

int session_update(session_t *sess, int data)
{
	if (!sess)
		return (0);

	sess->data = data;
	return (1);
}
