#include "Player.h"

void Player::MoveInstruction() {
	if (_kbhit()) {
		switch (_getch())
		{
		case 72:
			SetMoveTo(1);
			break;
		case 75:
			SetMoveTo(4);
			break;
		case 77:
			SetMoveTo(2);
			break;
		case 80:
			SetMoveTo(3);
			break;
		default:
			SetMoveTo(0);
			break;
		}
	}
}