#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	f;
	int				i;

	f = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (f == (const unsigned char)s[i])
			return ((char *)s + i);
		i++;
	}
	if (f == '\0')
		return ((char *)s + i);
	return (0);
}