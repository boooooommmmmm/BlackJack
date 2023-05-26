#pragma once
#include "Player.h"

namespace Game
{
	class AiPlayer : public Player
	{
	public:
		PlayerActionState OnDecision() const override;
	private:

	};
}
