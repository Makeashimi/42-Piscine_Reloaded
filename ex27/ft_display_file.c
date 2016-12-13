/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:22:37 by jcharloi          #+#    #+#             */
/*   Updated: 2016/11/11 15:13:25 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	buf;

	if (argc < 2)
		write(1, "File name missing.\n", 19);
	if (argc > 2)
		write(1, "Too many arguments.\n", 20);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	while (read(fd, &buf, BUF_SIZE) && argc <= 2)
	{
		ft_putchar(buf);
	}
	if (close(fd) == -1)
		return (1);
	return (0);
}
