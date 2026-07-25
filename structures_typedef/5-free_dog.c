#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - Frees a dog structure
 * @d: Pointer to the dog_t to free
 *
 * Description: Frees the memory allocated for the dog's name,
 * owner, and the dog structure itself if it is not NULL.
 */
void free_dog(dog_t *d)
{
	if (d == NULL)
		return;

	free(d->name);
	free(d->owner);
	free(d);
}

