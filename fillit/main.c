#include "libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdio.h>

void		ft_puts(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
}

int			print_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
	return (i);
}

char		**tab_filler(int fd, int fd1)
{
	int		gnl;
	int		i;
	int		count;
	char	*tmp;
	char	**tab;

	count = 0;
	i = 0;
	gnl = 0;
	tmp = 0;
	if (fd > 0 && fd1 > 0)
	{
		while ((gnl = get_next_line(fd1, &tmp)) == 1)
			count++;
		tab = (char **)malloc(sizeof(char *) * count + 1);
		while ((gnl = get_next_line(fd, &tmp)) == 1)
			tab[i++] = ft_strdup(tmp);
		tab[i] = 0;
	}
 	else
 	{
 		ft_putstr("OPEN FAILED ! :(\n");
 		return (0);
 	}
 	return (tab);
}

int		tetraminos_char_checker(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (ft_strchr(".#", tab[i][j]) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int 		main(int ac, char const **av)
{
	int		fd;
	int		fd1;
	char	**tab;

	fd = 0;
	fd1 = 0;
	tab = 0;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		fd1 = open(av[1], O_RDONLY);
	}
	else
	{
		ft_putstr("Argument needed.\n");
		return (-1);
	}
	tab = tab_filler(fd, fd1);
	if (tetraminos_char_checker(tab) != 0)
	{
		ft_puts("error");
		return (-1);
	}
	return 0;
}