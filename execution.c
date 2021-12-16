#include "pipex.h"

void execute_command(char   **envp, char    *command)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(command, ' ');
	path = find_path(envp, cmd);
	if (path)
		execve(path, cmd, envp);
	else 
		perror("This command doesn't exist");
}