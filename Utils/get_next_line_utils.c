/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlasrite <mlasrite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 18:54:55 by mlasrite          #+#    #+#             */
/*   Updated: 2020/01/17 14:14:06 by mlasrite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char			*ptr;
	int						len;
	int						i;

	len = count * size;
	i = 0;
	if (!(ptr = (unsigned char*)malloc(size * count)))
		return (NULL);
	while (i < len)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		s1len;
	int		s2len;
	int		i;
	int		j;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	p = (char *)malloc((s1len + s2len) * sizeof(char) + 1);
	if (p == 0)
		return (0);
	i = 0;
	while (s1len--)
	{
		p[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2len--)
		p[i++] = s2[j++];
	p[i] = '\0';
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ps;
	int		i;

	if (!s)
		return (0);
	if (start > ft_strlen(s) || !s[0])
	{
		ps = (char *)malloc(sizeof(char));
		if (ps == 0)
			return (0);
		ps[0] = '\0';
		return (ps);
	}
	i = 0;
	ps = (char *)malloc(len * sizeof(char) + 1);
	if (ps == 0)
		return (0);
	while (len--)
		ps[i++] = s[start++];
	ps[i] = '\0';
	return (ps);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char*)s);
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char*)s);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	if (s == NULL)
		return (i);
	while (s[i])
		i++;
	return (i);
}
