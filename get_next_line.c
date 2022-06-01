/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:35:54 by eclark            #+#    #+#             */
/*   Updated: 2022/06/01 11:59:29 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	read_file(int fd, char *buffer, char *readline)
{
	int		res;
	char	*temp;

	res = 1;
	while (res != 0) /*while read hasn't reached eof keep looping*/
	{
		res = read(fd, &buffer, BUFFER_SIZE);
		if (res == -1)
			return (NULL);
		/*res shows if read function has worked - if not return null*/
		if (res == 0)
			break;
		temp = readline;
		readline = ft_strjoin(buffer, temp);
		free(temp);
		if (ft_strchr(readline, '\n')
			break;
	}
	return (readline);
}

/*called when there is a \n in read_file ir eof*/
char	return_line(char *str)
{
	int		len;
	
	len = 0;
	while (read_line[len] != '\n' || read_line[len] != '\0') 
	{
		len++;
	}
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL)
	
	return (str);
}


char	extra_char(char	*readline)
{
	/*measure amount of characters after \n using strlen?
	 *malloc amount  of characters to str
	 *copy and add /0, return str*/
	int 	i;
	int		len;
	char	*extra;

	i = 0;
	while (*readline != '\n')
	{
		i++;
	}
	len = (ft_strlen(readline) - i) + 1;
	extra = malloc(len * sizeof(char));
	if (!extra)
		return (NULL);
	extra = ft_substr(readline, i, len);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*readline;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
	{
		return (NULL);
	}
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
	{
		return (NULL);
	}
	/*read from line*/
	line = read_file(fd, buffer, readline);
	/*return line/append lines to eachother*/

	/*free allocated space*/
	if (*line == '\0')
	{
		free(line);
		return (NULL);
	}
}
