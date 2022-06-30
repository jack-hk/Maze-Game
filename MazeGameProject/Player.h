#pragma once
#include <conio.h>
#include "Entity.h"

class Player : public Entity {
private: 
	int hitPoints = 3;
public:
	int GetHP() { return hitPoints; }
	void SetHP(int h) { hitPoints = h; }

	void MoveInstruction();
};