#include "get_next_line_utils.c"

char	*backup[OPEN_MAX];

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

char	*ft_split (int fd)
{
	char	*tmp;
	int		i;

	i = ft_strrchr (backup[fd], '\n');
	tmp = ft_strdup (backup[fd], i);
	ft_strmove (backup[fd], i + 1);
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

char	*get_next_line(int fd)
{
	char	*tmp;
	int		i;

	if (backup[fd] == NULL)
		i = read (fd, backup[fd], BUFFER_SIZE);
	if (i == -1)
		return (NULL);
	while (ft_strrchr (backup[fd], '\n') == 0)
	{
		tmp = new_string (tmp, backup[fd]);
		i = read (fd, backup[fd], BUFFER_SIZE);
		backup[fd] = ft_strjoin (tmp, backup[fd]);
		if (i < BUFFER_SIZE)
			break;
	}
	tmp = ft_split (fd);
	return (tmp);
}

