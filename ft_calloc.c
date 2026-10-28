/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdulrahmanhussein <abdulrahmanhussein@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 02:02:40 by abdulrahman       #+#    #+#             */
/*   Updated: 2026/10/19 02:40:02 by abdulrahman      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // Includes our custom library containing malloc, NULL, size_t, and ft_bzero prototypes.

void    *ft_calloc(size_t count, size_t size) // Returns void* (generic pointer) because it can allocate memory for ANY type. size_t prevents negative sizes.
{
    void    *p; // Declares a generic pointer to store the address of the newly allocated memory.

    // OVERFLOW PROTECTION:
    // 'count' ensures we don't divide by zero.
    // 'size > (size_t)-1 / count' checks if multiplying them will exceed the maximum memory limit (Integer Overflow).
   	if (count == 0 || size == 0)
		return (malloc(1));

	if (count && size > (size_t)-1 / count)
        return (NULL); // If overflow is detected, abort and return NULL safely.

    p = malloc(count * size); // Allocates the total required bytes in the Heap and saves the start address in 'p'.

    // ALLOCATION PROTECTION:
    // Checks if malloc failed (e.g., computer ran out of RAM). '!p' is exactly like saying 'if (p == NULL)'.
    if (!p)
        return (NULL); // Abort immediately to prevent a Segmentation Fault crash in the next step.

    ft_bzero(p, count * size); // Cleans the allocated memory by filling it entirely with zeros, erasing any old garbage data.
    
    return (p); // Returns the safe, clean memory address back to the user.
}


#include <stdio.h>
#include <stdlib.h>

void    *ft_calloc(size_t count, size_t size);

int main(void)
{
    int *arr;
    int i;

    i = 0;
    // 1. نحجز 3 غرف، حجم كل غرفة هو حجم الـ int
    arr = ft_calloc(5, sizeof(int));

    // 2. نمشي على الغرف الثلاث ونطبع محتواها (المفروض تطبع 0)
    while (i < 5)
    {
        printf("Room %d: %d\n", i, arr[i]);
        i++;
    }

    // 3. نرجع المفتاح (الذاكرة) للكمبيوتر
    free(arr);
    
    return (0);
}

// #include "libft.h"

// void	*ft_calloc(size_t count, size_t size)
// {
// 	void	*p;

// 	if (count && size > (size_t)-1 / count)
// 		return (NULL);
// 	p = malloc(count * size);
// 	if (!p)
// 		return (NULL);
// 	ft_bzero(p, count * size);
// 	return (p);
// }
