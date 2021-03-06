/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:13:14 by cjang             #+#    #+#             */
/*   Updated: 2022/04/17 21:30:58 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_BONUS_H
# define LIST_BONUS_H

# include "structure_bonus.h"

// list_utils_bonus

t_obj_list	*new_obj_list(void *object, int type, t_color3 color);
void		obj_list_add_back(t_obj_list **lst, t_obj_list *new_lst);
int			obj_list_size(t_obj_list *lst);

// list_del_bonus

void		del_color(t_color_info color);
void		del_obj_list(t_obj_list **lst);
void		del_obj_lst_parse(t_obj_list **lst);

#endif
