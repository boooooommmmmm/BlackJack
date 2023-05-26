#pragma once
#include <Vector>
#include "BattleMain.h"
#include "Card.h"

namespace Game
{
	enum PlayerState
	{
		Active,
		GiveUp,
	};

	enum PlayerActionState
	{
		Get,
		Skip,
	};

	class Player
	{
	public:
		Player();
		~Player();

		virtual PlayerActionState OnDecision() const;
		const PlayerState const GetPlayerState() const;
		void SetPlayerState(PlayerState state);
		void GetCard(Card* card);
		const int GetPoints() const { return points; }
		const vector<Card*>* GetOwnedCards() const;
	private:
		void UpdatePoints();
		PlayerState state;
		vector<Card*> ownedCards;


	protected:
		int points;
	};
}
