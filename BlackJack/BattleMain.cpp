#include "BattleMain.h"
#include "Logger.cpp"
#include "AiPlayer.h"

//class Player;
//class AiPlayer;
//enum PlayerState;

namespace Game
{
	BattleMain::BattleMain()
	{
		players->push_back(new Player());
		players->push_back(new AiPlayer());
	}

	BattleMain::BattleMain(CardShuffler* cardShuffler)
	{
		this->cardShuffler = cardShuffler;
		players->push_back(new Player());
		players->push_back(new AiPlayer());

		activePlayer = (*players)[0];
	}

	BattleMain::~BattleMain()
	{
		delete players;
	}

	void BattleMain::Tick(float const deltaTime)
	{
		MoveToNextState();
	}

	void BattleMain::MoveToNextState()
	{
		string info = "Current state: ";
		//info.append(static_cast<int>(battleState));
		info += std::to_string(static_cast<int>(battleState));
		Logger::Log(info);

		bool isAllPlayerGiveUp = true;
		for (Player* p : *players)
		{
			if (p->GetPlayerState() != PlayerState::GiveUp)
			{
				isAllPlayerGiveUp = false;
				break;
			}
		}

		if (isAllPlayerGiveUp)
			battleState = BattleState::Finished;

		switch (battleState)
		{
		case Set:
			battleState = BattleState::WaitForPlayerDecision;
			break;
		case WaitForPlayerDecision:
			PlayerDecision();

			break;
		case Finished:
			OnGameEnd();
			break;
		default:
			break;
		}
	}

	void BattleMain::PlayerDecision()
	{
		if (activePlayer->GetPlayerState() == PlayerState::GiveUp)
		{
			return;
		}

		LogBattleInfo();
		Logger::LogGame("Player [" + std::to_string(activePlayerIndex) + "] decision...");
		LogInputHelper();

		PlayerActionState deciton = activePlayer->OnDecision();

		switch (deciton)
		{
		case Game::Get:
			activePlayer->GetCard(cardShuffler->GetNextCard());

			if (activePlayer->GetPoints() > MainPoints)
			{
				activePlayer->SetPlayerState(PlayerState::GiveUp);
			}
			break;
		case Game::Skip:
			activePlayer->SetPlayerState(PlayerState::GiveUp);
			break;
		default:
			break;
		}

		activePlayerIndex = (activePlayerIndex + 1) % 2;//temp solution
		activePlayer = (*players)[activePlayerIndex];

		//MoveToNextState();
	}

	void BattleMain::LogBattleInfo() const
	{
		for (int i = 0; i < players->size(); ++i)
		{
			string info = "[Card Info]: Player " + std::to_string(i);
			info += " cards: ";
			const vector<Card*>* ownedCards = (*players)[i]->GetOwnedCards();
			for (int j = 0; j < ownedCards->size(); ++j)
			{
				info += " " + (*ownedCards)[j]->Name;
			}
			Logger::LogGame(info);
		}
	}

	void BattleMain::LogInputHelper() const
	{
		Logger::LogGame("0 for Get; 1 for skip/give up");
	}

	void BattleMain::OnGameEnd()
	{
		int winner = 0;
		int maxPoints = 0;
		for (int i = 0; i < players->size(); ++i)
		{
			if ((*players)[i]->GetPoints() > maxPoints)
			{
				maxPoints = (*players)[i]->GetPoints();
				winner = i;
			}
		}

		Logger::LogGame("Game End!");
		Logger::LogGame("Winner is: " + std::to_string(winner));
	}
}
