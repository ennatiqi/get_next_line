/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennatiq <rennatiq@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:40:54 by rennatiq          #+#    #+#             */
/*   Updated: 2023/01/10 21:48:13 by rennatiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <fcntl.h> 
# include <stdlib.h>

char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen_gnl(const char *s);
int		newline(char *str);
char	*get_next_line(int fd);
char	*truncate_file(char *rest, char *resulta);
char	*ft_strdup( char *s1);

#endif