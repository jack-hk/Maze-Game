#include "GameController.h"

//core
void GameController::Start() 
{
	ConfigMap();
	BuildMap();
}

void GameController::UpdateTick() 
{
	while (true) {
		DrawMap();
		DrawHUD();
		p.SetMoveTo(0);
		p.MoveInstruction();
		x.MoveAI(Rand(4));

		Sleep(60);
		Clear();
	}
}

//config
void GameController::ConfigMap() 
{
	ConfigTile();
	ConfigEntity();
}

void GameController::ConfigTile() 
{
	w.SetIcon('#');

	f.SetIcon('.');
	f.SetCollidable(false);

	l.SetIcon('~');
	l.SetDeadly(true);

	o.SetIcon('o');
	o.SetCollidable(false);
}

void GameController::ConfigEntity() 
{
	p.SetToken('@');
	x.SetToken('*');
}

//build
void GameController::BuildMap() 
{
	BuildTile();
	BuildEntity();
}

void GameController::BuildTile() 
{
	tilemap = {
	{w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w},
	{w,f,f,f,w,f,f,f,w,f,f,f,w,f,f,f,f,f,f,f,f,f,f,f,f,w,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,w},
	{w,f,f,f,w,f,f,f,f,f,f,f,w,f,f,f,f,f,f,f,f,f,f,f,f,w,f,f,f,l,l,l,l,l,l,f,f,f,f,f,o,f,f,f,f,f,w},
	{w,f,f,f,w,f,f,f,w,f,f,f,w,f,f,f,f,f,f,f,f,f,f,f,f,w,f,f,f,l,l,l,l,l,l,f,f,f,f,f,f,f,f,f,f,f,w},
	{w,w,f,w,w,w,w,w,w,f,f,f,w,f,f,f,f,f,f,f,f,f,f,f,f,w,f,f,f,l,l,l,l,l,l,f,f,f,f,f,f,f,f,f,f,f,w},
	{w,f,f,f,w,f,f,f,f,f,f,f,w,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,o,f,f,f,f,f,w},
	{w,f,f,f,w,f,f,f,w,w,f,w,w,f,f,f,f,f,f,f,f,f,f,f,f,w,f,f,f,l,l,l,l,l,l,f,f,f,f,f,f,f,f,f,f,f,w},
	{w,f,f,f,f,f,f,f,w,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,w,f,f,f,l,l,l,l,l,l,f,f,f,f,f,f,f,f,f,f,f,w},
	{w,f,f,f,f,f,f,f,w,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,w,f,f,f,l,l,l,l,l,l,f,f,f,f,f,o,f,f,f,f,f,w},
	{w,f,f,f,f,f,f,f,w,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,w,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,w},
	{w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w}
	};
}

void GameController::BuildEntity() 
{
	entities = { &p, &x };
	for (auto& entity : entities)
	{
		p.SetRow(2);
		p.SetColumn(2);
		x.SetRow(5);
		x.SetColumn(15);
	}
}

//draw
void GameController::DrawMap() 
{
	DrawTile();
	DrawEntity();
}

void GameController::DrawTile() 
{
	for (auto& row : tilemap)
	{
		for (auto& col : row)
		{
			std::cout << col.GetIcon();
		}
		std::cout << std::endl;
	}
}
void GameController::DrawEntity() 
{
		for (auto& entity : entities)
		{
			switch (entity->GetMoveTo()) {
			case 1:
				if (tilemap.at(entity->GetRow() - 1).at(entity->GetColumn()).GetDeadly()) {
					p.SetHP(p.GetHP() - 1);
				}
				if (tilemap.at(entity->GetRow() - 1).at(entity->GetColumn()).GetIcon() == 'o') {
					if (p.GetHP() > 2) {
						return;
					}
					p.SetHP(p.GetHP() + 1);
				}
				if (tilemap.at(entity->GetRow() - 1).at(entity->GetColumn()).GetCollidable() == false) {
					tilemap.at(entity->GetRow()).at(entity->GetColumn()).SetIcon('.');
					tilemap.at(entity->GetRow() - 1).at(entity->GetColumn()).SetIcon(entity->GetToken());
					entity->SetRow(entity->GetRow() - 1);
				}
				else
					tilemap.at(entity->GetRow()).at(entity->GetColumn()).SetIcon(entity->GetToken());
				break;
			case 2:
				if (tilemap.at(entity->GetRow()).at(entity->GetColumn() + 1).GetDeadly()) {
					p.SetHP(p.GetHP() - 1);
				}
				if (tilemap.at(entity->GetRow()).at(entity->GetColumn() + 1).GetIcon() == 'o') {
					if (p.GetHP() > 2) {
						return;
					}
					p.SetHP(p.GetHP() + 1);
				}
				if (tilemap.at(entity->GetRow()).at(entity->GetColumn() + 1).GetCollidable() == false) {
					tilemap.at(entity->GetRow()).at(entity->GetColumn()).SetIcon('.');
					tilemap.at(entity->GetRow()).at(entity->GetColumn() + 1).SetIcon(entity->GetToken());
					entity->SetColumn(entity->GetColumn() + 1);
				}
				else
					tilemap.at(entity->GetRow()).at(entity->GetColumn()).SetIcon(entity->GetToken());
				break;
			case 3:
				if (tilemap.at(entity->GetRow() + 1).at(entity->GetColumn()).GetDeadly()) {
					p.SetHP(p.GetHP() - 1);
				}
				if (tilemap.at(entity->GetRow() + 1).at(entity->GetColumn()).GetIcon() == 'o') {
					if (p.GetHP() > 2) {
						return;
					}
					p.SetHP(p.GetHP() + 1);
				}
				if (tilemap.at(entity->GetRow() + 1).at(entity->GetColumn()).GetCollidable() == false) {
					tilemap.at(entity->GetRow()).at(entity->GetColumn()).SetIcon('.');
					tilemap.at(entity->GetRow() + 1).at(entity->GetColumn()).SetIcon(entity->GetToken());
					entity->SetRow(entity->GetRow() + 1);
				}
				else
					tilemap.at(entity->GetRow()).at(entity->GetColumn()).SetIcon(entity->GetToken());
				break;
			case 4:
				if (tilemap.at(entity->GetRow()).at(entity->GetColumn() - 1).GetDeadly()) {
					p.SetHP(p.GetHP() - 1);
				}
				if (tilemap.at(entity->GetRow()).at(entity->GetColumn() - 1).GetIcon() == 'o') {
					if (p.GetHP() > 2) {
						return;
					}
					p.SetHP(p.GetHP() + 1);
				}
				if (tilemap.at(entity->GetRow()).at(entity->GetColumn() - 1).GetCollidable() == false) {
					tilemap.at(entity->GetRow()).at(entity->GetColumn()).SetIcon('.');
					tilemap.at(entity->GetRow()).at(entity->GetColumn() - 1).SetIcon(entity->GetToken());
					entity->SetColumn(entity->GetColumn() - 1);
				}
				else
					tilemap.at(entity->GetRow()).at(entity->GetColumn()).SetIcon(entity->GetToken());
				break;
			default:
				tilemap.at(entity->GetRow()).at(entity->GetColumn()).SetIcon(entity->GetToken());
			}
			std::cout << entity->GetMoveTo(); //debug
			//ROW -1 up
			//COL -1 left
		}
}

void GameController::DrawHUD()
{
	hud.DrawHeader();
	hud.HealthBar(p.GetHP());
	hud.DrawFooter();
}

void GameController::Clear()
{
#if defined _WIN32
	system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
	system("clear");
#elif defined (__APPLE__)
	system("clear");
#endif
}