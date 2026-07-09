#include "libft.h"

static void	free_allocated(char **allocated, int count)
{
	while (count--)
	{
		free(allocated[count]);
	}
	free(allocated);
}

static int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	**split_string(char const *s, char c, char **res)
{
	int	i;
	int	len;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		res[i] = ft_substr(s, 0, len);
		if (!res[i])
		{
			free_allocated(res, i);
			return (NULL);
		}
		i++;
		s += len;
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		size;

	if (!s)
		return (NULL);
	size = count_words(s, c) + 1;
	res = malloc(sizeof(char *) * size);
	if (!res)
		return (NULL);
	res = split_string(s, c, res);
	return (res);
}