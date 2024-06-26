/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_up_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:11:02 by tmalheir          #+#    #+#             */
/*   Updated: 2024/04/09 14:12:18 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_puthexa_up_fd(unsigned int nbr, int fd)
{
	int		count;
	char	*hexa_up;

	count = 0;
	hexa_up = "0123456789ABCDEF";
	if (nbr < 16)
		count += write(1, &hexa_up[nbr], fd);
	else
	{
		count += ft_puthexa_up_fd((nbr / 16), fd);
		count += ft_puthexa_up_fd((nbr % 16), fd);
	}
	return (count);
}
