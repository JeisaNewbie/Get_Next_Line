/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:01:38 by jhwang2           #+#    #+#             */
/*   Updated: 2022/09/20 12:33:06 by jhwang2          ###   ########.fr       */
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
	{
		tmp[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len_s2)
	{
		tmp[i + len_s1] = s2[i];
		i++;
	}
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
	//char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((*backup)->content == NULL)
		return (NULL);
	while ((*backup)->content[i] != '\n' &&
	(*backup)->content[i] != '\0')
		i++;
	if ((*backup)->content[i] == '\n')
		i++;
	tmp = (char *)malloc(sizeof(char) * (i + 1));
	if (tmp == NULL)
		return (NULL);
	while (j < i)
	{
		tmp[j] = (*backup)->content[j];
		j++;
	}
	tmp[j] = '\0';
	//temp = (*backup)->content;
	(*backup)->content = &(*backup)->content[j];
	//if ((*backup)->content[j] == '\0')
	//{
		//free (temp);
	//	(*backup)->content = NULL;
	//}
	return (tmp);
}

char	*read_fd(int fd, t_list **backup)
{
	char	tmp[BUFFER_SIZE + 1];
	char	*tmpptr;
	int		count;
	int		i;

	i = 0;
	while (1)
	{
		if ((count = read (fd, tmp, BUFFER_SIZE)) == 0)
			break ;
		tmp[count] = '\0';
		while (tmp[i] != '\n' && tmp[i] != '\0')
			i++;
		if (i < BUFFER_SIZE)
			break ;
		tmpptr = (*backup)->content;
		(*backup)->content = ft_strjoin ((*backup)->content, tmp);
		//printf ("%s \n", (*backup)->content);
		if (tmpptr != NULL)
			free (tmpptr);
		i = 0;
	}
	if (count != 0)
		(*backup)->content = ft_strjoin ((*backup)->content, tmp);
	tmpptr = ft_split (backup);
	//printf ("split backup = %s \n", (*backup)->content);
	return (tmpptr);
}

int	find_fd(int fd, t_list **backup)
{
	while (*backup != NULL && (*backup)->fd != fd)
		*backup = (*backup)->next;
	if (*backup == NULL)
		return (0);
	else
		return ((*backup)->fd);
}

char	*get_next_line(int fd)
{
	static t_list	*backup;
	char			*line;

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

//int main()
//{
//	int fd = open ("./1char.txt", O_RDWR);
//	char	*gnl;
//	gnl = get_next_line (fd);
//	printf ("%s \n", gnl);
//	gnl = get_next_line (fd);
//	printf ("%s \n", gnl);
//}
