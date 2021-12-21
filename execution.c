/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:23:54 by cjad              #+#    #+#             */
/*   Updated: 2021/12/21 13:15:27 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_command(char	**envp, char	*command)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(command, ' ');
	path = find_path(envp, cmd);
	if (path)
		execve(path, cmd, envp);
	else
	{
		perror("");
		exit(0);
	}
	free_tab(cmd);
	free(path);
}
