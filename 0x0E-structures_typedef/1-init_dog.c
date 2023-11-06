#include "dog.h"

/**
 * init_dog - initializes a structure of type dog
 * @d: The pointer to structure
 * @name: The pointer to the name of the dog
 * @age: The age of dog
 * @owner: The pointer to owner of dog
 *
 * Return: void(nothing)
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
