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
		free ((*backup)->content);
		(*backup)->content = NULL;
	}
	free (*backup);
}

int	find_fd(int fd, t_list **backup)
{
	while (*backup != NULL && (*backup)->fd != fd)
		*backup = (*backup)->next;
	if (*backup == NULL)
		return (0);
	else
		return (1);
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
