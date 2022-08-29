/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:46:22 by jhwang2           #+#    #+#             */
/*   Updated: 2022/08/29 15:52:18 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	int				fd;
}	t_list;
void	ft_strmove(char *tmp, int length);
char	*ft_split(char *backup_content, int fd);
char	*new_string(char *tmp, int count, char *backup_content);
t_list	find_fd(int fd);
char	*get_next_line(int fd);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content, int fd);
char	*ft_strrchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

#endif
