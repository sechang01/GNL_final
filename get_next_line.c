/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:51:00 by sechang           #+#    #+#             */
/*   Updated: 2018/08/14 23:41:43 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	nodemem(t_gnl *mem, t_gnl **memo, int fd)
{
	if (mem)
	{
		mem->fd = fd;
		mem->x = -2;
		mem->next = NULL;
		mem->store = (char *)ft_memalloc(sizeof(char) * BUFF_SIZE + 1);
		mem->tmp = NULL;
	}
	if (memo)
	{
		(*memo)->fd = fd;
		(*memo)->x = -2;
		(*memo)->next = NULL;
		(*memo)->store = (char *)ft_memalloc(sizeof(char) * BUFF_SIZE + 1);
		(*memo)->tmp = NULL;
	}
}

t_gnl	*fdcheck(t_gnl **gnl, int fd)
{
	t_gnl			*i;
	t_gnl			*new;

	if (*gnl == NULL)
	{
		*gnl = (t_gnl *)ft_memalloc(sizeof(t_gnl));
		nodemem(0, gnl, fd);
		return (*gnl);
	}
	i = *gnl;
	while (i->fd != fd)
	{
		if (!(i->next))
		{
			if (!(new = (t_gnl *)ft_memalloc(sizeof(t_gnl))))
				return (NULL);
			i->next = new;
			nodemem(new, 0, fd);
			return (new);
		}
		i = i->next;
	}
	return (i);
}

char	*expandstr(char *line)
{
	char			*tmp;

	tmp = ft_strdup(line);
	free(line);
	if (!(line = (char *)ft_memalloc(sizeof(char) * BUFF_SIZE + \
					ft_strlen(tmp) + 1)))
		return (NULL);
	ft_strcpy(line, tmp);
	free(tmp);
	return (line);
}

int		ret_and_store(char *stuf, t_gnl *pgnl, char *line, int j)
{
	int				i;

	i = 0;
//	printf("STUF=%s\n", stuf);
	while (stuf[i])
	{
		line[j++] = (stuf[i++] == '\n') ? '\0' : stuf[i - 1];
		if (stuf[i - 1] == '\n')
		{
			pgnl->tmp = ft_strdup(stuf + i);
			free(pgnl->store);
			pgnl->store = ft_strdup(pgnl->tmp);
			free(pgnl->tmp);
			pgnl->x = -1;
//			if (BUFF_SIZE == 1)
//				pgnl->x = BUFF_SIZE + 1;
			break ;
		}
	}
	if (pgnl->x != -1)
	{
		pgnl->store[0] = '\0';
		pgnl->x = -3;
	}
	line[j] = '\0';

//	printf("STORE=%s\n", pgnl->store);
//	printf("LINE=%s\n", line);
	return (j);	
	if (BUFF_SIZE == 1)
	{
		return ((!pgnl->x)) ? (-1) : (j);
	}
	else
		return (pgnl->x > 0 && pgnl->x < BUFF_SIZE) ? (-1) : (j);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*gnl;
	t_gnl			*pgnl;
	char			buf[BUFF_SIZE + 1];
	int				j;

	j = 0;
//	printf("\n\\\\\\\\\\\\\\NEWSTART\n");
	pgnl = fdcheck(&gnl, fd);
	pgnl->x = -2;
//	printf("NEWSTORE=%s\n", pgnl->store);
	if (fd < 0 || !line || (read(fd, buf, 0) < 0 || BUFF_SIZE < 1) || \
			(!(*line = (char *)ft_memalloc(sizeof(char) * BUFF_SIZE + 1 + \
											ft_strlen(pgnl->store)))))
		return (-1);

	if ((pgnl->store[0]))
	{
	//	printf("STOR @@\n");
		j = ret_and_store(pgnl->store, pgnl, *line, j);
	//	printf("line=%c\n", *line[0]);
	//	printf("pgnlx=%d\n", pgnl->x);
		if (pgnl->x == -1)
		{
//			printf("test\n");
			return (1);
		}
	}
//	prinitf("Outside.X=%d\n", pgnl->x);
		
	while (!(pgnl->store[0]) && (pgnl->x = read(fd, buf, BUFF_SIZE)))
	{
//		printf("BUF @@\n");
		buf[pgnl->x] = '\0';
//		printf("X=%d\n", pgnl->x);
		j = ret_and_store(buf, pgnl, *line, j);

		if (pgnl->x == -3)
			*line = expandstr(*line);
		else
			break ;
	}
	return ((*line[0]) || pgnl->x == -1) ? (1) : (0);
}
