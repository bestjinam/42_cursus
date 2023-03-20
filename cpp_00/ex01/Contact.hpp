/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:25:43 by jinam             #+#    #+#             */
/*   Updated: 2023/03/17 16:22:38 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class	Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	public:
		void	display(int idx) const;
		void	print_field(int select);
		void	set_info(void);
		int		empty(void) const;
};
