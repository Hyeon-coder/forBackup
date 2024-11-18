/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <ljh3900@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:20:32 by JuHyeon           #+#    #+#             */
/*   Updated: 2024/11/18 18:10:04 by juhyeonl         ###   ########.fr       */
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

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_itoa_base(unsigned int i, char *base)
{
	unsigned int	a;
	char	*rst;
	int	cnt;
	int	tmp;

	cnt = 0;
	if (!i || !base)
		return (0);
	if (ft_strlen(base) == 2)
		a = 2;
	else if (ft_strlen(base) == 8)
		a = 8;
	else if (ft_strlen(base) == 16)
		a = 16;
	else
		return (0);
	tmp = i;
	while (i / a != 0)
	{
		i /= a;
		cnt++;
	}
	rst = (char *)malloc(cnt * sizeof(char) + 1);
	if (!rst)
		return (0);
	i = tmp;
	tmp = cnt;
	while (i != 0)
	{
		if (i != 0)
			rst[tmp] = base[i % a];
		i /= a;
		tmp--;
	}
	rst[cnt + 1] = '\0';
	return (rst);
}

int	form_check(const char *format, va_list args)
{
	int	i;

	i = 0;
	if (*format == 'c')
		i += ft_putchar_rt(va_arg(args, int));
	else if (*format == 's')
		i += ft_putstr_rt(va_arg(args, char *));
//	else if (*format == 'p')
//		i += ft_itoa_base(		);
	else if (*format == 'd' || *format == 'i')
		i += ft_putstr_rt(ft_itoa(va_arg(args, int)));
//	else if (*format == 'u')
//		i += ft_putstr_rt(ft_itoa_base(va_arg(args, int), "012345678"));
	else if (*format == 'x')
		i += ft_putstr_rt(ft_itoa_base(va_arg(args, int), "0123456789abcdef"));
	else if (*format == 'X')
		i += ft_putstr_rt(ft_itoa_base(va_arg(args, int), "0123456789ABCDEF"));
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
	int	str = -999;

	ft_printf("%u", str);
	printf("\n-----\n");
	printf("%u", str);
	return 0;
}
