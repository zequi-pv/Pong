#include "Pad.h"

void initPad1(Pad& pad)
{
	pad.Position = { GetScreenWidth() / 10.0f, GetScreenHeight() / 3.0f };
	pad.Size = { GetScreenWidth() / 30.0f, GetScreenHeight() / 4.0f };
	pad.minPosition = 0;
	pad.maxPosition = GetScreenHeight() - pad.Size.y;
}

void initPad2(Pad& pad)
{
	pad.Position = { GetScreenWidth() - 100.0f, GetScreenHeight() / 3.0f };
	pad.Size = { GetScreenWidth() / 30.0f, GetScreenHeight() / 4.0f };
	pad.minPosition = 0;
	pad.maxPosition = GetScreenHeight() - pad.Size.y;
}