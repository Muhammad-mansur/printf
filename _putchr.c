#include "main.h"

/**
  * _putchr - writes character c to stdout
  * @c: character to be printed
  *
  * Return: 0
  */

int _putchr(char c)
{
	return (write(1, &c, 1));
}
