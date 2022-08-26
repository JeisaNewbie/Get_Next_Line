#include "get_next_line_utils_bonus.c"

t_list	backup;

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

char	*ft_split (t_list lstbackup, int fd)
{
	char	*tmp;
	int		i;

	i = ft_strrchr (lstbackup->content, '\n');
	tmp = ft_strdup (lstbackup->content, i);
	ft_strmove (lstbackup->content, i + 1);
	return (tmp);
}

char	*new_string(char *tmp1, char *tmp2)
{
	tmp1 = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (tmp1 == NULL)
		return (NULL);
	tmp1[0] = '\0';
	ft_strlcat (tmp1, tmp2, BUFFER_SIZE + 1);
	return (tmp1);
}

t_list	find_fd(int fd, int is_null)
{
	t_list	*tmp;
	char	*str;
	int		i;

	tmp = backup;
	if (backup->number < fd)
	{
		while (backup->number != fd)
			ft_lstadd_back (tmp, str, fd);
	}
	tmp = backup;
	while (tmp->fd != fd)
		tmp = tmp->next;
	return (tmp);
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
		tmp = new_string (tmp,lstbackup->content);
		i = read (fd, lstbackup->content, BUFFER_SIZE);
		lstbackup->content = ft_strjoin (tmp, lstbackup->content);
		if (i < BUFFER_SIZE)
			break;
	}
	tmp = ft_split (lstbackup, fd);
	return (tmp);
}
