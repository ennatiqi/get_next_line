/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennatiq <rennatiq@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:09:08 by rennatiq          #+#    #+#             */
/*   Updated: 2022/11/26 12:07:56 by rennatiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*first_try(int fd)
{
	int		ret;
	char	*resulta;

	resulta = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!resulta)
		return (0);
	ret = read(fd, resulta, BUFFER_SIZE);
	if (ret <= 0)
	{
		free(resulta);
		return (0);
	}
	resulta[ret] = 0;
	return (resulta);
}

static char	*read_from_file(char *resulta, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	int		ret;

	ret = 1;
	while (newline(resulta) == -1 && ret > 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret < 0)
		{
			free (resulta);
			return (0);
		}
		buff[ret] = 0;
		resulta = ft_strjoin(resulta, buff);
	}
	return (resulta);
}

char	*function_name(char *rest, char *resulta)
{
	if (rest[0] == '\0')
	{
		free(rest);
		rest = NULL;
	}
	free(resulta);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*resulta;
	char		*final;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd == 1 || fd == 2)
		return (0);
	if (!rest)
	{
		resulta = first_try(fd);
		if (!resulta)
			return (0);
	}
	if (rest)
		resulta = ft_strdup(rest);
	rest = NULL;
	resulta = read_from_file(resulta, fd);
	if (!resulta)
		return (0);
	rest = (char *)malloc(BUFFER_SIZE * 1);
	if (!rest)
		return (0);
	final = truncate_file(rest, resulta);
	rest = function_name(rest, resulta);
	return (final);
}
