/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlasrite <mlasrite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 14:09:10 by mlasrite          #+#    #+#             */
/*   Updated: 2020/01/18 20:58:51 by mlasrite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	lenword(char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static int	countword(char *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (s == 0)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (count);
}

static char	*allocateword(char *s, size_t n)
{
	unsigned int	i;
	char			*tab;

	tab = (char *)malloc(sizeof(char) * (n + 1));
	if (tab == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char		**ft_split(char const *s, char c, t_data *ptr)
{
	int		count;
	int		i;
	int		d;

	if (s == 0)
		return (0);
	count = countword((char *)s, c);
	ptr->deux = (char **)malloc(sizeof(char *) * (count + 1));
	if (ptr->deux == 0)
		return (0);
	i = 0;
	d = 0;
	while (count--)
	{
		while (*s == c)
			s++;
		ptr->deux[d++] = allocateword((char *)s, lenword((char *)s, c));
		s = s + lenword((char *)s, c);
		s++;
	}
	ptr->deux[d] = 0;
	return (ptr->deux);
}
