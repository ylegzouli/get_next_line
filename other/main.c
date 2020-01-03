#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		main()
{
	int		fd;
	int		ret;
	char	*line;

	fd = open("test", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("[%d] %s\n", ret, line);
		free(line);
	}
	printf("[%d] %s\n", ret, line);
	free(line);
	while(1)
	{}
}
