/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:06:54 by muokcan           #+#    #+#             */
/*   Updated: 2025/02/12 18:07:35 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MT_H
# define MT_H

# include <signal.h>

void	ft_putstr(char *str);
pid_t	atod(char *str);
void	ft_putnbr_fd(pid_t n, int fd);

#endif
