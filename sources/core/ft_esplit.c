#include "../../includes/push_swap.h"

static int	wcount(char *s, char c)
{
	int		count;
	bool	nextword;

	count = 0;
	while (*s)
	{
		nextword = false;
		while (*s == c)
			s++;
		while (*s != c && *s)
		{
			if (!nextword)
			{
				count++;
				nextword = true;
			}
			s++;;
		}
	}
	return (count);
}

static char	*get_next_word(char *s, char c)
{
	static int	index = 0;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[index] == c)
		index++;
	while ((s[index + len] != c) && s[index + len])
		len++;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((s[index] != c) && s[index])
		next_word[i++] = s[index++];
	next_word[i] = '\0';
	return (next_word);
}

char **ft_esplit(char *s, char c)
{
	int		words_count;
	char	**result_array;
	int		i;

	i = 0;
	words_count = wcount(s, c);
	if (!words_count)
		exit(1);
	result_array = malloc((size_t)(words_count + 2) * sizeof(char *));
	if (!result_array)
		return (NULL);
	while (words_count-- >= 0)
	{
		if (i == 0)
		{
			result_array[i] = malloc(sizeof(char));
			if (!result_array[i])
				return (NULL);
			result_array[i++][0] = '\0';
			continue ;
		}
		result_array[i++] = get_next_word(s, c);
	}
	result_array[i] = NULL;
	return (result_array);
}