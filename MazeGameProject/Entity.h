#pragma once
//#include <tuple>

class Entity {
private:
	//std::tuple <int, int> position;
	//std::tuple <int, int> GetPosition() { return position; }
	//void SetPosition(std::tuple <int, int> x) { position = x; }
	int positionRow;
	int positionColumn;

	int directionMoveTo;

	char token;
public:
	char GetToken() { return token; }
	void SetToken(char t) { token = t; }

	int GetRow() { return positionRow; }
	void SetRow(int r) { positionRow = r; }
	int GetColumn() { return positionColumn; }
	void SetColumn(int c) { positionColumn = c; }

	int GetMoveTo() { return directionMoveTo; }
	void SetMoveTo(int d) { directionMoveTo = d; }
};