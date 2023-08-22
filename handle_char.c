#include "main.h"

/**
 * handle_char - Format specifier for chracters
 * @args: input string
 * Return: A single character
 */

void handle_char(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
}
