/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/15 09:36:10 by rbraaksm      #+#    #+#                 */
/*   Updated: 2019/11/15 09:36:11 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*pstr;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	pstr = (char *)malloc(sizeof(*s1) * (len + 1));
	if (!pstr)
		return (NULL);
	while (i <= len)
	{
		pstr[i] = s1[i];
		i++;
	}
	return (pstr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*newstr;
	int			index;
	int			index2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	index = 0;
	index2 = 0;
	newstr = (char *)malloc(ft_strlen(s1) + (ft_strlen(s2) + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	while (s1[index] != '\0')
	{
		newstr[index] = s1[index];
		index++;
	}
	while (s2[index2] != '\0')
	{
		newstr[index + index2] = s2[index2];
		index2++;
	}
	newstr[index + index2] = '\0';
	return (newstr);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char*)&(s[i]));
		i++;
	}
	if (s[i] == '\0' && s[i] == (unsigned char)c)
		return ((char*)&(s[i]));
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*newstr;
	unsigned int	index;
	size_t			count;

	index = 0;
	count = 0;
	if (!s)
		return (NULL);
	while (s[index] != '\0')
		index++;
	if (!*s || start >= index)
		return (ft_strdup(""));
	if ((index - start) < len)
		newstr = (char *)malloc(sizeof(char) * ((index - start) + 1));
	else
		newstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (NULL);
	while (count < len)
	{
		newstr[count] = s[start + count];
		count++;
	}
	newstr[count] = '\0';
	return (newstr);
}
