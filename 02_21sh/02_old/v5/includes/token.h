/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 12:43:22 by curquiza          #+#    #+#             */
/*   Updated: 2017/05/26 12:56:59 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

enum	e_token
{
	WORD, // par défaut
	CTRL_OP, // operateur de controle : ;, ;;, |, ||, &, && ...
	RED_OP, // operateur de redirection : <, >, <<, >>, <&, >&, <<- ...
	IO_NBR, // nbr avant les red_op
	ASS_WORD, // NAME=valeur
	NEWLINE, // \n
};

enum	e_op
{
	SEMIC = 1, // ;
	DSEMIC = 11, // ;;
	PIPE = 2, // |
	DPIPE = 22, // ||
	AND = 3, // &
	DAND = 33, // &&
	LESS = 4, // <
	DLESS = 44, // <<
	GREAT = 5, // >
	DGREAT = 55, // >>
	LESSAND = 6, // <& 
	GREATAND = 7, // >&
	LESSGREAT = 8, // <>
	DLESSDASH = 9, // <<-
	CLOBBER = 10 // >|
};

#endif
