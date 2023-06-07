#pragma once
#include <vector>
#include "Brick.h"

class BricksList
{
public:
	BricksList();

	void addBrick(Brick* brick);

	const std::vector <Brick*>& getBricks() const;

private:
	std::vector <Brick*> m_bricksList;

};
