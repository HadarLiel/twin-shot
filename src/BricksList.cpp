#include "BricksList.h"

BricksList::BricksList()
{
}

void BricksList::addBrick(Brick* brick)
{
	m_bricksList.push_back(brick);
}

const std::vector<Brick*>& BricksList::getBricks() const
{
	return m_bricksList;
}
