#include "main.h"

/**
  * _printf - printf function recreation
  * format: string input
  * Return: number of characters printed
  */

int _printf(const char *format, ...)
{
	/* To keep track of the number of characters printed */
	int cnt = 0, c;
	const char *p, *s;

	va_list arg;

	va_start(arg, format);

	for (p = format; *p != '\0'; p++)
	{
		if (*p != '%')
		{
			_putchr(*p);
			cnt++;
		}

		else
		{
			/* Move past '%' */
			p++;

			if (*p == 'c')
			{
				/* fetch a character and store it in c var */
				c = va_arg(arg, int);
				_putchr(c);
				cnt++;
			}
			else if (*p == 's')
			{
				/* Fetch a stringand assign it to a char variable */
				s = va_arg(arg, const char *);
				/* Check for NULL terminator */
				for (; *s != '\0'; s++)
				{
					_putchr(*s);
					cnt++;
				}
			}
			else if (*p == '%')
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
	}

	va_end(arg);

	return (cnt);
}
