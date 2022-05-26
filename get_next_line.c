/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:35:54 by eclark            #+#    #+#             */
/*   Updated: 2022/05/26 11:53:55 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	read_file(int fd)
{
	static char 	*read_line;
	char			*buffer;
	int				res;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	res = 1;
	while (res != 0)
	{
		res = read(fd, &buffer, BUFFER_SIZE);
		if (res == -1)
			return (NULL);
		while (buffer != '\n')
		{
			strjoin(read_line, buffer);
		}

	}
}

char	return_line(int fd)
{
	/*join lines together? using strjoin*/
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
	readfile(fd);
	/*read from line
	*return line/append lines to eachother
	*free allocated space
	*/
}
