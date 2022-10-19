#include "libft.h"

static int	ft_sep(char const *s, char c)
{
	int	t;
	int	n;

	t = 0;
	n = 0;
	while (s[t] != '\0')
	{
		if (s[t] == c && s[t + 1] != '\0' && s[t + 1] != c)
			++n;
		++t;
	}
	++n;
	return (n);
}

static char	*malloc_size(char const *s, char c)
{
	char	*size;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		++i;
	size = malloc(sizeof(char) * (i + 1));
	if (!size)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		size[i] = s[i];
		++i;
	}
	size[i] = '\0';
	return (size);
}

static void	*ft_free_all(char **tab, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		sep;
	int		j;

	j = 0;
	sep = ft_sep(s, c);
	tab = malloc(sizeof(char *) * (sep + 1));
	if (!tab)
		return (ft_free_all(tab, sep));
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			tab[j] = malloc_size(s, c);
			++j;
			while (*s && *s != c)
				s++;
		}
	}
	tab[j] = NULL;
	return (tab);
}