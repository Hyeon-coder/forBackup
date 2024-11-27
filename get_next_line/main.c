#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	char *line1;
	char *line2;
	char *line3;
	int fd1;
	int	fd2;
	int	fd3;
	int i;

	fd1 = open("./test.txt", O_RDONLY);
	fd2 = open("./test2.txt", O_RDONLY);
	fd3 = open("./test3.txt", O_RDONLY);
	if (fd1 < 0 || fd2 < 0 || fd3 < 0) {
		perror("Failed to open file");
		return 1;
	}
	i = 1;
	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	line3 = get_next_line(fd3);
	while (i < 4) {
		printf("line [%d]: %s", i, line1);
		printf("line [%d]: %s", i, line2);
		printf("line [%d]: %s", i, line3);
		i++;
	}
	free(line1);
	free(line2);
	free(line3);
	close(fd1);
	close(fd2);
	close(fd3);
	return 0;
}
