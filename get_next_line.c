/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:35:54 by eclark            #+#    #+#             */
/*   Updated: 2022/06/02 11:53:55 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

/*while loop for while read function hasn't reached eof
 * if read malfuctions return null
 * if there is nothing to read break
 * assign readline contents to *temp in order to not overwite using strjoin
 * if temp contains '\0' indicating eof free remaining space
 * if there is a '\n' readline break from the reading function
 * returns the read line*/
static char	*read_file(int fd, char *buffer, char *readline)
{
	int		res;
	char	*temp;

	res = 1;
	while (res != 0)
	{
		res = read(fd, buffer, BUFFER_SIZE);
		if (res == -1)
			return (NULL);
		if (res == 0)
			break ;
		buffer[res] = '\0';
		if (!readline)
		{
			readline = ft_strdup("");
		}
		temp = readline;
		readline = ft_strjoin(temp, buffer);
		free(temp);
		temp = (NULL);
		if (ft_strchr(readline, '\n'))
			break ;
	}
	return (readline);
}

/*called when there is a \n in read_file or eof
 * finds newline/eof indicator
 * copies line until the '\n'
 * saves remaining text after line using substr
 * frees space if readline is at the eof
 * returns readline, now where it needs to begin again*/
static char	*return_line(char *line)
{
	int		len;
	char	*readline;

	len = 0;
	while (line[len] != '\n' && line[len] != '\0')
	{
		len++;
	}
	if(!line[1] || !line[len])
		return (NULL);
	readline = ft_substr(line, len + 1, ft_strlen(line)-len);
	if (*readline == '\0')
	{
		free(readline);
		readline = (NULL);
	}
	line [len + 1] = '\0';
	return (readline);
}

/*first checks if fd exists & there isnt a negative buffer size
 * then allocates size for buffer + 1 for '\0'
 * reads from file, inputs into line
 * returns just one line from this string (if there was excess)
 * frees allocated space in line for next line*/
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
	line = read_file(fd, buffer, readline);
	free(buffer);
	buffer = NULL;
	if (!line)
	{
		return (NULL);
	}
	readline = return_line(line);
	return (line);
}
