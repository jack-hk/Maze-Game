#include "HUD.h"

void HUD::HealthBar(int length) {
	{
		if (!isDead) {
			if (!length < 1) {
				for (size_t i = 0; i < length; i++)
				{
					std::cout << textLife;
				}
				for (size_t i = 0; i < (3 - length); i++)
				{
					std::cout << textDead;
				}
			}
			else {
				std::cout << "DEAD";
				isDead = true;
			}
		}
		else {
			std::cout << "DEAD";
		}
	}
}

void HUD::DrawHeader() {
	std::cout << textTitle << std::endl;
	std::cout << textHealth;
}

void HUD::DrawFooter() {
	std::cout << std::endl;
	std::cout << textLine << std::endl;

	std::cout << "@ = Player" << std::endl;
	std::cout << "* = Spell" << std::endl;
	std::cout << "~ = Lava" << std::endl;
	std::cout << "Made by Jack";
}