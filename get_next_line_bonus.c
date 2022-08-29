/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:46:07 by jhwang2           #+#    #+#             */
/*   Updated: 2022/08/29 18:00:57 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*backup = NULL;

void	ft_strmove(char *tmp, int length)
{
	int	i;

	i = 0;
	while ((length + i) <= BUFFER_SIZE)
	{
		tmp[i] = tmp[length + i];
		i++;
	}
	while (i <= BUFFER_SIZE)
	{
		tmp[i] = '\0';
		i++;
	}
}

char	*ft_split(t_list *lstbackup, int fd)
{
	char	*tmp;
	int		i;

	i = ft_strrchr (lstbackup->content, '\n');
	tmp = ft_strdup (lstbackup->content, i);
	ft_strmove (lstbackup->content, i + 1);
	return (tmp);
}

char	*new_string(char *tmp, int count, char *backup_content)
{
	char	*tmp1;

	tmp1 = (char *)malloc(sizeof(char) * (BUFFER_SIZE * count) + 1);
	if (tmp1 == NULL)
		return (NULL);
	tmp1[0] = '\0';
	ft_strlcat (tmp1, backup_content, (BUFFER_SIZE * count) + 1);
	return (tmp1);
}

t_list	*find_fd(int fd)
{
	t_list	*tmp;
	char	*str;
	int		i;

	tmp = backup;
	if (tmp->fd != fd)
	{
		while ((tmp->next) != 0)
		{
			if (tmp->fd == fd)
				break ;
			tmp = tmp->next;
		}
	}
	if ((tmp->fd != fd) || tmp->content == 0)
	{
		if ((i = read (fd, str, BUFFER_SIZE)) < 0)
			return (NULL);
		tmp->next = ft_lstnew (str, fd);
	}
	return (tmp->next);
}

char	*get_next_line(int fd)
{
	static t_list	*backup = NULL;
	t_list			*lstbackup;
	char			*tmp;
	int				i;
	int				count;

	count = 1;
	if (backup == NULL)
	{
		if ((i = read (fd, tmp, BUFFER_SIZE)) < 0)
			return (NULL);		
		backup = ft_lstnew (tmp, fd);
	}
	lstbackup = find_fd (fd);
	while (ft_strrchr (lstbackup->content, '\n') == 0)
	{
		tmp = new_string (tmp, count, lstbackup->content);
		count++;
		i = read (fd, lstbackup->content, BUFFER_SIZE);
		lstbackup->content = ft_strjoin (tmp, lstbackup->content);
		if (i < BUFFER_SIZE)
			break ;
	}
	tmp = ft_split (lstbackup, fd);
	return (tmp);
}
