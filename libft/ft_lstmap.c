#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*elm;

	if (!f || !lst)
		return (NULL);
	new = NULL;
	while (lst)
	{
		elm = ft_lstnew((*f)(lst->content));
		if (!elm)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, elm);
		lst = lst->next;
	}
	return (new);
}
