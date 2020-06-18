/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setcon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 20:51:03 by jiyyu             #+#    #+#             */
/*   Updated: 2020/06/07 21:14:23 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		set_condition(char *input_value, int *condition)
{
	int i;

	i = 0;
	while (input_value[i] != '\0' && i < 31)
	{
		if (i % 2 == 0)
		{
			if (input_value[i] < '1' || input_value[i] > '4')
				return (0);
			condition[i / 2] = input_value[i] - '0';
		}
		else
		{
			if (input_value[i] != ' ')
				return (0);
		}
		i++;
	}
	if (i == 31 && input_value[i] == '\0')
		return (1);
	return (0);
}
