/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:00:37 by cjad              #+#    #+#             */
/*   Updated: 2021/12/21 13:15:53 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char	**av, char	**envp)
{
	int	fin;
	int	fout;
	int	a;

	a = 2;
	if (ac >= 5)
	{
		fin = open(av[1], O_RDONLY);
		fout = open(av[ac -1], O_CREAT | O_RDWR | O_TRUNC, 0666);
		dup2(fin, 0);
		if (fin < 0 || fout < 0)
		{
			perror("");
			return (0);
		}
		while (a < ac - 2)
		{
			pipex(av[a], envp);
			a++;
		}
		dup2(fout, 1);
		execute_command(envp, av[a]);
	}
	write(2, "Invalid number of arguments\n", 28);
	return (0);
}
