/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:21:52 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/17 15:22:48 by ylegzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

char			*ft_strjoin(char const *s1, char const *s2);
int				get_next_line(int fd, char **line);
char			*read_line(int fd, char *str);
int				backslash_n(char *str);
int				len_substr(char const *s, unsigned int start, size_t len);
char			*ret_error(void);
char			*ft_substr(char const *s, unsigned int start, size_t len);
unsigned int	ft_strlen(char const *str);

#endif
