/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:01:04 by jhwang2           #+#    #+#             */
/*   Updated: 2022/09/24 21:26:40 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

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

void	lstfree(t_list **backup, int fd)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *backup;
	prev = *backup;
	if (tmp->fd == fd)
	{
		(*backup) = (*backup)->next;
		if (tmp->content != NULL)
			free (tmp->content);
		free (tmp);
		return ;
	}
	while (tmp->fd != fd)
	{
		*backup = tmp;
		tmp = tmp->next;
	}
	(*backup)->next = tmp->next;
	if (tmp->content != NULL)
		free (tmp->content);
	free (tmp);
	*backup = prev;
}

int	find_fd(int fd, t_list **backup)
{
	if ((*backup)->fd == fd)
		return (1);
	while ((*backup)->next != NULL)
	{
		*backup = (*backup)->next;
		if ((*backup)->fd == fd)
			return (1);
	}
	return (0);
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
