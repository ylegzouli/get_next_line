/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:21:47 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/16 19:14:02 by ylegzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		backslash_n(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*read_line(int fd, char *str)
{
	int		ret;
	char	buffer[BUFFER_SIZE + 1];
	char	*temp;

	ret = 1;
	while (backslash_n(str) == 0 && ret > 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
		{
			free(str);
			str = NULL;
			return (NULL);
		}
		buffer[ret] = '\0';
		temp = ft_strjoin(str, buffer);
		free(str);
		str = temp;
	}
	return (str);
}

int		ft_check_error(int fd, char **str, char **line)
{
	if (fd == -1 || line == NULL)
		return (0);
	if (!(*str))
	{
		if (!(*str = (char *)malloc(sizeof(char *) * (BUFFER_SIZE + 1))))
			return (0);
		(*str)[0] = '\0';
	}
	return (1);
}

void	buff_copy(char **str, int size_line)
{
	int		i;

	i = 0;
	while ((*str)[i + size_line + 1])
	{
		(*str)[i] = (*str)[i + size_line + 1];
		i++;
	}
	(*str)[i] = (*str)[i + size_line + 1];
}

int		get_next_line(int fd, char **line)
{
	static char	*str;
	int			size_line;

	if (!ft_check_error(fd, &str, line))
		return (-1);
	if ((str = read_line(fd, str)) == NULL)
		return (-1);
	size_line = 0;
	if (!(str[size_line]))
	{
		//(*line) <--- '\0'
		return (0);
	}
	while (str[size_line] && str[size_line] != '\n')
		size_line++;
	(*line) = ft_substr(str, 0, size_line);
	if (backslash_n(str) == 1)
		buff_copy(&str, size_line);
	else
	{
		free(str);
		str = NULL;
		return (0);
	}
	return (1);
}
