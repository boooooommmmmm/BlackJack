#include "Card.h"


namespace Game
{
	Card::Card(ECardColor color, ECardNumber number)
	{
		CardColor = color;
		CardNumber = number;

		Name = colorStr[(int)color] + " " + numberStr[(int)number];
	}

	Card::~Card()
	{}

	const int const Card::GetPoint() const
	{
		return static_cast<int>(CardNumber) + ECardNumber::Ace;
	}
}