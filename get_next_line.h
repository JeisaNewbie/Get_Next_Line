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
	int				next_fd;
}	t_list;
void	lstfree(int fd, t_list *backup);
t_list	*lstnew(int fd);
void	ft_strmove(char *tmp, int length);
char	*ft_split(t_list *cur, int count);
t_list	*find_fd(int fd, t_list *backup);
char	*get_next_line(int fd);
int		ft_strrchr(const char *s, int c, int count);
char	*ft_strjoin(char const *s1, char const *s2, int count);
void	ft_strlcat(char *dst, const char *src, size_t dstsize);

#endif
