#include "get_next_line.h"
#include "./libft/includes/libft.h"

int		main(int argc, char **argv)
{
	int	fd[3];
	char *line;
	int i;
	int	j;

	line = (char *)ft_memalloc(sizeof(char) * 1);
	j = 0;
	while (j <= 2)
	{
		fd[j] = open(argv[j + 1], O_RDONLY);
		j++;
	}

	i = 0;
	while (i < 100)
	{
		j= 0;
		//j = i % 3;
		//j = i * i * 26236 % 3;
		printf("\nReading from argv[%d]:\t%s", j + 1, argv[j]);
		printf("~~~!!!!!.RET=%d", get_next_line(fd[j], &line));
		printf("\nReading from argv[%d]:\t%s", j + 1, argv[j]);
		printf("\n\t@@@ MAIN FUNC GNL: \n%s\n", line);
		getchar();
		i++;
	}
//	free(line);
	return (0);
}
