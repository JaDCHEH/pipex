/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:23:13 by cjad              #+#    #+#             */
/*   Updated: 2021/12/20 15:02:20 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	**ft_split(char const	*s, char c);
char	*ft_substr(char const	*s, unsigned int start, size_t len);
size_t	ft_strlen(const char *c);
int		ft_strncmp(const char	*s1, const char	*s2, size_t	n);
char	*ft_strdup(const char	*s1);
char	*ft_strjoin(char const	*s1, char const *s2);
char	*find_path(char	**envp, char **cmd);
void	execute_command(char	**envp, char	*command);
void	free_tab(char	**tab);
void	pipex(char	*av, char	**envp);

#endif
