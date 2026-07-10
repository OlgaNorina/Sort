#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*cpy;

	len = ft_strlen(s) + 1;
	cpy = malloc(len);
	if (cpy)
	{
		ft_strlcpy(cpy, s, len);
		return (cpy);
	}
	return (0);
}