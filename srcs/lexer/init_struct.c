/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariandr <hariandr@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:38:00 by hariandr          #+#    #+#             */
/*   Updated: 2024/10/17 14:37:16 by hariandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	token_size(t_token *token)
{
	if (token == NULL)
		return (0);
	if (token->next != NULL)
		return (token_size (token) + 1);
	return (1);
}

void	add_back(t_token **token, t_token *new_token)
{
	t_token	*last;

	if (*token != NULL)
	{
		last = last_token (token);
		last->next = new_token;
		if (new_token != NULL)
			new_token->prev = last;
	}
	else
		*token = new_token;
}

void	delete_token(t_token **token)
{
	if (*token != NULL)
	{
		free ((*token)->content);
		(*token)->content = NULL;
		free ((*token));
		(*token) = NULL;
	}
}

void	clear_token(t_token **token)
{
	if ((*token) != NULL)
	{
		if ((*token)->next != NULL)
			clear_token (&(*token)->next);
		delete_token (token);
	}
}

t_token	*new_token(t_token_type type, char *content)
{
	t_token	*token;

	token = (t_token *)malloc (sizeof (t_token));
	if (token == NULL)
		return (NULL);
	token->content = content;
	token->type = type;
	token->next = NULL;
	token->prev = NULL;
	return (token);
}
