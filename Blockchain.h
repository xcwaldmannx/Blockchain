#pragma once

#include <vector>

#include "Block.h"

class Blockchain {
public:
	Blockchain();
	~Blockchain();

	void addBlock(Block block);

private:
	uint32_t m_difficulty = 0;
	std::vector<Block> m_chain;

	Block getLastBlock() const;
};
