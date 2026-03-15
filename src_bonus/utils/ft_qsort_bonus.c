/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:46:28 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/15 20:20:31 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <aio.h>
#include <stdlib.h>
#include <stdbool.h>

static ssize_t	partition(char *base, size_t size, size_t nmemb,
					int (*compar)(const void*, const void*));
static void		*decide_pivot(char *base, size_t size, size_t nmemb,
					int (*compar)(const void*, const void*));

void			ft_swap(void *a, void *b, size_t size);

// left = 0;
// right = size - 1;
/*
@brief QUICK sort in Ascending order(1, 2, 3, ...)
*/
void	ft_qsort(char *base, size_t nmemb, size_t size,
				int (*compar)(const void*, const void*))
{
	ssize_t	last_idx;

	if (nmemb <= 1)
		return ;
	last_idx = partition(base, size, nmemb, compar);
	ft_qsort(base, last_idx + 1, size, compar);
	ft_qsort(base + (last_idx + 1) * size, nmemb - (last_idx + 1),
		size, compar);
	return ;
}

static ssize_t	partition(char *base, size_t size, size_t nmemb,
						int (*compar)(const void*, const void*))
{
	void		*pivot_p;
	static char	pivot[4096];
	ssize_t		l;
	ssize_t		r;

	pivot_p = decide_pivot(base, size, nmemb, compar);
	ft_memcpy(pivot, pivot_p, size);
	l = -1;
	r = nmemb;
	while (l < r)
	{
		while ((*compar)(base + (++l) * size, &pivot) < 0)
			;
		while ((*compar)(&pivot, base + (--r) * size) < 0)
			;
		if (l >= r)
			break ;
		ft_swap(base + l * size, base + r * size, size);
	}
	return (r);
}

static void	*decide_pivot(char *base, size_t size, size_t nmemb,
						int (*compar)(const void*, const void*))
{
	ssize_t	tail;
	ssize_t	center;

	tail = (nmemb - 1);
	center = tail / 2;
	if (!(*compar)(base, base + center * size))
	{
		if ((*compar)(base + center * size, base + tail * size))
			return (base + center * size);
		else if ((*compar)(base, base + tail * size))
			return (base + tail * size);
		else
			return (base);
	}
	else
	{
		if ((*compar)(base, base + tail * size))
			return (base);
		else if ((*compar)(base + center * size, base + tail * size))
			return (base + tail * size);
		else
			return (base + center * size);
	}
}

// #include <stdio.h>
// static int	charcomp(const void *lhs, const void *rhs) {
// 	unsigned char	_lhs = *(unsigned char *)lhs;
// 	unsigned char	_rhs = *(unsigned char *)rhs;

// 	return ((int)_lhs - (int)_rhs);
// }
// int	main(int argc, char *argv[])
// {
// 	for (int i = 1; i < argc; i++) {
// 		ft_qsort(argv[i], ft_strlen(argv[i]), sizeof(char), charcomp);
// 		fprintf(stderr, "%s\n", argv[i]);
// 	}
// 	return (0);
// }

// // structure test
// #include <stdio.h>
// typedef struct s_obj
// {
// 	int		*date_p;
// 	char	_;
// 	size_t	aaa;
// 	void	*p;
// }	t_obj;

// int	compare_obj(const void *a, const void *b)
// {
// 	t_obj	obj_a = *(const t_obj *)a;
// 	t_obj	obj_b = *(const t_obj *)b;

// 	return (*obj_a.date_p - *obj_b.date_p);
// }

// void	print_obj_sort(t_obj arr[])
// {
// 	fprintf(stderr,
//	"before:\ta:%d b:%d c:%d d:%d\n",
//	*arr[0].date_p, *arr[1].date_p, *arr[2].date_p, *arr[3].date_p);
// 	ft_qsort((char *)arr, 4, sizeof(t_obj), compare_obj);
// 	// ft_swap(arr, arr+1, sizeof(t_obj));
// 	fprintf(stderr,
//	"after:\ta:%d b:%d c:%d d:%d\n",
//	*arr[0].date_p, *arr[1].date_p, *arr[2].date_p, *arr[3].date_p);
// }

// int	main(void)
// {
// 	int		one = 1;
// 	int		two = 2;
// 	int		three = 3;
// 	int		four = 4;
// 	t_obj	a = {.date_p = &one};
// 	t_obj	b = {.date_p = &two};
// 	t_obj	c = {.date_p = &three};
// 	t_obj	d = {.date_p = &four};

// 	t_obj	arr1[] = {a, b, c, d};
// 	t_obj	arr2[] = {c, d, a, b};
// 	t_obj	arr3[] = {b, c, d, a};
// 	print_obj_sort(arr1);
// 	print_obj_sort(arr2);
// 	print_obj_sort(arr3);
// }

// // sorting test
// #include <stdio.h>
// static int	char_cmp(const void *a, const void *b)
// {
// 	const unsigned char _a = *(const unsigned char *)a;
// 	const unsigned char _b = *(const unsigned char *)b;

// 	return (int)_a - (int)_b;
// }

// static int	is_in_order(char *s, size_t len)
// {
// 	char	prev;
// 	size_t	i;

// 	i = 0;
// 	prev = 0;
// 	while (i < len)
// 	{
// 		if (s[i] < prev)
// 			return (0);
// 		prev = s[i];
// 		i++;
// 	}
// 	return (1);
// }

// static void	print_sort(void *a)
// {
// 	size_t	len;

// 	len = ft_strlen((char *)a);
// 	fprintf(stderr, "before:\t%s\n", (char *)a);
// 	ft_qsort((char *)a, len, sizeof(char), char_cmp);
// 	fprintf(stderr, "after:\t%s", (char *)a);
// 	if (!is_in_order((char *)a, len))
// 		fprintf(stderr, "  <-----Error!!");
// 	fprintf(stderr, "\n");
// }

// static void	print_sort_arr(void **arr, size_t nmemb)
// {
// 	for (int i = 0; i < nmemb; i++)
// 		print_sort(arr[i]);
// }

// static void	clear_str_arr(char **str_arr, int size);

// int	main(void)
// {
// 	static char	table[][5] = {
// 		"a",
// 		"ab",
// 		"ba",
// 		"abc",
// 		"acb",
// 		"bac",
// 		"bca",
// 		"cab",
// 		"cba",
// 		"abcd",
// 		"abdc",
// 		"acbd",
// 		"acdb",
// 		"adbc",
// 		"adcb",
// 		"bacd",
// 		"badc",
// 		"bcad",
// 		"bcda",
// 		"bdac",
// 		"bdca",
// 		"cabd",
// 		"cadb",
// 		"cbad",
// 		"cbda",
// 		"cdab",
// 		"cdba",
// 		"dabc",
// 		"dacb",
// 		"dbac",
// 		"dbca",
// 		"dcab",
// 		"dcba",
// 		"abcde",
// 		"abced",
// 		"abdce",
// 		"abdec",
// 		"abecd",
// 		"abedc",
// 		"acbde",
// 		"acbed",
// 		"acdbe",
// 		"acdeb",
// 		"acebd",
// 		"acedb",
// 		"adbce",
// 		"adbec",
// 		"adcbe",
// 		"adceb",
// 		"adebc",
// 		"adecb",
// 		"aebcd",
// 		"aebdc",
// 		"aecbd",
// 		"aecdb",
// 		"aedbc",
// 		"aedcb",
// 		"bacde",
// 		"baced",
// 		"badce",
// 		"badec",
// 		"baecd",
// 		"baedc",
// 		"bcade",
// 		"bcaed",
// 		"bcdae",
// 		"bcdea",
// 		"bcead",
// 		"bceda",
// 		"bdace",
// 		"bdaec",
// 		"bdcae",
// 		"bdcea",
// 		"bdeac",
// 		"bdeca",
// 		"beacd",
// 		"beadc",
// 		"becad",
// 		"becda",
// 		"bedac",
// 		"bedca",
// 		"cabde",
// 		"cabed",
// 		"cadbe",
// 		"cadeb",
// 		"caebd",
// 		"caedb",
// 		"cbade",
// 		"cbaed",
// 		"cbdae",
// 		"cbdea",
// 		"cbead",
// 		"cbeda",
// 		"cdabe",
// 		"cdaeb",
// 		"cdbae",
// 		"cdbea",
// 		"cdeab",
// 		"cdeba",
// 		"ceabd",
// 		"ceadb",
// 		"cebad",
// 		"cebda",
// 		"cedab",
// 		"cedba",
// 		"dabce",
// 		"dabec",
// 		"dacbe",
// 		"daceb",
// 		"daebc",
// 		"daecb",
// 		"dbace",
// 		"dbaec",
// 		"dbcae",
// 		"dbcea",
// 		"dbeac",
// 		"dbeca",
// 		"dcabe",
// 		"dcaeb",
// 		"dcbae",
// 		"dcbea",
// 		"dceab",
// 		"dceba",
// 		"deabc",
// 		"deacb",
// 		"debac",
// 		"debca",
// 		"decab",
// 		"decba",
// 		"eabcd",
// 		"eabdc",
// 		"eacbd",
// 		"eacdb",
// 		"eadbc",
// 		"eadcb",
// 		"ebacd",
// 		"ebadc",
// 		"ebcad",
// 		"ebcda",
// 		"ebdac",
// 		"ebdca",
// 		"ecabd",
// 		"ecadb",
// 		"ecbad",
// 		"ecbda",
// 		"ecdab",
// 		"ecdba",
// 		"edabc",
// 		"edacb",
// 		"edbac",
// 		"edbca",
// 		"edcab",
// 		"edcba",
// 	};
// 	void	**arr;
// 	int		nmemb;

// 	nmemb = sizeof(table) / sizeof(*table);
// 	arr = ft_calloc(nmemb, sizeof(*arr));
// 	if (!arr)
// 		return (1);
// 	for (int i = 0; i < nmemb; i++)
// 	{
// 		arr[i] = ft_strdup(table[i]);
// 		if (!arr[i])
// 		{
// 			clear_str_arr((char **)arr, i);
// 			return (1);
// 		}
// 	}
// 	print_sort_arr(arr, nmemb);
// 	clear_str_arr((char **)arr, nmemb);
// }

// static void	clear_str_arr(char **str_arr, int nmemb)
// {
// 	for (int i = 0; i < nmemb; i++)
// 		free(str_arr[i]);
// 	free(str_arr);
// 	return ;
// }
