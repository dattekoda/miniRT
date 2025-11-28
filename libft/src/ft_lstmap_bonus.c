/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:06:01 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/05/02 21:38:17 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*p;
	void	*tmp;

	new_list = NULL;
	while (lst)
	{
		tmp = f(lst->content);
		p = ft_lstnew(tmp);
		if (!p)
		{
			del(tmp);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, p);
		lst = lst->next;
	}
	return (new_list);
}

/*
void *lstmap_f(void *content);

int main(void)
{
	t_list	*ret;
	t_list	*l;
	l = ft_lstnew(ft_strdup("abc"));
	l->next = ft_lstnew(ft_strdup("ABC"));
	l->next->next = ft_lstnew(ft_strdup("(x_x)"));
	ret = ft_lstmap(l, &lstmap_f, &free);
	while (ret)
	{
		printf("%s\n", (char *)ret->content);
		ret = ret->next;
	}
	return (0);
}

void *lstmap_f(void *content)
{
    if (!content)
        return NULL;
    return ft_strdup((char *)content);
}
*/