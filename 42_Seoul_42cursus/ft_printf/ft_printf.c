/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:58:43 by jiyyu             #+#    #+#             */
/*   Updated: 2020/12/28 17:58:48 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_type(va_list str, t_info *info)
{
	int		ret;
	char	type;

	ret = 0;
	type = info->type;
	if (type == 'c')
		ret = ft_print_char(va_arg(str, int), info);
	else if (type == '%')
		ret = ft_print_char('%', info);
	else if (type == 's')
		ret = ft_print_string(va_arg(str, char *), info);
	else if (type == 'd' || type == 'i')
		ret = ft_print_nbr(va_arg(str, int), info);
	else if (type == 'x' || type == 'X' || type == 'u')
		ret = ft_print_nbr(va_arg(str, unsigned int), info);
	else if (type == 'p')
		ret = ft_print_nbr(va_arg(str, unsigned long long), info);
	return (ret);
}

void	check_width_prec(va_list str,
		char *fmt, t_info *info, int i)
{
	if (ft_isdigit(fmt[i]))
	{
		if (info->prec == -1)
			info->width = info->width * 10 + fmt[i] - 48;
		else
			info->prec = info->prec * 10 + fmt[i] - 48;
	}
	else if (fmt[i] == '*')
	{
		if (info->prec == -1)
		{
			info->width = va_arg(str, int);
			if (info->width < 0)
			{
				info->minus = 1;
				info->width *= -1;
			}
		}
		else
			info->prec = va_arg(str, int);
	}
}

void	check_info(va_list str, char *fmt, t_info *info, int i)
{
	if (fmt[i] == '0' && info->width == 0 && info->prec == -1)
		info->zero = 1;
	else if (fmt[i] == '-')
		info->minus = 1;
	else if (fmt[i] == '.')
		info->prec = 0;
	else if (ft_isdigit(fmt[i]) || fmt[i] == '*')
		check_width_prec(str, fmt, info, i);
}

int		parse_format(va_list str, char *fmt)
{
	int		i;
	int		ret;
	t_info	*info;

	i = 0;
	ret = 0;
	if (!(info = malloc(sizeof(t_info) * 1)))
		return (-1);
	while (fmt[i] != '\0')
	{
		while (fmt[i] != '%' && fmt[i] != '\0')
			ret += ft_putchar(fmt[i++]);
		if (fmt[i] == '%')
		{
			set_info(info);
			while (fmt[++i] != '\0' && !(ft_strchr(TYPE, fmt[i])))
				check_info(str, fmt, info, i);
			info->type = fmt[i++];
			if ((info->minus == 1 || info->prec > -1) && info->type != '%')
				info->zero = 0;
			ret += print_type(str, info);
		}
	}
	free(info);
	return (ret);
}

int		ft_printf(const char *fmt, ...)
{
	int		ret;
	va_list	str;

	va_start(str, fmt);
	ret = parse_format(str, (char *)fmt);
	va_end(str);
	return (ret);
}
