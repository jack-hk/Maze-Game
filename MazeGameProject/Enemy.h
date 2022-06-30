#pragma once
#include <iostream>
#include <stdlib.h>
#include "Entity.h"

class Enemy : public Entity {
public:
	void MoveAI(int num);
};