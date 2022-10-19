/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalbako <ibalbako@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:41:02 by ibalbako          #+#    #+#             */
/*   Updated: 2022/03/07 15:25:32 by ibalbako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (0);
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*rtrn;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (in_set(s1[start], set) == 0)
		start++;
	if (start == ft_strlen(s1))
	{
		rtrn = ft_strdup("");
		if (!rtrn)
			return (NULL);
		else
			return (rtrn);
	}
	while (in_set(s1[end - 1], set) == 0)
		end--;
	rtrn = ft_substr(s1, start, end - start);
	return (rtrn);
}
