/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:30:00 by javierzarag       #+#    #+#             */
/*   Updated: 2025/03/12 12:18:40 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

void	handle_input_redirection(t_commands *command)
{
	int	fd;

	if (command->input)
	{
		fd = open(command->input, O_RDONLY);
		if (fd == -1)
		{
			perror("open input file");
			exit(EXIT_FAILURE);
		}
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
}

void	handle_output_redirection(t_commands *command)
{
	int	fd;

	if (command->output)
	{
		fd = open(command->output, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			perror("open output file");
			exit(EXIT_FAILURE);
		}
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	if (command->output_append)
	{
		fd = open(command->output_append, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd == -1)
		{
			perror("open append file");
			exit(EXIT_FAILURE);
		}
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
}

void	execute_child_process(t_commands *command)
{
	handle_input_redirection(command);
	handle_output_redirection(command);
	if (command->command)
	{
		execvp(command->command, command->args);
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

void	execute_commands(t_commands *command)
{
	pid_t	pid;
	int		status;

	printf("hola");
	ft_set_signals();
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
		execute_child_process(command);
	if (waitpid(pid, &status, 0) == -1)
	{
		perror("waitpid");
		exit(EXIT_FAILURE);
	}
}
