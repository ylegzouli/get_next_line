#include "get_next_line.h"

int		main()
{
	int		fd;
	int		ret;
	char	*line;

	*line = NULL;
	fd = open("test", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		
