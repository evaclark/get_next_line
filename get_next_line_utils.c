/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:36:34 by eclark            #+#    #+#             */
/*   Updated: 2022/06/03 11:23:10 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(char const *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		t_len;
	char	*ptr;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	t_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = malloc(sizeof(char) * (t_len));
	if (ptr == NULL)
		return (NULL);
	while (*s1)
		ptr[i++] = *s1++;
	while (*s2)
		ptr[i++] = *s2++;
	ptr[t_len - 1] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (0);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = start;
	j = 0;
	while (i < ft_strlen(s) && j < len)
	{
		str[j++] = s[i++];
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(s1) + 1;
	ptr = malloc(sizeof(*s1) * len);
	ptr = ft_memcpy(ptr, s1, len);
	return (ptr);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*cdst;
	unsigned char	*csrc;

	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*cdst = *csrc;
		cdst++;
		csrc++;
		i++;
	}
	return (dst);
}
