#pragma once
#include "Card.h"
#include <Vector>
#include <Queue>
#include <Stack>

namespace Game
{
	class CardShuffler
	{
	public:
		void InitCards();
		Card* GetNextCard();
	private:
		//vector<Card*> cards;
		stack<Card*> cards;
	};
}