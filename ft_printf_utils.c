/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:50:59 by acolonne          #+#    #+#             */
/*   Updated: 2024/12/03 18:12:39 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	n_len(unsigned long long n)
{
	int	len;

	len = 0;
	while (n)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

char	*ft_itoa_ptr(unsigned long long n)
{
	char				*nb;
	unsigned long long	number;
	int					len;

	number = n;
	if (n == 0)
		return ("0");
	len = n_len(n);
	nb = malloc((sizeof(char) * len) + 1);
	if (!nb)
		return (0);
	nb[len] = '\0';
	while (len--)
	{
		number = (n % 16) + 48;
		if (number >= 58 && number <= 64)
			nb[len] = number + 39;
		else
			nb[len] = number;
		n = n / 16;
	}
	return (nb);
}

int	len_nb(long nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (0);
	if (nbr < 0)
		nbr = -nbr;
	while (nbr)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*put_in_numbers(long nbr, char *nb, int signe, int len)
{
	int	end;

	len = len_nb(nbr);
	end = len;
	nb = malloc(len + signe + 1);
	if (!nb)
		return (0);
	if (signe == 1)
	{
		nb[0] = '-';
		nbr = -nbr;
		len++;
	}
	len--;
	while (nbr > 0)
	{
		nb[len] = (nbr % 10) + 48;
		nbr = nbr / 10;
		len--;
	}
	nb[end + signe] = '\0';
	return (nb);
}

int	ft_itoa_printf(long n)
{
	char	*nb;
	long	nbr;
	int		len;
	int		signe;

	nbr = (long)n;
	nb = 0;
	len = 0;
	signe = 0;
	if (nbr == 0)
	{
		ft_putstr_fd("0", 1);
		return (1);
	}
	if (nbr < 0)
		signe = 1;
	nb = put_in_numbers(nbr, nb, signe, len);
	if (!nb)
		return (0);
	ft_putstr_fd(nb, 1);
	len = ft_strlen(nb);
	free (nb);
	return (len);
}
