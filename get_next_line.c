/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:01:38 by jhwang2           #+#    #+#             */
/*   Updated: 2022/09/20 19:46:03 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tmp;
	int		len_s1;
	int		len_s2;
	int		i;

	i = 0;
	if (s1 == NULL)
		s1 = "";
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	tmp = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (tmp == 0)
		return (0);
	while (i < len_s1)
		tmp[i++] = *s1++;
	i = 0;
	while (i < len_s2)
		tmp[i++ + len_s1] = *s2++;
	tmp[len_s1 + len_s2] = '\0';
	return (tmp);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_split(t_list **backup)
{
	char	*tmp;
	char	*temp;
	int		i;
	int		j;

	j = 0;
	if ((*backup)->content == NULL)
		return (NULL);
	i = ft_strchr ((*backup)->content, '\n');
	tmp = (char *)malloc(sizeof(char) * (i + 1));
	if (tmp == NULL)
		return (NULL);
	temp = (*backup)->content;
	while (j < i)
		tmp[j++] = *(*backup)->content++;
	tmp[j] = '\0';
	(*backup)->content = ft_strjoin((*backup)->content, "");
	if ((*backup)->content[0] == '\0')
	{
		free ((*backup)->content);
		(*backup)->content = NULL;
	}
	free (temp);
	return (tmp);
}

char	*read_fd(int fd, t_list **backup)
{
	char	tmp[BUFFER_SIZE + 1];
	char	*tmpptr;
	int		count;
	int		i;

	while (1)
	{
		i = 0;
		count = read (fd, tmp, BUFFER_SIZE);
		if (count == 0)
			break ;
		tmp[count] = '\0';
		tmpptr = (*backup)->content;
		(*backup)->content = ft_strjoin ((*backup)->content, tmp);
		free (tmpptr);
		while (tmp[i] != '\n' && tmp[i] != '\0')
			i++;
		if (tmp[i] == '\n')
			break ;
	}
	tmpptr = ft_split (backup);
	return (tmpptr);
}

char	*get_next_line(int fd)
{
	static t_list	*backup;
	char			*line;

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0 || read (fd, 0, 0) < 0)
		return (NULL);
	if (find_fd (fd, &backup) == 0)
	{
		backup = lstnew (fd);
		if (backup == NULL)
			return (NULL);
	}
	line = read_fd (fd, &backup);
	if (line == NULL)
	{
		lstfree (&backup);
		backup = NULL;
	}
	return (line);
}
/*int main()
{	
	int i = 0;
	while (i++ < 6)
		printf("%s", get_next_line(0));
	return (0);
}
int main()
{
	int fd = open ("./one_line_no_nl.txt", O_RDWR);
	char	*gnl;
	while ((gnl = get_next_line (fd)) != NULL)
		printf ("%s \n", gnl);
}*/
