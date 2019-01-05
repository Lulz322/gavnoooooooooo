/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 14:54:47 by iruban            #+#    #+#             */
/*   Updated: 2018/11/02 14:54:49 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		len(long long nb)
{
    int		len;
    unsigned long long forsure;

    len = 0;
    if (nb < 0)
    {
        forsure = nb * -1;
        len++;
    }
    else
    	forsure = nb;
    while (forsure > 0)
    {
        forsure = forsure / 10;
        len++;
    }
    return (len);
}

char	*ft_itoa(long long nb)
{
    char *str;
    long long	n;
    int		i;
    unsigned long long check;

    n = nb;
    i = len(n);

    if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
    	return (NULL);
    str[i--] = '\0';
    if (n == 0)
    {
        str[0] = 48;
        return (str);
    }
    if (n < 0)
    {
        str[0] = '-';
        check = nb * -1;
    }
    else
    	check = nb;
    while (check > 0)
    {
        str[i] = 48 + (check % 10);
        check = check / 10;
        i--;
    }
    return (str);
}
