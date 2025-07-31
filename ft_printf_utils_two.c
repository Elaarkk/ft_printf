/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:23:52 by acolonne          #+#    #+#             */
/*   Updated: 2024/12/03 19:34:54 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_caps(int x)
{
	int	i;

	if (x == 'X')
		i = -32;
	else
		i = 0;
	return (i);
}

int	len_nb_hexa(long long nbr)
{
	int	len;

	len = 0;
	while (nbr)
	{
		nbr = nbr / 16;
		len++;
	}
	return (len);
}

char	*put_in_numbers_hexa(unsigned long long nbr, char *nb, int hexa_caps)
{
	int	end;
	int	len;

	len = len_nb_hexa(nbr);
	end = len;
	nb = malloc(len + 1);
	if (!nb)
		return (0);
	while (len--)
	{
		nb[len] = (nbr % 16) + 48;
		if (nb[len] >= 58 && nb[len] <= 64)
			nb[len] = nb[len] + 39 + hexa_caps;
		else
			nb[len] = nb[len];
		nbr = nbr / 16;
	}
	nb[end] = '\0';
	return (nb);
}

int	ft_itoa_hexa(unsigned int n, int x)
{
	unsigned long long	nbr;
	char				*nb;
	int					len;
	int					hexa_caps;

	nbr = (unsigned long long)n;
	nb = 0;
	len = 0;
	hexa_caps = is_caps(x);
	if (nbr == 0)
	{
		ft_putstr_fd("0", 1);
		return (1);
	}
	nb = put_in_numbers_hexa(nbr, nb, hexa_caps);
	if (!nb)
		return (0);
	ft_putstr_fd(nb, 1);
	len = ft_strlen(nb);
	free (nb);
	return (len);
}
