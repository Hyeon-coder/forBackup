/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <ljh3900@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:20:32 by JuHyeon           #+#    #+#             */
/*   Updated: 2024/11/19 13:43:50 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed;

	printed = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (ft_strchr("cspdiuxX%", *format))
				printed += ft_form_check(format, args);
		}
		else
			printed += ft_putchar_rt(*format);
		format++;
	}
	va_end(args);
	return (printed);
}

int	main(void)
{
	int	str;

	str = 999;
	ft_printf("%x", str);
	printf("\n-----\n");
	printf("%x", str);
	return (0);
}

