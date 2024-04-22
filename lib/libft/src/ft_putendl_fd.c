/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:15:53 by tmalheir          #+#    #+#             */
/*   Updated: 2024/04/09 13:35:20 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*Outputs the string ’s’ to the given file descriptor.*/

void	ft_putendl_fd(char *str, int fd)
{
	int	idx;

	if (str)
	{
		idx = 0;
		while (str[idx])
		{
			write (fd, &str[idx], 1);
			idx++;
		}
		write (fd, "\n", 1);
	}
}
