#pragma once
#include <iostream>
#include <vector>
#include <windows.h>

#include "HUD.h"

#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "Spell.h"
#include "Life.h"

#include "Tile.h"
#include "Floor.h"
#include "Wall.h"
#include "Lava.h"

class GameController {
private:
	HUD hud;

	Player p;
	Spell x;
	Life o;

	Floor f;
	Wall w;
	Lava l;

	std::vector<std::vector<Tile>> tilemap;
	std::vector<Entity*> entities;
public:
	void Start();
	void UpdateTick();

	int Rand(int num) { return rand() % num; }

	//configuration
	void ConfigMap();
	void ConfigTile();
	void ConfigEntity();

	//build
	void BuildMap();
	void BuildTile();
	void BuildEntity();

	//draw
	void DrawMap();
	void DrawTile();
	void DrawEntity();
	void DrawHUD();
	void Clear();
};