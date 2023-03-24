#include "Blockchain.h"

Blockchain::Blockchain() {
	m_chain.emplace_back(Block(0, "Genesis Block"));
	m_difficulty = 5;
}

Blockchain::~Blockchain() {

}

void Blockchain::addBlock(Block block) {
	block.m_prevHash = getLastBlock().getHash();
	block.mineBlock(m_difficulty);
	m_chain.push_back(block);
}

Block Blockchain::getLastBlock() const {
	return m_chain.back();
}
