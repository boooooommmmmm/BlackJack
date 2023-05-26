#pragma once
#include "CardShuffler.h"
#include "Player.h"
//#include "AiPlayer.h"

class Player;
//class AiPlayer;

namespace Game
{
	static const int MainPoints = 21;

	enum BattleState
	{
		Set,
		WaitForPlayerDecision,
		Finished,
	};

	class BattleMain
	{
	public:
		BattleMain();
		BattleMain(CardShuffler* cardShuffler);
		~BattleMain();
		BattleState GetBattleState() const { return battleState; };

		void Tick(float const time);
	private:

		void MoveToNextState();
		void PlayerDecision();
		void OnGameEnd();
		void LogBattleInfo() const;
		void LogInputHelper() const;

		CardShuffler* cardShuffler;
		vector<Player*>* players = new vector<Player*>(0); //temp
		int gameStatus[2];
		BattleState battleState = Set;
		int activePlayerIndex;
		Player* activePlayer;
	};
}