/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:19:16 by cjang             #+#    #+#             */
/*   Updated: 2022/04/17 21:19:20 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WRITE_H
# define FT_WRITE_H

int		ft_write(int fd, const char *str);
int		ft_writes(int fd, char *arr[]);
void	ft_putstr_fd(char *s, int fd);

#endif
