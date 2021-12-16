/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:18:30 by cjad              #+#    #+#             */
/*   Updated: 2021/12/16 19:49:00 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int	*fd, int fd1, char	**envp, char	**av)
{
	dup2(fd1, 0);
	dup2(fd[1], 1);
	close(fd[0]);
	close(fd1);
	execute_command(envp, av[2]);
}

void	parent_process(int *fd, int fd2, char	**envp, char	**av)
{
	dup2(fd2, 1);
	dup2(fd[0], 0);
	close(fd[1]);
	close(fd2);
	execute_command(envp, av[3]);
}

void pipex(int fd1, int fd2, char	**av, char	**envp)
{
	int		fd[2];
	int 	frk;
	char	**commande;
	int		s;
	
	frk = pipe(fd);
	if (frk < 0)
		{
			perror("An error occured when executing pipe :");
			exit(0);
		}
	frk = fork();
	if (frk == 0)
		child_process(fd, fd1, envp, av);
	else
	{
		wait(&s);
		parent_process(fd, fd2, envp, av);
	}
}

int	main(int ac, char	**av,char	**envp)
{
	int f1;
	int f2;
	
	if(ac == 5)
	{
		f1 = open(av[1], O_RDONLY);
		f2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0666);
		if (f1 < 0 || f2 < 0)
			return(0);
		pipex(f1, f2, av, envp);
	}
	return(0);
}