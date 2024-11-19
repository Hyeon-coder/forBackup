/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_form_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <ljh3900@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:37:49 by JuHyeon           #+#    #+#             */
/*   Updated: 2024/11/19 13:39:39 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_form_check(const char *format, va_list args)
{
	int	i;

	i = 0;
	if (*format == 'c')
		i += ft_putchar_rt(va_arg(args, int));
	else if (*format == 's')
		i += ft_putstr_rt(va_arg(args, char *));
	else if (*format == 'p')
	{
		i += ft_putstr_rt("0x");
		i += ft_putstr_rt(ft_itoa_base((unsigned long)va_arg(args, void *),
					"0123456789abcdef"));
	}
	else if (*format == 'd' || *format == 'i')
		i += ft_putstr_rt(ft_itoa(va_arg(args, int)));
	else if (*format == 'u')
		i += ft_putstr_rt(ft_itoa_base(va_arg(args, unsigned int),
					"0123456789"));
	else if (*format == 'x')
		i += ft_putstr_rt(ft_itoa_base(va_arg(args, unsigned int),
					"0123456789abcdef"));
	else if (*format == 'X')
		i += ft_putstr_rt(ft_itoa_base(va_arg(args, unsigned int),
					"0123456789ABCDEF"));
	else if (*format == '%')
		i += ft_putchar_rt('%');
	return (i);
}
