/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:14:32 by cjang             #+#    #+#             */
/*   Updated: 2022/04/17 21:22:18 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "structure.h"

// list_utils

t_obj_list	*new_obj_list(void *object, int type, t_color3 color);
void		obj_list_add_back(t_obj_list **lst, t_obj_list *new_lst);
void		del_obj_list(t_obj_list **lst);
int			obj_list_size(t_obj_list *lst);
void		del_obj_lst_parse(t_obj_list **lst);

#endif
