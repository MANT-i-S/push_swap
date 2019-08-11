/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 15:50:54 by sholiak           #+#    #+#             */
/*   Updated: 2019/08/10 16:57:22 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_strdigits(char *str)
{
    int i;

    i = 0;
    if (str[i] == '\0' || str[i] == '\n' || str[i] == ' ')
    error("Please enter some digits");
    while(str[i] != '\0' && str[i] > 47 && str[i] < 58)
    i++;
    if (str[i] != '\0' && str[i] != '\n' && str[i] != ' ')
    error("Please enter digits only");
    return(0);
}