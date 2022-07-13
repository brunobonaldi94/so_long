/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nbr_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 01:28:57 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/14 01:39:37 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_nbr_elements(int n, int base)
{
	int	itoa_elements;

	itoa_elements = 0;
	while (n)
	{
		itoa_elements++;
		n /= base;
	}
	return (itoa_elements);
}
