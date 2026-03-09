/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 22:18:12 by fefo              #+#    #+#             */
/*   Updated: 2025/08/12 23:35:46 by fefo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void fight_after_death(ClapTrap *fighter1, ClapTrap *fighter2)
{
        std::cout << std::endl << fighter1->getName() << 
                " try to attack" << std:: endl;
        fighter1->attack(fighter2->getName());
        fighter2->takeDamage(fighter1->getAttackDamage());
}

int main()
{

    ClapTrap claptrap1("Drake");
    ClapTrap claptrap2("K-Dot");
    
    std::cout << std::endl << "-----------FIGHT!-----------" << std::endl;
    while (1)
    {
        if (claptrap1.getHitPoints() > 0 && claptrap1.getEnergyPoints() > 0)
        {
            claptrap1.attack(claptrap2.getName());
            claptrap2.takeDamage(claptrap1.getAttackDamage());
            claptrap1.beRepaired(2);
        }
        if (claptrap2.getHitPoints() > 0 && claptrap2.getEnergyPoints() > 0)
        {
            claptrap2.attack(claptrap1.getName());
            claptrap1.takeDamage(claptrap2.getAttackDamage());
        }
        else
        {
            std::cout << "-------------FIGHT AFTER NO ENERGY OR NO LIFE-------------" << std::endl;
            if (claptrap1.getHitPoints() == 0 && claptrap1.getEnergyPoints() == 0)
                fight_after_death(&claptrap1, &claptrap2);
            else
                fight_after_death(&claptrap2, &claptrap1);
            break ;
        }
    }
    
    return 0;
}
