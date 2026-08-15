#include <stdlib.h>
#include <string.h>
#include "session.h"

session_t *session_create(const char *id, unsigned int uid, const unsigned char *data, size_t data_len)
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
	sess->uid = uid;

	if (data && data_len > 0)
	{
		sess->data = malloc(data_len);
		if (!sess->data)
		{
			free(sess->id);
			free(sess);
			return (NULL);
		}
		memcpy(sess->data, data, data_len);
		sess->data_len = data_len;
	}
	else
	{
		sess->data = NULL;
		sess->data_len = 0;
	}

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
	if (sess->data)
	{
		free(sess->data);
		sess->data = NULL;
	}
	free(sess);
}

int session_update(session_t *sess, const unsigned char *data, size_t data_len)
{
	unsigned char *new_data;

	if (!sess)
		return (0);

	if (data && data_len > 0)
	{
		new_data = malloc(data_len);
		if (!new_data)
			return (0);
		memcpy(new_data, data, data_len);
		if (sess->data)
			free(sess->data);
		sess->data = new_data;
		sess->data_len = data_len;
	}
	else
	{
		if (sess->data)
			free(sess->data);
		sess->data = NULL;
		sess->data_len = 0;
	}

	return (1);
}

int session_set_data(session_t *sess, const unsigned char *data, size_t data_len)
{
	return (session_update(sess, data, data_len));
}
