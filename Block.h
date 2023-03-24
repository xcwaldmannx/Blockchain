#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <ctime>

#include "sha256.h"

class Block {
public:
	Block(uint32_t index, const std::string& data);
	~Block();

	void mineBlock(uint32_t difficulty);

	std::string getHash();

public:
	std::string m_prevHash{};

private:
	uint32_t m_index = 0;
	int64_t m_nonce = 0;
	std::string m_data{};
	std::string m_hash{};
	time_t m_time = 0;

	std::string calculateHash() const;

};