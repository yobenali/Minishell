/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobenali <yobenali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:52:13 by mouizar           #+#    #+#             */
/*   Updated: 2022/11/18 00:38:21 by yobenali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	isvalid_to_export(char c)
{
	return (c == '_' || (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z') || (c == '='));
}

int	ft_space(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

int	ft_egal(char c)
{
	return (c == '=' || c == '_' );
}

void	ft_free_array(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}	
	free(str);
}

void	free_lst(t_list **lst)
{
	t_list	*temp;

	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		if (temp->content)
			free(temp->content);
		free(temp);
	}
	*lst = 0;
}
