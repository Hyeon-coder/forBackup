#include "libft.h"

int	main(void)
{
	printf("ft : %d\n", ft_atoi("546:5"));
	printf("%d\n", atoi("546:5"));
	printf("--------------\n");
	printf("ft : %d\n", ft_atoi("+548"));
	printf("%d\n", atoi("+548"));
	printf("--------------\n");
	printf("ft : %d\n", ft_atoi("--47"));
	printf("%d\n", atoi("--47"));
	return 0;
}
