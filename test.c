#include "libft.h"

int	main(void)
{
	char	*s = "Hello World";
	int	start = 7;

	printf("%zu\n", ft_strlen(s));
	printf("%zu\n", ft_strlen(s + start));
//	if (ft_strlen(s + start) < len)
//		printf("here is!!");
	return 0;
}
