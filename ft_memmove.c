#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dst && !src)
		return (dst);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d < s)
		return (ft_memcpy(dst, src, len));
	while (len--)
		d[len] = s[len];
	return (dst);
}
 
#include <stdio.h>
int main (void)
{
	char source[] = "ahmed"; 

    // 2. الوجهة: صندوق فاضي (حطيت فيه نقاط عشان تشوف التغيير بعينك)
    char destination[] = "hhhhh"; 

    // 3. أمر النسخ:
    // انسخ إلى (destination) 
    // من (source)
    // عدد (5) حروف
    ft_memmove(destination, source, 5);

    // 4. طباعة الصندوقين عشان نشوف النتيجة
    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);

    return (0);
}
