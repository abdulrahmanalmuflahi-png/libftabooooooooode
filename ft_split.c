#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*copy_word(char const *s, int len)
{
	char	*word;
	int		i;

	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;
	int		len;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len = 0;
			while (s[i + len] && s[i + len] != c)
				len++;
			result[j] = copy_word(s + i, len);
			if (!result[j])
			{
				while (j > 0)
					free(result[--j]);
				free(result);
				return (NULL);
			}
			j++;
			i += len;
		}
	}
	result[j] = NULL;
	return (result);
}



// #include "libft.h"

// static size_t	count_words(const char *s, char c)
// {
// 	size_t	n;

// 	n = 0;
// 	while (*s)
// 	{
// 		while (*s == c)
// 			s++;
// 		if (*s)
// 		{
// 			n++;
// 			while (*s && *s != c)
// 				s++;
// 		}
// 	}
// 	return (n);
// }

// static void	free_all(char **arr, size_t n)
// {
// 	while (n--)
// 		free(arr[n]);
// 	free(arr);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**res;
// 	size_t	i;
// 	size_t	len;

// 	if (!s)
// 		return (NULL);
// 	res = malloc((count_words(s, c) + 1) * sizeof(char *));
// 	if (!res)
// 		return (NULL);
// 	i = 0;
// 	while (*s)
// 	{
// 		while (*s == c)
// 			s++;
// 		if (!*s)
// 			break ;
// 		len = 0;
// 		while (s[len] && s[len] != c)
// 			len++;
// 		res[i] = ft_substr(s, 0, len);
// 		if (!res[i++])
// 			return (free_all(res, i - 1), NULL);
// 		s += len;
// 	}
// 	res[i] = NULL;
// 	return (res);
// }
