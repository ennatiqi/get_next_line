/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennatiq <rennatiq@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:09:05 by rennatiq          #+#    #+#             */
/*   Updated: 2023/01/10 21:47:52 by rennatiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	s2 = (char *) malloc((ft_strlen_gnl(s1) + 1) * sizeof(char));
	if (!s2)
		return (0);
	while (s1 && s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	free(s1);
	return (s2);
}

char	*truncate_file(char *rest, char *resulta)
{
	int		i;
	int		j;
	int		k;
	char	*final;

	i = -1;
	k = 0;
	j = 0;
	while (resulta[k] != '\n' && resulta[k] != '\0')
		k++;
	final = (char *)malloc((k + 2) * sizeof(char));
	while (++i < k)
		final[i] = resulta[i];
	final[i] = resulta[i];
	if (resulta[i] == '\0')
	{
		rest[0] = '\0';
		return (final);
	}
	final[++i] = 0;
	while (resulta[i])
		rest[j++] = resulta[i++];
	rest[j] = '\0';
	return (final);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*resulta;
	int		m;
	int		n;

	i = 0;
	if (!s1 || !s2)
		return (0);
	n = ft_strlen_gnl(s1);
	m = ft_strlen_gnl(s2);
	resulta = (char *)malloc((n + m + 1) * sizeof(char));
	if (!resulta)
		return (0);
	while (i < n)
	{
		resulta[i] = ((char *)s1)[i];
		i++;
	}
	j = 0;
	while (i < (n + m))
		resulta[i++] = ((char *)s2)[j++];
	resulta[i] = 0;
	free(s1);
	return (resulta);
}
