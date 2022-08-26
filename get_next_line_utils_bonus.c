#include "get_next_line.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == 0)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst)
	t_list	*tmplst;

	if (lst == 0)
		return ;
	else if (*lst == 0)
		*lst = new;
	else
	{
		tmplst = ft_lstlast(*lst);
		tmplst->next = new;
	}
}

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list == 0)
		return (0);
	list->content = content;
	list->next = 0;
	list->fd = 3; 
	return (list);
}

