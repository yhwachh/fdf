#include "libft.h"

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*dst;
	int		i;
	int		k;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	i = 0;
	k = 0;
	dst = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)
		return (NULL);
	while (s1[i] != '\0')
		dst[k++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		dst[k++] = s2[i++];
	dst[k] = '\0';
	free (s1);
	return (dst);
}