#pragma once
#include <string>
#include "GameObject.h"

using namespace std;
namespace Game {
	enum ECardColor : unsigned int
	{
		Hearts = 0,
		Spades = 1,
		Diamond = 2,
		Clubs = 3
	};

	enum ECardNumber //: int
	{
		Ace = 1,
		Two = 2,
		Three = 3,
		Four = 4,
		Five = 5,
		Six = 6,
		Seven = 7,
		Eight = 8,
		Nine = 9,
		Ten = 10,
		Jack = 11,
		Queen = 12,
		King = 13,
	};

	static const string colorStr[] = { "Hearts", "Spades", "Diamond", "Clubs" };
	static const string numberStr[] = { "Ace", "2","3","4","5","6","7","8","9","10","Jack","Queen","King" };

	class Card : public Engine::GameObject {
	public:
		Card(ECardColor color, ECardNumber number);
		~Card();

		const int const GetPoint() const;

		ECardColor CardColor;
		ECardNumber CardNumber;
	private:

	};
}