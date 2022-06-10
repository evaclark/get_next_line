/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:35:54 by eclark            #+#    #+#             */
/*   Updated: 2022/06/10 13:34:55 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

/*while loop for while read function hasn't reached eof
 * if read malfuctions return null
 * if there is nothing to read break
 * assigns null to where the buffer has been read to, ending the string
 * if this is the first loop the readline string will be assigned an empty-
 * string ready to be filled
 * assign readline contents to *temp in order to not overwite using strjoin
 * free and nullify temp ready to be used in the next loop
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
		else if (res == 0)
			return (readline);
		buffer[res] = '\0';
		if (!readline)
			readline = ft_strdup("");
		temp = readline;
		readline = ft_strjoin(temp, buffer);
		free(temp);
		temp = (NULL);
		if (ft_strchr(readline, '\n'))
			return (readline);
	}
	return (readline);
}

/*called when there is a \n in read_file or eof
 * finds newline/eof indicator
 * checks to see if there is anything in line - if not return null
 * copies line until the '\n'/'\0' - from the position the function-
 * was called
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
	if (!line[1] || !line[len])
		return (NULL);
	readline = ft_substr(line, len + 1, ft_strlen(line)-len);
	if (*readline == '\0')
	{
		free(readline);
		readline = NULL;
	}
	line [len + 1] = '\0';
	return (readline);
}

/*first checks if fd exists & there isnt a negative buffer size
 * then allocates size for buffer + 1 for '\0' - checks malloc worked
 * reads from file, inputs into line
 * frees the buffer to be called again
 * checks if there is anything to return, if not return null
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
	buffer = (char *)malloc(sizeof * buffer * (BUFFER_SIZE + 1));
	if (!buffer)
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

int main (int argc, char **argv)
{
	int	fd;
	char	*line;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	line = "";

	while (line != NULL)
	{
		line  = get_next_line(fd);
		printf("%s", line);
	}
	fd = close(fd);
	return 0;
}
