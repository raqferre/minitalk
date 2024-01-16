/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:00:19 by raqferre          #+#    #+#             */
/*   Updated: 2022/12/05 13:39:04 by raqferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)

{
	int	sign;
	int	out;
	int	i;

	sign = 1;
	i = 0;
	out = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
			i++;
	if (str[i] == '+' && str[i + 1] == '-')
		return (0);
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		sign = sign * -1;
		i++;
	}	
	while (str[i] >= '0' && str[i] <= '9')
	{
		out = out * 10 + str[i] - 48;
		i++;
	}
	return (sign * out);
}

void	ft_putchar_fd(char c, int fd)

{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	out;

	out = (long) n;
	if (out < 0)
	{
		ft_putchar_fd('-', fd);
		out = out * -1;
	}
	if (out / 10)
	{
		ft_putnbr_fd((out / 10), fd);
	}
	ft_putchar_fd((out % 10 + 48), fd);
}

void	ft_putstr_fd(char *s, int fd)

{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
						i++;
	}
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{		
		if (*str == (char) c)
			return ((char *)str);
			str++;
	}	
	if (*str == (char) c)
		return ((char *) str);
	return (0);
}
