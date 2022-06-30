#include "Enemy.h"

void Enemy::MoveAI(int num) {
switch (num) {
case 1:
	SetMoveTo(1);
	break;
case 2:
	SetMoveTo(2);
	break;
case 3:
	SetMoveTo(3);
	break;
case 4:
	SetMoveTo(4);
	break;
default:
	break;
}
	}