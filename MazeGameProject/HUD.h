#pragma once
#include <iostream>
#include <string>
#include <vector>

class HUD {
private:
	std::string textTitle = "   ----------------STATS---------------";
	std::string textLine = "     --------------------------------";
	std::string textHealth = "	   HP: ";
	std::string textLife = "o ";
	std::string textDead = "- ";
	bool isDead{ false };

	std::vector<std::string> listHUD;
public:
	bool GetDead() { return isDead; }
	void SetDead(bool x) { isDead = x; }
	void HealthBar(int length);
	void DrawHeader();
	void DrawFooter();
};