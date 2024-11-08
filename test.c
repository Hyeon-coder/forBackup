#include "libft.h"

int	main(void)
{
	/* ft_atoi
	printf("ft : %d\n", ft_atoi("546:5"));
	printf("%d\n", atoi("546:5"));
	printf("--------------\n");
	printf("ft : %d\n", ft_atoi("+548"));
	printf("%d\n", atoi("+548"));
	printf("--------------\n");
	printf("ft : %d\n", ft_atoi("--47"));
	printf("%d\n", atoi("--47"));
	*/
	/* ft_strncmp
	printf("ft : %d\n", ft_strncmp("test\200", "test\0", 6));
	printf("%d\n", strncmp("test\200", "test\0", 6));
	printf("ft : %d\n", ft_strncmp("abc", "abd", 3));
	printf("%d\n", strncmp("abc", "abd", 3));
	*/
	/*	ft_strrchr
	char	str2[] = "bonjour";
	printf("ft : %s\n", ft_strrchr(str2, 'b'));
	printf("%s\n", strrchr(str2, 'b'));
	printf("ft : %s\n", ft_strrchr(str2, '\0'));
	printf("%s\n", strrchr(str2, '\0'));
	*/
//	printf("ft : %s\n", ft_itoa(-2147483648LL));
	/*
	int	i = 0;
	while (i <= 47)
	{
		ft_putchar_fd(i, 2);
		i++;
	}
	*/
	char	s1[] = "lorem ipsum";
	char	s2[] = "dolor sit amet";

	printf("ft : %s\n", ft_strjoin(s1, s2));
	printf("\n");

	s1[0] = '\0';
	printf("ft : %s\n", ft_strjoin(s1, s2));
	printf("\n");

	s2[0] = '\0';
	printf("ft : %s\n", ft_strjoin(s1, s2));
	printf("\n");

	char	s3[] = "lorem ipsum";
	printf("ft : %s\n", ft_strjoin(s3, s2));
	printf("\n");
	return 0;
}
