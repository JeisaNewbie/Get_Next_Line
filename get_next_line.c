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
		tmp = backup[fd];
		i = read (fd, backup[fd], BUFFER_SIZE);
		if (i < BUFFER_SIZE)
			break ;
		backup[fd] = ft_strjoin (tmp, backup[fd]);
	}
	tmp = ft_split (fd);
	return (tmp);
}

// 개행문자가 있는 문자열을 split으로 처리한 후 backup배열 내에 문자열이 존재할때, 다음 gnl호출시 남은 문자열과 다음 문자열을 합쳐야함.
