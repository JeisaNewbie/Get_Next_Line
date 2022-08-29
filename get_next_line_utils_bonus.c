/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:46:14 by jhwang2           #+#    #+#             */
/*   Updated: 2022/08/29 17:55:17 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == 0)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstnew(void *content, int fd)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list == 0)
		return (0);
	list->content = content;
	list->next = 0;
	list->fd = fd;
	return (list);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*string;
	char	ch;
	int		i;

	i = 0;
	string = (char *)s;
	ch = (char)c;
	while (i <= BUFFER_SIZE)
	{
		if (string[i] == ch)
			return (&string[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	size_t	len_s1;
	int		i;

	len_s1 = 0;
	while (s1[len_s1] != '\0')
		len_s1++;
	tmp = (char *)malloc(sizeof(char) * (len_s1 + BUFFER_SIZE + 1));
	if (tmp == 0)
		return (0);
	tmp[0] = '\0';
	ft_strlcat(tmp, s1, len_s1 + 1);
	ft_strlcat(tmp, s2, len_s1 + BUFFER_SIZE + 1);
	tmp[len_s1 + BUFFER_SIZE] = '\0';
	return (tmp);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_dnd;
	size_t	size;

	len_dst = 0;
	while (dst[len_dst] != '\0')
		len_dst++;
	len_dnd = len_dst + dstsize;
	if (dstsize <= len_dst)
		return (NULL);
	size = len_dnd - 1;
	while (size > 0)
	{
		dst[len_dst] = *src;
		src++;
		len_dst++;
		size--;
	}
	dst[len_dst] = '\0';
	return (len_dnd);
}
