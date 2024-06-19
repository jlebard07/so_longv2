/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:38:48 by jlebard           #+#    #+#             */
/*   Updated: 2024/06/14 18:29:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_size_of_unsigned(unsigned int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	if (i == 0)
		i = 1;
	return (i);
}

int	ft_if_unsigned(unsigned int n)
{
	int				i;
	int				x;
	char			*base_unsigned;
	char			*dest;

	if (n == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	x = ft_size_of_unsigned(n);
	i = 0;
	dest = malloc(sizeof(char) * (x + 1));
	base_unsigned = "0123456789";
	while (n > 0)
	{
		dest[i] = base_unsigned[n % 10];
		n /= 10;
		i ++;
	}
	dest[i] = '\0';
	while (i-- > 0)
		ft_putchar_fd(dest[i], 1);
	free(dest);
	return (x);
}
