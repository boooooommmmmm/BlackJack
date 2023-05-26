#include "AiPlayer.h";

enum PlayerActionState;

namespace Game
{
	PlayerActionState AiPlayer::OnDecision() const
	{
		if (points < 15)
		{
			return PlayerActionState::Get;
		}
		else
		{
			return PlayerActionState::Skip;
		}
	}
}