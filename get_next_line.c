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

static char	*read_file(int fd, char *buffer, char *readline)
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
		if (*temp == '\0')
		{
			free(temp);
			temp = (NULL);
		}
		if (ft_strchr(readline, '\n')
			break;
	}
	return (readline);
}

/*called when there is a \n in read_file ir eof*/
static char	*return_line(char *line)
{
	int		len;
	char		*readline;
	
	len = 0;
	/*finds the newline / eof*/
	while (line[len] != '\n' || line[len] != '\0') 
	{
		len++;
	}
	/*copies the line after the '/n'*/
	len = 0;
	while (line[len] && line[len] != '\n')
	{
		readline[len++] == line[len++];
	}
	readline = ft_substr(line, len + 1, ft_strlen(line)-len);
	if (*readline == '\0')
	{
		free(readline);
		return (NULL);
	}
	return (readline);
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
