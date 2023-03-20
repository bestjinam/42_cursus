/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:22:20 by jinam             #+#    #+#             */
/*   Updated: 2023/03/17 18:04:40 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		last_idx;
	public:
		PhoneBook(void);
		void	add(void);
		void	search(void);
		void	show_table(void);
};
