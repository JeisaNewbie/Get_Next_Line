#include "get_next_line.h"

char	*ft_strdup(const char *s1, int buffer_size)
{
	char	*tmp;
	int		i;

	tmp = (char *)malloc(sizeof(char) * (buffer_size + 1));
	if (tmp == 0)
		return (0);
	i = 0;
	while (i < buffer_size)
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[buffer_size] = '\0';
	return (tmp);
}

int	ft_strrchr(char *s, int c)
{
	char	*string;
	char	ch;
	int		i;

	string = (char *)s;
	ch = (char)c;
	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (string[i] == ch)
			return (i);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	len_dns;
	size_t	size;

	len_src = 0;
	len_dst = 0;
	while (src[len_src] != '\0')
		len_src++;
	while (dst[len_dst] != '\0' && len_dst < BUFFER_SIZE)
		len_dst++;
	len_dns = len_dst + len_src;
	if (dstsize <= len_dst)
		return (dstsize + len_src);
	size = dstsize - len_dst - 1;
	while (*src != '\0' && size > 0)
	{
		dst[len_dst] = *src;
		src++;
		len_dst++;
		size--;
	}
	dst[len_dst] = '\0';
	return (len_dns);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	int		len_s1;

	len_s1 = ft_strlen(s1);
	tmp = (char *)malloc(sizeof(char) * (len_s1 + BUFFER_SIZE + 1));
	if (tmp == 0)
		return (0);
	tmp[0] = '\0';
	ft_strlcat(tmp, s1, len_s1 + 1);
	ft_strlcat(tmp, s2, len_s1 + BUFFER_SIZE + 1);
	tmp[len_s1 + BUFFER_SIZE] = '\0';
	return (tmp);
}
