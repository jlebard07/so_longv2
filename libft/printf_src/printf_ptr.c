/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:36:32 by jlebard           #+#    #+#             */
/*   Updated: 2024/06/14 18:29:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_size_of_ptr(unsigned long long n)
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

static int	ft_write_ptr(uintptr_t ptr)
{
	unsigned long long		i;
	unsigned long long		n;
	char					*dest;
	char					*base_hexa;

	i = 0;
	n = (unsigned long long)ptr;
	dest = malloc(sizeof(char) * (ft_size_of_ptr(n) + 1));
	base_hexa = "0123456789abcdef";
	while (n > 0)
	{
		dest[i] = base_hexa[n % 16];
		n /= 16;
		i ++;
	}
	dest[i] = '\0';
	n = i;
	while (i > 0)
	{
		i --;
		ft_putchar_fd(dest[i], 1);
	}
	free(dest);
	return ((int)n + 2);
}

int	ft_if_ptr(void *ptr)
{
	uintptr_t	n;

	n = (uintptr_t)ptr;
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		write(1, "0x", 2);
		return (ft_write_ptr(n));
	}
}
