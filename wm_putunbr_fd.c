/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wm_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfelipe- < wfelipe-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 19:14:46 by wfelipe-          #+#    #+#             */
/*   Updated: 2021/09/29 23:40:13 by wfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	core(unsigned int integer, int fd)
{
	unsigned int	result;
	unsigned int	midzeros_verifier;

	result = 10;
	while ((integer / result) >= 10)
		result = result * 10;
	if (integer / result != 0)
		ft_putchar_fd('0' + (integer / result), fd);
	else if (integer / result == 0)
	{
		ft_putchar_fd('0' + (integer % result), fd);
		return ;
	}
	midzeros_verifier = result / 10;
	while (integer % result < midzeros_verifier)
	{
		ft_putchar_fd('0', fd);
		midzeros_verifier /= 10;
		if (midzeros_verifier == 0)
			return ;
	}
	core (integer % result, fd);
	return ;
}

void	wm_putunbr_fd(unsigned int n, int fd)
{
	unsigned int	integer;

	if (n < 0)
	{
		integer = -n;
		write(fd, "-", 1);
	}
	else
		integer = n;
	core (integer, fd);
}