#include "CardShuffler.h"
#include <Vector>
#include "Card.h"
#include "Logger.cpp"

namespace Game
{
	void CardShuffler::InitCards()
	{
		const int colorSize = sizeof(colorStr) / sizeof(colorStr[0]);
		const int numberSize = end(numberStr) - begin(numberStr);
		vector<Card*> orderedCards;

		for (int i = 0; i < colorSize; ++i)
		{
			for (int j = 0; j < numberSize; ++j)
			{
				Card* _c = new Card((ECardColor)i, (ECardNumber)(j + 0));
				orderedCards.push_back(_c);
			}
		}

		for (int i = orderedCards.size(); i > 0; --i)
		{
			int index = rand() % i;
			//cards.push_back(orderedCards[index]);
			cards.push(orderedCards[index]);
			orderedCards.erase(orderedCards.begin() + index);
		}
	}

	Card* CardShuffler::GetNextCard() {
		Card* c = cards.top();
		cards.pop();
		return c;
	}
}