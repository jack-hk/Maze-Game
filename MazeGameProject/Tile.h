#pragma once

class Tile {
private:
	char icon;
	char color;
	bool isCollidable{ true };
	bool isDeadly{ false };
public:
	char GetIcon() { return icon; }
	void SetIcon(char i) { icon = i; }

	char GetColor() { return color; }
	void SetColor(char c) { color = c; }

	bool GetCollidable() { return isCollidable; }
	void SetCollidable(bool x) { isCollidable = x; }

	bool GetDeadly() { return isDeadly; }
	void SetDeadly(bool x) { isDeadly = x; }
};

class TileInteractor {
private:
	bool isActivated{ false };
public:
	bool GetActivated() { return isActivated; }
	void SetActivated(bool z) { isActivated = z; }
};


