#pragma once
#include "Tile.h"


class Collectable : public Tile {
private:
	bool isPickedUp{ true };
public:
	bool GetPickedUp() { return isPickedUp; }
	void SetPickedUp(bool a) { isPickedUp = a; }
};