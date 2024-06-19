/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hexa2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:46:56 by jlebard           #+#    #+#             */
/*   Updated: 2024/06/14 18:29:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_size_of_hexa(unsigned int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	if (i == 0)
		i = 1;
	return (i);
}

int	ft_if_hexa_up(unsigned int n)
{
	int		i;
	int		x;
	char	*dest;
	char	*base_hexa;

	i = 0;
	x = ft_size_of_hexa(n);
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	dest = ft_calloc(x + 1, sizeof(char));
	base_hexa = "0123456789ABCDEF";
	while (n > 0)
	{
		dest[i++] = base_hexa[n % 16];
		n /= 16;
	}
	dest[i] = '\0';
	while (--i >= 0)
		ft_putchar_fd(dest[i], 1);
	free(dest);
	return (x);
}
