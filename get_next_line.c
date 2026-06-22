/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iualkhim <iualkhim@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 18:37:58 by iualkhim          #+#    #+#             */
/*   Updated: 2026/06/22 18:45:26 by iualkhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_save(int fd, char *save)
{
	char	*chunk;
	char	*temp;
	int		bytes_read;

	chunk = malloc(BUFFER_SIZE + 1);
	if (!chunk)
		return (NULL);
	bytes_read = read(fd, chunk, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		chunk[bytes_read] = '\0';
		temp = ft_strjoin(save, chunk);
		free(save);
		save = temp;
		if (!save || ft_strchr(save, '\n'))
			break ;
		bytes_read = read(fd, chunk, BUFFER_SIZE);
	}
	free(chunk);
	return (save);
}

char	*extract_line(char *saved)
{
	char	*line;
	int		i;

	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (saved[i] == '\n')
		i++;
	line = ft_substr(saved, 0, i);
	return (line);
}

char	*update_save(char *saved)
{
	char	*updated;
	int		i;

	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (saved[i] == '\n')
		i++;
	if (!saved[i])
		return (free(saved), NULL);
	updated = ft_substr(saved, i, ft_strlen(saved) - i);
	free(saved);
	return (updated);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_and_save(fd, save);
	if (!save)
		return (NULL);
	line = extract_line(save);
	save = update_save(save);
	return (line);
}

/*
int main(void){
    int fd = open("text.txt", O_RDONLY);
    char *line;

    line = get_next_line(fd);
    printf("Final save: %s", line);
    free(line);
    return (0);
}
*/
