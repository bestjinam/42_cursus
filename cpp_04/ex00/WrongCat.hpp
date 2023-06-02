/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:11:31 by jinam             #+#    #+#             */
/*   Updated: 2023/06/02 14:16:21 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <string>
#define WRONGCAT_TYPE std::string("WrongCat");

class WrongCat : public WrongAnimal
{
private:
public:
    WrongCat();
    ~WrongCat();
    WrongCat(const WrongCat& ref);
    WrongCat& operator=(const WrongCat& ref);
    void makeSound(void) const;
};
#endif
