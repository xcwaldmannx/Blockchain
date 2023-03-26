#include "Blockchain.h"

#include <iostream>

#include "KeySet.h"

void mineBlocks() {
    Blockchain chain = Blockchain();

    std::cout << "Mining block 1..." << std::endl;
    chain.addBlock(Block(1, "Block 1 Data"));

    std::cout << "Mining block 2..." << std::endl;
    chain.addBlock(Block(2, "Block 2 Data"));

    std::cout << "Mining block 3..." << std::endl;
    chain.addBlock(Block(3, "Block 3 Data"));
}

int main() {

    KeySet keySet = KeySet(20);
    std::cout << "KeySet:" << std::endl;
    keySet.print();

    PublicKeyCode pkc = keySet.generatePublicKeyCode(5);
    std::cout << "Public Key Code:" << std::endl;
    pkc.print();

    std::cout << "done." << std::endl;

    std::string s;
    std::cin >> s;

	return 0;
}