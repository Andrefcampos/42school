
#include <stdio.h>
#include <stdlib.h>
#include "../libs/libft/libft.h"

char	*find_env(char **envp)
{
	int	index;

	index = 0;
	while (ft_strncmp("PATH", envp[index], 4))
		index++;
	return (envp[index]);
}

int	main(int ac, char **av, char **envp)
{
	char *args;

	args = find_env(envp);
	printf ("%s\n\n", args++);
	return (0);
}
