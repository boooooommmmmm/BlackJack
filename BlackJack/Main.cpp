#include <iostream>
#include <windows.h>
#include "Logger.cpp"
#include "CardShuffler.h"
#include "BattleMain.h"

using namespace std;


extern void Init();
extern void StartGame();
extern void GameRunning();
extern void GameEnd();
extern void Tick();

Game::CardShuffler* cardShuffler;
Game::BattleMain* battleMain;
enum Game::BattleState;

void Init()
{
	Logger::LogGame("Welcome");
	cardShuffler = new Game::CardShuffler();
	cardShuffler->InitCards();

	battleMain = new Game::BattleMain(cardShuffler);
}

void StartGame()
{}

void GameRunning()
{
	while (battleMain->GetBattleState() != Game::BattleState::Finished)
	{
		battleMain->Tick(0.0f);
		Sleep(1000);
	}

	GameEnd();
}

void Tick()
{
}

void GameEnd()
{
	Logger::LogGame("Game end.");
}

int main()
{
	Init();
	StartGame();
	GameRunning();
	//GameEnd();
}

