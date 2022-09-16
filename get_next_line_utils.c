/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:01:04 by jhwang2           #+#    #+#             */
/*   Updated: 2022/09/08 18:52:00 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

t_list	*lstnew(int fd)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->content = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (new == NULL || new->content == NULL)
		return (NULL);
	new->next = NULL;
	new->fd = fd;
	new->next_fd = 0;
	return (new);
}

void	lstfree(int fd, t_list *backup)
{
	t_list	*tmp;

	while (backup->next_fd != fd)
		backup = backup->next;
	tmp = backup->next;
	backup->next = backup->next->next;
	backup->next_fd = backup->next->next_fd;
	free (tmp->content);
	free (tmp);
	tmp = NULL;
}

int	ft_strrchr(const char *s, int c, int count)
{
	char	*string;
	char	ch;
	int		i;

	i = 0;
	string = (char *)s;
	ch = (char)c;
	while (i <= (BUFFER_SIZE * count))
	{
		if (string[i] == ch || string[i] == '\0')
			return (i);
		i++;
	}
	return (0);
}

void	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_total;

	len_dst = 0;
	while (dst[len_dst] != '\0')
		len_dst++;
	len_total = len_dst + dstsize;
	while (len_dst < len_total)
	{
		dst[len_dst] = *src;
		src++;
		len_dst++;
	}
	dst[len_dst] = '\0';
	return ;
}
