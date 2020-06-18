/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 21:04:15 by jiyyu             #+#    #+#             */
/*   Updated: 2020/05/29 12:03:10 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char *b_number, char *a_number)
{
	write(1, &b_number[0], 1);
	write(1, &b_number[1], 1);
	write(1, " ", 1);
	write(1, &a_number[0], 1);
	write(1, &a_number[1], 1);
	if (b_number[0] == '9' && b_number[1] == '8')
	{
		return ;
	}
	write(1, ",", 1);
	write(1, " ", 1);
}

void	set_nums(char *b_number, char *a_number)
{
	a_number[0] = b_number[0];
	a_number[1] = b_number[1] + 1;
}

void	set_after_nums(char *b_number, char *a_number)
{
	while (a_number[0] <= '9')
	{
		while (a_number[1] <= '9')
		{
			ft_putchar(b_number, a_number);
			a_number[1]++;
		}
		a_number[0]++;
		a_number[1] = '0';
	}
}

void	ft_print_comb2(void)
{
	char nums1[2];
	char nums2[2];

	nums1[0] = '0';
	nums1[1] = '0';
	set_nums(nums1, nums2);
	while (nums1[0] <= '9')
	{
		while (nums1[1] <= '9')
		{
			set_after_nums(nums1, nums2);
			nums1[1]++;
			set_nums(nums1, nums2);
		}
		nums1[0]++;
		nums1[1] = '0';
		set_nums(nums1, nums2);
	}
}
