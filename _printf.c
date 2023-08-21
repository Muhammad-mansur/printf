#include "main.h"

/**
  */

int _printf(const char *format, ...)
{
	/* To keep track of the number of characters printed */
	int cnt = 0, c, s;
	const char *p;

	va_list arg;

	va_start(arg, format);

	for (p = format; *p != '\0'; p++)
	{
		if (*p != '%')
		{
			_putchr(*p);
			cnt++;
		}

		if (*p == 'c')
		{
			/* Fetch a character and store it in c var */
			c = va_arg(arg, int);
			_putchr(c);
			cnt++;
		}

		else if (*p == 's')
		{
			/* Fetch a string and assign it to a char var */
			s = va_arg(arg, int);
			for (s = 0; s != '\0'; s++)
			{
				_putchr(s);
			}
			cnt++;
		}

		else if(*p == '%')
		{
			_putchr('%');
			cnt++;
		}

		else
		{
			_putchr('%');
			_putchr(*p);
			cnt += 2;
		}
	}

	va_end(arg);

	return (*p);
}
