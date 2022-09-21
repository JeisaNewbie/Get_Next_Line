/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:01:04 by jhwang2           #+#    #+#             */
/*   Updated: 2022/09/20 19:58:09 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

t_list	*lstnew(int fd)
{
	t_list	*new;
	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = NULL;
	new->next = NULL;
	new->fd = fd;
	return (new);
}

void	lstfree(t_list **backup)
{
	if (backup == NULL || *backup == NULL)
		return ;
	if ((*backup)->content != NULL)
	{
		//ft_memset ((*backup)->content, 0, 0);
		free ((*backup)->content);
		(*backup)->content = NULL;
	}
	free (*backup);
}

int	ft_strchr(const char *s, int c)
{
	char	*string;
	char	ch;
	int		i;

	i = 0;
	string = (char *)s;
	ch = (char)c;
	while (string[i] != '\0')
	{
		if (string[i] == ch)
			return (i + 1);
		i++;
	}
	return (i);
}
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	a;
	unsigned char	*tmp;

	a = (unsigned char)c;
	tmp = (unsigned char *)b;
	while (len)
	{
		*tmp = a;
		tmp++;
		len--;
	}
	return (b);
}
char	*ft_strlcat(char *dst, char *src, size_t count)
{
	size_t			len_dst;
	unsigned long	i;
	char			*tmp;

	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE * (count + 1)));
	len_dst = 0;
	while (dst[len_dst] != '\0')
	{
		tmp[len_dst] = dst[len_dst];
		len_dst++;
	}
	i = len_dst;
	while (i < BUFFER_SIZE * count)
	{
		tmp[i] = *src;
		src++;
		len_dst++;
		i++;
	}
	tmp[len_dst + i] = '\0';
	free (dst);
	free (src);
	return (tmp);
}
