/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ascii.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:14:54 by cjang             #+#    #+#             */
/*   Updated: 2022/04/17 21:14:55 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ASCII_H
# define FT_ASCII_H

# include "libft_type.h"

double	ft_atof(char *str, int *valid);
int		ft_atoi(const char *str, t_res *valid);
t_bool	ft_isdigit(int c);
t_bool	ft_isspace(int c);

#endif
