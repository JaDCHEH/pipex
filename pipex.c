/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:18:30 by cjad              #+#    #+#             */
/*   Updated: 2021/12/21 13:16:10 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int	*fd, char	**envp, char *av)
{
	close(fd[0]);
	dup2(fd[1], 1);
	execute_command(envp, av);
}

void	pipex(char	*av1, char	**envp)
{
	int	fd[2];
	int	frk;

	pipe(fd);
	frk = fork();
	if (frk < 0)
	{
		perror("");
		exit(0);
	}
	if (frk == 0)
		child_process(fd, envp, av1);
	else
	{
		wait(NULL);
		close(fd[1]);
		dup2(fd[0], 0);
	}
}
