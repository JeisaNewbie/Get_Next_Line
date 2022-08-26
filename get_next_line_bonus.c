#include "get_next_line_utils_bonus.c"

t_list	*backup;

void	ft_strmove (char *tmp, int length)
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

char	*ft_split (char *backup_content, int fd)
{
	char	*tmp;
	int		i;

	i = ft_strrchr (backup_content, '\n');
	tmp = ft_strdup (backup_content, i);
	ft_strmove (lstbackup->content, i + 1);
	return (tmp);
}

char	*new_string(char *tmp, char *backup_content)
{
	char	*tmp1;

	tmp1 = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (tmp1 == NULL)
		return (NULL);
	tmp1[0] = '\0';
	ft_strlcat (tmp1, backup_content, BUFFER_SIZE + 1);
	return (tmp1);
}

t_list	find_fd(int fd)
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
	if (tmp->fd != fd)
	{
		if ((i = read (fd, str, BUFFER_SIZE)) < 0)
			return (NULL);
		tmp->next = ft_lstnew (str, fd);
	}
	return (tmp->next);
}

char	*get_next_line(int fd)
{
	t_list	*lstbackup;
	char	*tmp;
	int		i;

	if (backup == NULL)
	{
		if((i = read (fd, tmp, BUFFER_SIZE)) < 0)
			return (NULL);		
		backup = ft_lstnew (tmp, fd);
	}
	lstbackup = find_fd (fd);
	while (ft_strrchr (lstbackup->content, '\n') == 0)
	{
		tmp = new_string (tmp,lstbackup->content);//백업안의 내용을 저장하려
		i = read (fd, lstbackup->content, BUFFER_SIZE);
		lstbackup->content = ft_strjoin (tmp, lstbackup->content);
		if (i < BUFFER_SIZE)
			break;
	}
	tmp = ft_split (lstbackup, fd);
	return (tmp);
}
