/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 22:18:12 by fefo              #+#    #+#             */
/*   Updated: 2025/08/12 00:47:23 by fefo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{

    ClapTrap claptrap1("Alex");
    ClapTrap claptrap2("Dimitri");
    
    std::cout << std::endl << "-----------FIGHT!-----------" << std::endl;
    while (1)
    {
        if (claptrap1.getHitPoints() <= 0)
        {
            std::cout << std::endl << claptrap1.getName() << 
                    " try to attack after his death" << std:: endl;
            claptrap1.attack("Dimitri");
            std::cout << std::endl << claptrap1.getName() 
            << " try to heal after his death" << std::endl;
            claptrap1.beRepaired(5);
        }
        if (claptrap2.getHitPoints() <= 0)
        {
            std::cout << std::endl << claptrap2.getName() 
            << " try to attack after his death" << std:: endl;
            
            claptrap2.attack("Alex");
            
            std::cout << std::endl << claptrap2.getName() 
            << " try to heal after death" << std:: endl;
            
            claptrap2.beRepaired(5);
            break ;
        }
        claptrap1.attack(claptrap2.getName());
        claptrap2.attack(claptrap1.getName());
    }
    
    return 0;
}