#include "syscall_mock.h"
#include "libft.h"
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

void	*__wrap_malloc(size_t size)
{
	static int	called_count = 0;
	void	*p;
	t_list	*new_node;

	if (err_syscall == MALLOC)
	{
		called_count++;
		if (called_count % 3)
		{
			errno = _wrap_errno_;
			return (NULL);
		}
	}
	p = __real_malloc(size);
	if (!p)
		return (NULL);
	new_node = __real_malloc(sizeof(*new_node));
	if (!new_node)
	{
		__real_free(p);
		return (NULL);
	}
	new_node->content = p;
	new_node->next = NULL;
	ft_lstadd_back(&dummy_head.next, new_node);
	return (p);
}

void	__wrap_free(void *ptr)
{
	t_list	*cur;
	t_list	*prev;

	cur = dummy_head.next;
	prev = &dummy_head;
	while (cur)
	{
		if (cur->content == ptr)
		{
			prev->next = cur->next;
			__real_free(cur->content);
			__real_free(cur);
			return ;
		}
		prev = cur;
		cur = cur->next;
	}
	fprintf(stderr, "ERROR: invalid free.\n");
	abort();
}

bool	is_memory_leaked(void)
{
	return (dummy_head.next != NULL);
}

ssize_t	__wrap_read(int fd, void *buf, size_t count)
{
	if (err_syscall == READ)
	{
		errno = _wrap_errno_;
		return (-1);
	}
	return (__real_read(fd, buf, count));
}

int	__wrap_open(const char *pathname, int flags)
{
	if (err_syscall == OPEN)
	{
		errno = _wrap_errno_;
		return (-1);
	}
	return (__real_open(pathname, flags));
}
