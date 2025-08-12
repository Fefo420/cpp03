/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 22:18:12 by fefo              #+#    #+#             */
/*   Updated: 2025/08/12 23:34:45 by fefo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void fight_and_hi5_after_death(FragTrap *fighter1, FragTrap *fighter2)
{
        std::cout << std::endl << fighter1->getName() << 
                " try to ATTACK after his death" << std:: endl;
        fighter1->attack(fighter2->getName());
        std::cout << std::endl << fighter1->getName() 
        << " try to High Five after his death" << std::endl;
        fighter1->highFivesGuys();

}

int main()
{

    FragTrap FragTrap1("Lello");
    FragTrap FragTrap2("Jolon");
    
    std::cout << std::endl << "-----------FIGHT!-----------" << std::endl;
    while (1)
    {
        if (FragTrap1.getHitPoints() > 0 && FragTrap1.getEnergyPoints() > 0)
        {
            FragTrap1.attack(FragTrap2.getName());
            FragTrap2.takeDamage(FragTrap1.getAttackDamage());
            FragTrap1.highFivesGuys();
        }
        if (FragTrap2.getHitPoints() > 0 && FragTrap2.getEnergyPoints() > 0)
        {
            FragTrap2.attack(FragTrap1.getName());
            FragTrap1.takeDamage(FragTrap2.getAttackDamage());
            FragTrap2.highFivesGuys();
        }
        else
        {
            if (FragTrap1.getHitPoints() == 0 && FragTrap1.getEnergyPoints() == 0)
                fight_and_hi5_after_death(&FragTrap1, &FragTrap2);
            else
                fight_and_hi5_after_death(&FragTrap2, &FragTrap1);
            break ;
        }
    }
    
    return 0;
}
