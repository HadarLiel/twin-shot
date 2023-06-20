#pragma once

struct MusicStruct
{
	MusicStruct(bool turnOnMenu = true, bool turnOnGame = true) :
		_turnOnMenu(turnOnMenu),
		_turnOnGame(turnOnGame)
	{}
	bool _turnOnMenu;
	bool _turnOnGame;
};