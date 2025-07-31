/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:06:48 by acolonne          #+#    #+#             */
/*   Updated: 2024/11/29 20:07:22 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	i = ft_strlen(s);
	ft_putstr_fd(s, 1);
	return (i);
}

int	ft_print_pointer(void *pointer)
{
	int					i;
	unsigned long long	pointer_add;
	char				*n;

	i = 0;
	pointer_add = (unsigned long long) pointer;
	if (pointer_add == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	n = ft_itoa_ptr(pointer_add);
	ft_putstr(n);
	i = 2 + ft_strlen(n);
	free(n);
	return (i);
}

int	found_special(const char *str, va_list params)
{
	int		i;

	i = 1;
	if (str[i] == '%')
		ft_putchar_fd('%', 1);
	else if (str[i] == 'c')
		ft_putchar_fd(va_arg(params, int), 1);
	else if (str[i] == 's')
		i = ft_putstr(va_arg(params, char *));
	else if (str[i] == 'p')
		i = ft_print_pointer(va_arg(params, void *));
	else if (str[i] == 'd' || str[i] == 'i')
		i = ft_itoa_printf(va_arg(params, int));
	else if (str[i] == 'u')
		i = ft_itoa_printf(va_arg(params, unsigned int));
	else if (str[i] == 'x' || str[i] == 'X')
		i = ft_itoa_hexa(va_arg(params, unsigned int), str[i]);
	else
	{
		ft_putchar_fd('%', 1);
		ft_putchar_fd(str[i], 1);
		return (2);
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		j;
	va_list	params;

	i = 0;
	j = 0;
	if (!str)
		return (-1);
	va_start(params, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			j = j + found_special(&str[i], params) - 2;
			i++;
		}
		else
			ft_putchar_fd(str[i], 1);
		i++;
	}
	j = i + j;
	va_end(params);
	return (j);
}
