/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:01:38 by jhwang2           #+#    #+#             */
/*   Updated: 2022/09/08 18:49:00 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

t_list	*find_fd(int fd, t_list *backup)
{
	t_list	*cur;
	int		i;

	if (fd < 2)
		return (NULL);
	cur = backup;
	while ((cur->next_fd != 0) && (cur->fd != fd))
		cur = cur->next;
	if (cur->fd != fd)
	{
		cur->next = lstnew (fd);
		i = read (fd, cur->next->content, BUFFER_SIZE);
		if (i < 0)
		{
			lstfree (fd, backup);
			cur = NULL;
			return (NULL);
		}
		cur->next_fd = fd;
		cur = cur->next;
	}
	return (cur);
}

void	ft_strmove(char *tmp, int length)
{
	int	i;

	i = 0;
	while (((length + i) <= BUFFER_SIZE) || tmp[length + i] != '\0')
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

char	*ft_split(t_list *cur, int count)
{
	char	*tmp;
	int		i;
	int		j;

	j = 0;
	i = ft_strrchr (cur->content, '\n', count);
	tmp = (char *)malloc(sizeof(char) * i + 1);
	if (tmp == NULL)
		return (NULL);
	while (j < i)
	{
		tmp[j] = cur->content[j];
		j++;
	}
	tmp[j] = '\0';
	ft_strmove (cur->content, i + 1);
	return (tmp);
}

char	*ft_strjoin(char const *s1, char const *s2, int count)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE * count) + 1);
	if (tmp == 0)
		return (0);
	tmp[0] = '\0';
	ft_strlcat (tmp, s1, (BUFFER_SIZE * (count - 1)) + 1);
	ft_strlcat (tmp, s2, BUFFER_SIZE + 1);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static t_list	*backup = NULL;
	t_list			*cur;
	char			*tmp;
	int				count;

	count = 1;
	if (backup == NULL)
	{
		backup = lstnew (0);
		if (backup == NULL)
			return (NULL);
	}
	cur = find_fd (fd, backup);
	if (cur == NULL)
		return (NULL);
	while (!(ft_strrchr (cur->content, '\n', count))
		|| !(ft_strrchr (cur->content, '\0', count)))
	{
		tmp = cur->content;
		if (read (fd, cur->content, BUFFER_SIZE) < 0)
			return (NULL);
		cur->content = ft_strjoin (tmp, cur->content, count++);
	}
	tmp = ft_split (cur, count);
	return (tmp);
}
