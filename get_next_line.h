/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:46:22 by jhwang2           #+#    #+#             */
/*   Updated: 2022/09/08 18:30:25 by ahkiler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
	int				fd;
}	t_list;

t_list	*lstnew(int fd);
void	lstfree(t_list **backup);
void	ft_strmove(t_list **backup, int length, int count);
int		find_fd(int fd, t_list **backup);
char	*get_next_line(int fd);
char    *ft_strlcat(char *dst, char *src, size_t count);
char    *ft_strjoin(char *s1, char *s2);
int ft_strlen(const char *str);
char    *ft_split(t_list **backup);
char    *read_fd(int fd, t_list **backup);

#endif
