/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:35:54 by eclark            #+#    #+#             */
/*   Updated: 2022/05/30 15:08:47 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	read_file(int fd, char *buffer)
{
	static char 	*read_line;
	int				res;

	res = 1;
	while (res != 0) /*while read hasn't reached eof keep looping*/
	{
		res = read(fd, &buffer, BUFFER_SIZE);
		if (res == -1)
			return (NULL);
		/*res shows if read function has worked - if not return null*/
		read_line  = ft_strjoin(buffer, read_line);
		if (ft_strchr(read_line, '\n')
		   res == 0;
		/*if read_line contains a \n end the reading loop -- use substr??*/
	}	
}

/*called when there is a \n in read_file ir eof*/
char	return_line(static char *read_line)
{
	int		len;
	char	str;
	
	len = 0;
	while (read_line[len] != '\n')
	{
		len++;
	}

}


char	extra_char(static char	*read_line)
{
	/*measure amount of characters after \n using strlen?
	 *malloc amount  of characters to str
	 *copy and add /0, return str*/

}

char	*get_next_line(int fd)
{
	char	*buffer;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
	{
		return (NULL);
	}
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
	{
		return (NULL);
	}
	/*read from line
	*return line/append lines to eachother
	*free allocated space
	*/
	read_file = (fd, buffer);
}
