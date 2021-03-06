/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inhibitor_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 15:17:22 by curquiza          #+#    #+#             */
/*   Updated: 2017/04/26 14:21:22 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_check_quote(t_lexeme *lex)
{
	int		i;
	char	*s;

	s = ft_lexlst_last(lex)->s;
	i = 0;
	while (s[i])
	{
		if (s[i] == 92)
			i++;
		else if (s[i] == 39)
		{
			i = ft_next_squote(i, s);
			if (!s[i])
				return (39);
		}
		else if (s[i] == 34)
		{
			i = ft_next_dquote(i, s);
			if (!s[i])
				return (34);
		}
		if (s[i])
			i++;
	}
	return (0);
}

int		ft_check_pipe(t_lexeme *lex)
{
	while (lex)
	{
		if (lex->op == PIPE)
		{
			lex = ft_next_token(lex);
			if (!lex)
				return (-1);
		}
		lex = lex->next;
	}	
	return (0);
}

int		ft_check_bslash(t_lexeme *lex)
{
	int			i;
	t_lexeme	*last;

	last = ft_lexlst_last(lex);
	if (last->token == NEWLINE)
		return (0);
	i = ft_strlen(last->s) - 2;
	if (last->s[i] == 92 && last->s[i + 1] == '\n')
		return (-1);
	return (0);
}
