/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 22:18:12 by fefo              #+#    #+#             */
/*   Updated: 2025/08/12 23:35:21 by fefo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void fight_and_heal_after_death(ScavTrap *fighter1, ScavTrap *fighter2)
{
        std::cout << std::endl << fighter1->getName() << 
                " try to ATTACK after his death" << std:: endl;
        fighter1->attack(fighter2->getName());
        fighter2->takeDamage(fighter1->getAttackDamage());
        std::cout << std::endl << fighter1->getName() 
        << " try to HEAL after his death" << std::endl;
        fighter1->beRepaired(5);

}

int main()
{

    ScavTrap ScavTrap1("Sosa");
    ScavTrap ScavTrap2("Lil Jojo");
    
    std::cout << std::endl << "-----------FIGHT!-----------" << std::endl;
    ScavTrap1.guardGate();
    
    ScavTrap1.beRepaired(20);
    ScavTrap2.beRepaired(20);
    while (1)
    {
        if (ScavTrap1.getHitPoints() > 0 && ScavTrap1.getEnergyPoints() > 0)
        {
            ScavTrap1.attack(ScavTrap2.getName());
            ScavTrap2.takeDamage(ScavTrap1.getAttackDamage());
        }
        if (ScavTrap2.getHitPoints() > 0 && ScavTrap2.getEnergyPoints() > 0)
        {
            ScavTrap2.attack(ScavTrap1.getName());
            ScavTrap1.takeDamage(ScavTrap2.getAttackDamage());
        }
        else
        {
            if (ScavTrap1.getHitPoints() == 0 && ScavTrap1.getEnergyPoints() == 0)
                fight_and_heal_after_death(&ScavTrap1, &ScavTrap2);
            else
                fight_and_heal_after_death(&ScavTrap2, &ScavTrap1);
            break ;
        }
    }
    
    return 0;
}
