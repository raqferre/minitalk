/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:08:22 by raqferre          #+#    #+#             */
/*   Updated: 2022/12/05 14:16:24 by raqferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include <signal.h>
#include <stdio.h>

static int	check_error(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_strchr("0123456789", str[i]))
			return (1);
	}
	return (0);
}

static void	sending(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(200);
		}
	}
}	

int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		if (check_error(argv[1]) == 1)
			write(1, "Error", 5);
		sending(ft_atoi(argv[1]), argv[2]);
	}
	else
		write(1, "Error", 5);
	return (0);
}
