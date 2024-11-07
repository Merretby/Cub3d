/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:25:07 by jlebre            #+#    #+#             */
/*   Updated: 2024/10/08 11:58:23 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*push_line(char *remains)
{
	int		i;
	char	*array;

	i = 0;
	while (remains[i] && remains[i] != '\n')
		i++;
	if (remains[i] == '\n')
		i++;
	array = (char *)malloc(sizeof(char) * (i + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (remains[i] && remains[i] != '\n')
	{
		array[i] = remains[i];
		i++;
	}
	if (remains[i] == '\n')
	{
		array[i] = '\n';
		array[i + 1] = '\0';
		return (array);
	}
	array[i] = '\0';
	return (array);
}

char	*cut_next_line(char *remains)
{
	int		i;
	int		j;
	char	*array;

	i = 0;
	j = 0;
	while (remains[i] && remains[i] != '\n')
		i++;
	if (!remains[i])
	{
		free(remains);
		return (NULL);
	}
	array = (char *)malloc(sizeof(char) * (ft_strlen(remains) - i + 1));
	if (!array)
		return (NULL);
	i++;
	while (remains[i])
		array[j++] = remains[i++];
	array[j] = '\0';
	free(remains);
	return (array);
}

bool	find_new_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (true);
		i += 1;
	}
	return (false);
}
