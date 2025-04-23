/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:36:45 by jazarago          #+#    #+#             */
/*   Updated: 2025/04/23 13:46:29 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execute.h"

void	ft_handle_sigint(int signum)
{
	printf("\n");
	if (g_signal.heredoc_fd > 0)
	{
		close(0);
		g_signal.heredoc_fd = 0;
	}
	else
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	g_signal.exit_sig = signum;
}

void	ft_handle_sigquit(int signum)
{
	if (signum == SIGQUIT)
		printf("Quit\n");
	g_signal.exit_sig = signum;
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
	g_signal.exit_sig = signal;
}

void	unset_signals(void)
{
	signal(SIGINT, ft_new_line);
	signal(SIGQUIT, ft_handle_sigquit);
}
