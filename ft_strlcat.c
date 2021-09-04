#include "libft.h"

char	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_count;
	size_t	dst_count;
	size_t	dst_len;

	src_count = 0;
	dst_count = 0;
	dst_len = ft_strlen(dst);
	if (size <= dst_len)
		return (size + ft_strlen(src));
	while (*(dst + dst_count))
		dst_count++;
	while (*(src + src_count) && (dst_count < (size - 1)))
	{
		*(dst + dst_count) = *(src + src_count);
		dst_count++;
		src_count++;
	}
	*(dst + dst_count) = '\0';
	return (dst_len + ft_strlen(src));
}
