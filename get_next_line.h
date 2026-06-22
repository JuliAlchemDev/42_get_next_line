/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iualkhim <iualkhim@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 18:19:33 by iualkhim          #+#    #+#             */
/*   Updated: 2026/06/22 18:21:29 by iualkhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h> // malloc, free, size_t
# include <fcntl.h> // O_RDONLY flag
# include <unistd.h> // read, close

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd);

// GNL Utils
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int ch);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin(const char *str_1, const char *str_2);
char	*ft_substr(const char *str, unsigned int start, size_t len);

#endif
