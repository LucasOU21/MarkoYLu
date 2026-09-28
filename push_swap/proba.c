#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


int main(void)
{
	int fd = open("test.c", O_WRONLY | O_CREAT | O_APPEND, 0644);

	if (fd == -1)
	{
		printf("Error while opening the file\n");
		return (1);
	}
	for (int i = 0; i < 1000; i++)
	{
	write(fd, "sa append\n", 10);
	}
	close(fd);


	return 0;
}