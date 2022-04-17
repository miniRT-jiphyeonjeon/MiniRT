/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:19:12 by cjang             #+#    #+#             */
/*   Updated: 2022/04/17 21:19:23 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H

void	ft_bzero(void *ptr, size_t n);
void	*ft_calloc(size_t size, size_t count);
void	*ft_memset(void *b, int c, size_t len);

#endif
