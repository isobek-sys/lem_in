/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:35:56 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/07 21:32:55 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int	count_ways(t_way **ways)
{
	int		len;

	len = 0;
	while (*ways && ++len)
		++ways;
	return (len);
}

t_way		*cp_way_add_room(t_way *way, int room)
{
	t_way	*new_way;

	new_way = NULL;
	while (way)
	{
		new_way = add_room_to_way(new_way, way->pos);
		way = way->next;
	}
	new_way = add_room_to_way(new_way, room);
	return (new_way);
}

t_way		*add_room_to_way(t_way *way, int room)
{
	t_way	*tmp;

	if (way && (tmp = way))
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_way *)malloc(sizeof(t_way));
		ft_bzero(tmp->next, sizeof(t_way));
		tmp->pos = room;
	}
	else
	{
		way = (t_way *)malloc(sizeof(t_way));
		ft_bzero(way, sizeof(t_way));
		way->pos = room;
	}
	return (way);
}

t_way		**add_way_to_ways(t_way **ways, t_way *way)
{
	t_way	**tmp;
	int		i;

	if ((i = 1) && way)
		++i;
	if (ways)
	{
		i += count_ways(ways);
		tmp = ways;
		ways = (t_way **)malloc((i + 1) * sizeof(t_way *));
		i = ~0;
		while (tmp[++i])
			ways[i] = tmp[i];
		if (way)
			ways[i] = way;
		ways[++i] = NULL;
		free(tmp);

	}
	else if ((ways = (t_way **)malloc((i + 1) * sizeof(t_way *))))
	{
		if (--i && way)
			*ways = way;
		*(ways + i) = NULL;
	}
	return (ways);
}

