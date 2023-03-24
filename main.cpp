#include "Blockchain.h"

#include <iostream>

int main() {

    Blockchain chain = Blockchain();

    std::cout << "Mining block 1..." << std::endl;
    chain.addBlock(Block(1, "Block 1 Data"));

    std::cout << "Mining block 2..." << std::endl;
    chain.addBlock(Block(2, "Block 2 Data"));

    std::cout << "Mining block 3..." << std::endl;
    chain.addBlock(Block(3, "Block 3 Data"));

	return 0;
}