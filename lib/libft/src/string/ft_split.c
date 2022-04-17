/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:07:55 by cjang             #+#    #+#             */
/*   Updated: 2022/04/17 21:50:26 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	find_start(char const *s, char *cset, size_t index)
{
	char	*cs;

	cs = cset;
	while (*cs != '\0')
	{
		if (index == 0 && *s == *cs)
			return (0);
		else if (index > 0 && s[index - 1] == *cs)
		{
			while (*cset != '\0')
			{
				if (s[index] == *cset)
					return (0);
				++cset;
			}
			return (1);
		}
		++cs;
	}
	if (index == 0)
		return (1);
	return (0);
}

static int	find_end(char const *s, char *cset, size_t index)
{
	char	*cs;

	cs = cset;
	while (*cs != '\0')
	{
		if (s[index] == *cs)
			return (0);
		++cs;
	}
	while (*cset != '\0')
	{
		if (s[index + 1] == *cset || s[index + 1] == 0)
			return (1);
		++cset;
	}
	return (0);
}

static char	*word_maker(char const *s, char *charset, size_t *i)
{
	char	*word;
	size_t	size;

	size = 0;
	while (!find_start(s, charset, *i))
		*i += 1;
	while (!find_end(s, charset, *i + size))
		size++;
	word = (char *)malloc(size + 2);
	if (!word)
		return (NULL);
	ft_strlcpy(word, &s[*i], size + 2);
	*i = *i + size + 1;
	return (word);
}

static char	**free_book(char **book, size_t index)
{
	while (index > 0)
		free(book[--index]);
	free(book);
	return (NULL);
}

char	**ft_split(char const *s, char *charset)
{
	char	**book;
	size_t	i;
	size_t	num;
	size_t	index;

	i = 0;
	num = 0;
	index = 0;
	if (!s)
		return (NULL);
	while (s[i])
		if (find_end(s, charset, i++))
			num++;
	book = (char **)malloc(sizeof(char *) * (num + 1));
	if (!book)
		return (NULL);
	i = 0;
	while (index < num)
	{
		book[index] = word_maker(s, charset, &i);
		if (!book[index++])
			return (free_book(book, index));
	}
	book[num] = NULL;
	return (book);
}
