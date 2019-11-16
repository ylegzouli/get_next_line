/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:21:44 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/14 14:36:52 by ylegzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char				*ft_strjoin(char const *s1, char const *s2)
{
	char		*ret;
	int			i;
	int			j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	ret = (void *)malloc(sizeof(char) * (i + j + 1));
	if (ret == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = '\0';
	return (ret);
}

int					len_substr(char const *s, unsigned int start, size_t len)
{
	if (ft_strlen(&s[start]) > len)
		return ((int)len);
	else
		return (ft_strlen(&s[start]));
}

char				*ret_error(char *ret)
{
	ret = malloc(sizeof(char));
	ret[0] = '\0';
	return (ret);
}

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*ret;
	int			i;
	int			size;

	ret = NULL;
	if (!s || !len)
		return (ret_error(ret));
	if (start >= len || start >= ft_strlen(s))
		return (ret_error(ret));
	size = len_substr(s, start, len);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (ret == 0)
		return (NULL);
	i = 0;
	while (s[start] != '\0' && i < size)
	{
		ret[i] = s[start];
		i++;
		start++;
	}
	ret[i] = '\0';
	return (ret);
}

unsigned int		ft_strlen(char const *str)
{
	unsigned int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
