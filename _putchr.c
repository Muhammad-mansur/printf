#include "main.h"

/**
  * _putchr - writes character c to stdout
  * @c: character to be printed
  *
  * Returm: 1
  */

int _putchr(char c)
{
	return (write(1, &c, 1));
}
