#include <iostream>
#include "Player.h"

namespace Game
{
	Player::Player()
	{
		state = PlayerState::Active;
	}

	Player::~Player()
	{}

	const PlayerState const Player::GetPlayerState() const
	{
		return state;
	}

	void Player::SetPlayerState(PlayerState state)
	{
		this->state = state;
	}

	void Player::GetCard(Card* card)
	{
		ownedCards.push_back(card);
		UpdatePoints();
	}

	const vector<Card*>* Player::GetOwnedCards() const
	{
		return &ownedCards;
	}

	void Player::UpdatePoints()
	{
		points = 0;
		for (Card* c : ownedCards)
		{
			points += c->GetPoint();
		}

		if (points > MainPoints)
		{
			points = -1;
			state = PlayerState::GiveUp;
		}
	}

	PlayerActionState Player::OnDecision() const
	{
		int decision;
		std::cin >> decision;

		return PlayerActionState(decision);
	}

}