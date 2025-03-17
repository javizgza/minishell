/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:36:45 by jazarago          #+#    #+#             */
/*   Updated: 2025/03/17 15:17:57 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_handle_sigint(int signum)
{
	if (signum == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	ft_handle_sigquit(int signum)
{
	if (signum == SIGQUIT)
		printf("Quit\n");
}

void	ft_set_signals(void)
{
	signal(SIGINT, ft_handle_sigint);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_new_line(int signal)
{
	(void)signal;
	rl_on_new_line();
	printf("\n");
}

void	unset_signals(void)
{
	signal(SIGINT, ft_new_line);
	signal(SIGQUIT, ft_handle_sigquit);
}
