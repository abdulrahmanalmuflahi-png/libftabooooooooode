#include "libft.h"

char    *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t  i;
    size_t  j;

    // 1. حالة الإبرة الوهمية (فارغة)
    if (needle[0] == '\0')
        return ((char *)haystack);
        
    i = 0;
    // 2. اللوب الخارجي: المشي في كومة القش
    while (haystack[i] != '\0' && i < len)
    {
        j = 0;
        // 3. اللوب الداخلي (الرادار): فحص التطابق حرفاً بحرف
        while (haystack[i + j] == needle[j] && (i + j) < len)
        {
            // إذا كان الحرف القادم في الإبرة هو نهاية النص، وجدنا الكلمة
            if (needle[j + 1] == '\0')
                return ((char *)&haystack[i]);
            j++;
        }
        i++;
    }
    return (NULL);
}
#include <stdio.h>
#include <string.h>

// توقيع دالتك عشان الكومبايلر يعرفها
char    *ft_strnstr(const char *haystack, const char *needle, size_t len);

int main(void)
{
    // 1. النص الطويل (كومة القش)
    char haystack[] = "42 Abu Dhabi";
    
    // 2. الكلمة اللي نبحث عنها (الإبرة)
    char needle[] = "u";
    
    // 3. النتيجة (المؤشر اللي بيرجع لنا)
    char *result;

    // نستدعي الدالة ونعطيها مسافة 15 حرف عشان تبحث براحتها
    result = ft_strnstr(haystack, needle, 15);

    // 4. نطبع النتيجة
    if (result != NULL)
    {
        printf("Success! We found it: %s\n", result);
    }
    else
    {
        printf("Failed! Word not found.\n");
    }

    return (0);
}