/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:51:00 by sechang           #+#    #+#             */
/*   Updated: 2018/08/13 12:27:19 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Uses libft functions: memset, memalloc, strlen, strcpy, and strdup
*/

void	nodemem(t_gnl *mem, t_gnl **memo, int fd)
{
	if (mem)
	{
		mem->fd = fd;
		mem->key = 0;
		mem->next = NULL;
		mem->store = (char *)ft_memalloc(sizeof(char) * BUFF_SIZE + 1);
	}
	if (memo)
	{
		(*memo)->fd = fd;
		(*memo)->key = 0;
		(*memo)->next = NULL;
		(*memo)->store = (char *)ft_memalloc(sizeof(char) * BUFF_SIZE + 1);
	}
}

t_gnl	*fdcheck(t_gnl **gnl, int fd)
{
	t_gnl		*i;
	t_gnl		*new;

	if (*gnl == NULL)
	{
		*gnl = (t_gnl *)ft_memalloc(sizeof(t_gnl));
		nodemem(0, gnl, fd);
		return (*gnl);
	}
	i = *gnl;
	while (i->fd != fd)
	{
		if (i->fd == fd)
			return (i);
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
	char		*tmp;

	tmp = ft_strdup(line);
	free(line);
	if (!(line = (char *)ft_memalloc(sizeof(char) * BUFF_SIZE + ft_strlen(tmp) + 1)))
		return (NULL);
	ft_strcpy(line, tmp);
	free(tmp);
	return (line);
}

int		ret_and_store(char *buf, t_gnl *pgnl, char *line, int j)
{
	int			i;

	i = 0;
	while (buf[i])
	{
		line[j++] = (buf[i++] == '\n') ? '\0' : buf[i - 1];
		if (buf[i - 1] == '\n')
		{
			pgnl->key = 'b';
			free(pgnl->store);
			pgnl->store = ft_strdup(buf + i);
			break ;
		}
	}
	if (buf[i - 1] != '\n')
		pgnl->store[0] = '\0';
	line[j] = '\0';
	return (j);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*gnl;
	t_gnl			*pgnl;
	char			buf[BUFF_SIZE + 1];
	int				x;
	int				j;

	j = 0;
	pgnl = fdcheck(&gnl, fd);
	free(*line);
	if (!fd || !line || (!(*line = (char *)ft_memalloc(sizeof(char) * BUFF_SIZE + 1 + ft_strlen(pgnl->store)))))
		return (-1);
	if (pgnl->key)
	{
		j = ret_and_store(pgnl->store, pgnl, *line, j);
		if (pgnl->key != 'c')
			pgnl->key = (pgnl->store[0]) ? 'b' : 0;
	}
	while (pgnl->store[0] == '\0' && (x = read(fd, buf, BUFF_SIZE) && pgnl->key != 'c'))
	{
		buf[x] = '\0';
		j = ret_and_store(buf, pgnl, *line, j);
		if ((x < BUFF_SIZE && (pgnl->key = 'c')) || (pgnl->store[0] == '\0' && pgnl->key == 'b'))
			break ;
		*line = expandstr(*line);
	}

	return (pgnl->key == 'c' && pgnl->store[0] == '\0' && x == 0) ? (0) : (1);
}
