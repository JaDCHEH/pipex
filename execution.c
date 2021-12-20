/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:23:54 by cjad              #+#    #+#             */
/*   Updated: 2021/12/20 13:23:55 by cjad             ###   ########.fr       */
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
		perror("This command doesn't exist");
	free_tab(cmd);
	free(path);
}
