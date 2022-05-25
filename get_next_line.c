/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:35:54 by eclark            #+#    #+#             */
/*   Updated: 2022/05/19 13:29:46 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	read_file(int fd)
{
	char	*buffer;
	/*read from fd to buffer variable
	*/	
}

char	return_line(int fd)
{

}

char	save_char(int fd)
{

}

char	*get_next_line(int fd)
{
	if ((fd < 0) || (BUFFER_SIZE <= 0))
	{
		return (NULL);
	}
	/*malloc to allocate space for lines
	*read from line
	*return line/append lines to eachother
	*free allocated space
	*/
}


