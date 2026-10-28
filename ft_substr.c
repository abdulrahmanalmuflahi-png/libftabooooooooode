#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)

{
	size_t slen;
	// size_t i;
	char *suboptarg;

	if (!s)
	return (NULL);

	slen = ft_strlen(s);
	if (start >= slen)
	return (ft_strdup(""));

	if (len > slen - start)
		len = slen - start;

	  suboptarg = malloc (len + 1);
	  if (!suboptarg)
	  	return (NULL);
		ft_memcpy(suboptarg, s + start, len);
		suboptarg [len] = '\0';
		return(suboptarg);


	
}

// #include <stdio.h>
// #include <stdlib.h>
// int main  (void)
// {
// 	char *r;
// 	r = ft_substr("hello world", 4, 7);
// 	printf("[%s]\n", r);
// 	free(r);
// 	return 0;
// }



