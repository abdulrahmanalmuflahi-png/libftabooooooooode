/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdulrahmanhussein <abdulrahmanhussein@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 02:01:03 by abdulrahman       #+#    #+#             */
/*   Updated: 2026/10/19 13:37:17 by abdulrahman      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strdup(const char *s1)
{
    char    *dup; // Pointer to store the address of the newly allocated string.
    size_t  len;  // Variable to store the length of the original string.

    len = ft_strlen(s1); // 1. Calculate the exact length of the original string 's1'.
    
    // 2. Allocate memory: 'len' for the characters + 1 extra byte for the null terminator '\0'.
    dup = malloc(len + 1);

    // 3. Protection: If malloc fails (out of memory), abort and return NULL to prevent crashes.
    if (!dup)
        return (NULL);

    // 4. Copy the data from source (s1) to destination (dup). We copy (len + 1) to safely include the '\0'.
    ft_memcpy(dup, s1, len + 1);
    
    return (dup); // 5. Return the pointer to the brand new, duplicated string.
}
// #include <stdio.h>
// #include <stdlib.h>
// int main(void)

// {
// 	char    *original;
//     char    *copy;

//     // 1. هذا النص الأصلي
//     original = "Hello 42 Abu Dhabi!";

//     // 2. نطلب من دالتك تسوي نسخة منه وتحجز لها مكان
//     copy = ft_strdup(original);

//     // 3. نطبع النسخة عشان نتأكد أنها تطابقت
//     if (copy != NULL) // نتأكد إن الحجز نجح قبل ما نطبع
//     {
//         printf("Original : %s\n", original);
//         printf("My Copy  : %s\n", copy);
        
//         // 4. مهم جداً: نرجع المساحة للكمبيوتر بعد ما نخلص
//         free(copy);
//     }
//     else
//     {
//         printf("Error: Malloc failed!\n");
//     }

//     return (0);
	
// }










// {
// 	char	*dup;
// 	size_t	len;

// 	len = ft_strlen(s1);
// 	dup = malloc(len + 1);
// 	if (!dup)
// 		return (NULL);
// 	ft_memcpy(dup, s1, len + 1);
// 	return (dup);
// }
