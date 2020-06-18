/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:22:33 by jiyyu             #+#    #+#             */
/*   Updated: 2020/06/10 22:18:44 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char			*ft_make_str(long long int origin, char *base_to, int base_num);

int				ft_check_base(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int				ft_find_index(char *base, char c)
{
	int i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

long long int	ft_make_num(char *str, char *base, int base_size)
{
	int				i;
	long long int	j;
	int				minus;
	long long int	nb;

	i = 0;
	minus = 0;
	nb = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			minus++;
	}
	while (str[i] != '\0')
	{
		j = ft_find_index(base, str[i++]);
		if (j < 0)
			break ;
		nb = nb * base_size + j;
	}
	if (minus % 2 == 1)
		nb = nb * -1;
	return (nb);
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long int	origin_nbr;
	int				base_num1;
	int				base_num2;
	char			*changed_nbr;

	base_num1 = ft_check_base(base_from);
	base_num2 = ft_check_base(base_to);
	if (base_num1 < 2 || base_num2 < 2)
		return (0);
	origin_nbr = ft_make_num(nbr, base_from, base_num1);
	changed_nbr = ft_make_str(origin_nbr, base_to, base_num2);
	if (changed_nbr == 0)
		return (0);
	return (changed_nbr);
}
