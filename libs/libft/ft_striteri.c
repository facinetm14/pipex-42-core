/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:50:52 by fakouyat          #+#    #+#             */
/*   Updated: 2022/06/24 22:01:33 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;
	int	length;

	if (!s)
		return ;
	i = 0;
	length = ft_strlen(s);
	while (i < length)
	{
		(*f)(i, &s[i]);
		i++;
	}
}
