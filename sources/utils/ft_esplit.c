/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergoh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:25:27 by jergoh            #+#    #+#             */
/*   Updated: 2023/09/21 10:25:30 by jergoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

static char	**free_array(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (0);
}

static int	count_words(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*put_word(char *word, char *s, int start, int word_len)
{
	int	j;

	j = 0;
	while (word_len > 0)
	{
		word[j] = s[start - word_len];
		j++;
		word_len--;
	}
	word[j] = '\0';
	return (word);
}

static char	**split_words(char *s, char c, char **result, int num_words)
{
	static int	tracker = 0;
	int			word;
	int			word_len;
	int			start;

	word = 0;
	while (word < num_words)
	{
        word_len = 0;
		while (s[tracker] && s[tracker] == c)
			tracker++;
		start = tracker;
		while (s[tracker] && s[tracker] != c)
		{
			tracker++;
			word_len++;
		}
		result[word] = (char *)malloc((word_len + 1) * sizeof(char));
		if (!result[word])
			return (free_array(result, word));
		put_word(result[word], s, start + word_len, word_len);
		word++;
	}
	result[word] = '\0';
	return (result);
}

char	**ft_esplit(char *s, char c)
{
	int		words_count;
	char	**result;
	int		i;

	i = 0;
	words_count = count_words(s, c);
	if (!words_count)
		exit(1);
	result = (char **)malloc((words_count + 2) * sizeof(char *));
	if (!result)
		return (NULL);
	if (s[0] == c)
	{
		result[i] = (char *)malloc(sizeof(char));
		if (!result[i])
			return (NULL);
		result[i++][0] = '\0';
	}
	result = split_words(s, c, result, words_count);
	return (result);
}