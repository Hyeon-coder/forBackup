/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <ljh3900@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:20:32 by JuHyeon           #+#    #+#             */
/*   Updated: 2024/11/18 14:31:26 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putchar_rt(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_rt(char *str)
{
	int	i;

	if (!str)
		return (ft_putstr_rt("(null)"));
	i = 0;
	while (str[i])
		ft_putchar_rt(str[i++]);
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}

int	form_check(const char *format, va_list args)
{
	int	i;

	i = 0;
	if (*format == 'c')
		i += ft_putchar_rt(va_arg(args, int));
	else if (*format == 's')
		i += ft_putstr_rt(va_arg(args, char *));
	else if (*format == 'p')	// n
		i += ft_putstr_rt(va_arg(args, void *));
	else if (*format == 'd' || *format == 'i')
		i += ft_putstr_rt(ft_itoa(va_arg(args, int)));
	else if (*format == 'u')	// n
		i += ft_putchar_rt(*format);
	else if (*format == 'x')	// n
		i += ft_
	else if (*format == 'X')	// n
	else if (*format == '%')
		i += ft_putchar_rt('%');
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	i;

	i = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (ft_strchr("cspdiuxX%", *format))
				i += form_check(format, args);
		}
		else
			i += ft_putchar_rt(*format);
		format++;
	}
	va_end(args);
	return (i);
}

int	main(void)
{
//	char	*str = "Juhyeon";
	int	str = 42;
	char	c = 'a';

	ft_printf("Hello, %d", str);
	ft_printf("\n");
	ft_printf("%c", c);
	printf("\n-----\n");
	printf("Hello, %x", str);
	printf("\n");
	printf("%c", c);
	return 0;
}
