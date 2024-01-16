/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:08:44 by raqferre          #+#    #+#             */
/*   Updated: 2022/12/05 15:43:17 by raqferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

void	print_text(int sig, siginfo_t *info, void *context)
{
	static int	i = 7;
	static int	c = 0;

	(void)info;
	(void)context;
	if (sig == SIGUSR1)
	{
		c += 1 << i;
	}
	i--;
	if (i == -1)
	{	
		write(1, &c, 1);
		c = 0;
		i = 7;
	}
}

int	main(void)
{	
	pid_t				pid;
	struct sigaction	act;

	pid = getpid();
	ft_putstr_fd("My PID is pid ", 1);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	act.sa_sigaction = print_text;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	while (1)
		pause();
	return (0);
}
