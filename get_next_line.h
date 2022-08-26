#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

typedef	struct s_list
{
	void	*content;
	struct	s_list	*next;
	int		fd;
}	t_list;

#endif
