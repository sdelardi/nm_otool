/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 21:54:39 by sdelardi          #+#    #+#             */
/*   Updated: 2015/11/26 15:43:12 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	static	ft_nb_digits(int n)
{
	int digits;

	digits = 0;
	if (n < 0)
		n = -n;
	while (n / 10 > 0)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

char		*ft_itoa(int n)
{
	char	*nbr;
	int		digits;
	int		h;

	digits = ft_nb_digits(n);
	if (n == -2147483648 || n == 0)
		return ((n == 0) ? ft_strdup("0") : ft_strdup("-2147483648"));
	nbr = ft_strnew(digits + 1);
	if (nbr == NULL)
		return (NULL);
	h = 0;
	if (n < 0)
	{
		nbr[0] = '-';
		n = -n;
		digits++;
		h = 1;
	}
	while (digits >= h)
	{
		nbr[digits] = (n % 10) + 48;
		n /= 10;
		digits--;
	}
	return (nbr);
}
