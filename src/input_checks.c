/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_checks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 17:09:07 by mvalk         #+#    #+#                 */
/*   Updated: 2023/04/19 14:13:18 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <limits.h>

int	dupe_check(char **input)
{
	int	to_comp;
	int	j;
	int	i;

	i = 0;
	while (input[i])
	{
		j = i + 1;
		to_comp = ft_atoi(input[i]);
		while (input[j])
		{
			if (to_comp == ft_atoi(input[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_input_type(char **input)
{
	int	j;
	int	i;

	i = 0;
	while (input[i] != NULL)
	{
		j = 0;
		if (input[i][0] == '-')
			j++;
		if (input[i][j] == '\0')
			return (1);
		while (input[i][j])
		{
			if (!ft_isdigit(input[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
