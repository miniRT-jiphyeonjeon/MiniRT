/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_type.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:15:11 by cjang             #+#    #+#             */
/*   Updated: 2022/04/17 21:15:13 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TYPE_H
# define LIBFT_TYPE_H

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1,
}	t_bool;

typedef enum e_res
{
	CLEAN = 0,
	NOTCLEAN = -1,
	ERR = -2,
}	t_res;

typedef enum e_gnl_res
{
	READFAIL = -2,
	ERROR = -1,
	FIN = 0,
	SUCCESS = 1,
}	t_gnl_res;

#endif
