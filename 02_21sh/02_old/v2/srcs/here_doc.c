/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:50:43 by curquiza          #+#    #+#             */
/*   Updated: 2017/05/05 21:09:34 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_is_quoted(char *s)
{
	while (*s)
	{
		if (*s == 39 || *s == 34 || *s == 92)
			return (1);
		s++;
	}
	return (0);
}

void	ft_get_hdoc_lines(t_lexeme *lex, int quoted)
{
	char	*line;
	char	*buff;
	char	*tmp;
	char	*word;

	word = ft_strjoin(lex->next->s, "\n");
	line = NULL;
	while (1)
	{
		ft_putstr("hdoc> ");
		ft_read_command_newline(&line);
		while (quoted == 0 && line[ft_strlen(line) - 2] == 92)
		{
			ft_rm_bslash_newline(&line);
			buff = ft_strdup(line);
			ft_putstr("bslash> ");
			ft_read_command_newline(&line);
			tmp = line;
			line = ft_strjoin(buff, tmp);
			free(buff);
			free(tmp);
		}
		if (ft_strcmp(line, word) == 0)
			break;
		tmp = lex->hdoc;
		lex->hdoc = ft_strjoin(tmp, line);
		free(tmp);
	}
	free(line);
	free(word);
}

void	ft_apply_hdoc_bslash(char **s)
{
	int		i;

	i = 0;
	while ((*s)[i])
	{
		if ((*s)[i] == 92 && ((*s)[i + 1] == '$' || (*s)[i + 1] == '`'
								|| (*s)[i + 1] == 92 || (*s)[i + 1] == '\n')) 
			ft_escape_char(s, i, (*s)[i + 1]);
		i++;
	}
}

void	ft_hdoc(t_lexeme *lex, t_var *tabvar)
{
	int		quoted;

	while (lex)
	{
		if (lex->op == DLESS && lex->next)
		{
			if ((quoted = ft_is_quoted(lex->next->s)) == 1)
				ft_quote_removal(&lex->next->s);
			ft_get_hdoc_lines(lex, quoted);
			lex->next->token = HDOC_DELIM;
			if (quoted == 0)
			{
				ft_parameter_expansion(&lex->hdoc, tabvar);
				ft_apply_hdoc_bslash(&lex->hdoc);
			}
		}
		lex = lex->next;
	}
}
