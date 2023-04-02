#include "Blockchain.h"

#include <LaBCry.h>

#include <iostream>

void mineBlocks() {
    Blockchain chain = Blockchain();

    std::cout << "Mining block 1..." << std::endl;
    chain.addBlock(Block(1, "Block 1 Data"));

    std::cout << "Mining block 2..." << std::endl;
    chain.addBlock(Block(2, "Block 2 Data"));

    std::cout << "Mining block 3..." << std::endl;
    chain.addBlock(Block(3, "Block 3 Data"));
}

int correct = 0;
int incorrect = 0;

void run(int bit) {
    labcry::KeyPair kp = labcry::KeyPair(64, 1000);
    labcry::PublicKeyNonce nonce = kp.generateNonce();
    labcry::MessageCoder::encode(nonce, bit);
    int32_t result = labcry::MessageCoder::decode(kp.getPrivateKey(), nonce);

    if ((result == 0 && bit == 0) || (result == 1 && bit == 1)) {
        correct++;
    } else {
        incorrect++;
    }

}

int main() {

    for (int i = 0; i < 10000; i++) {
        run(1);
    }

    std::cout << "Correct: " << correct << std::endl;
    std::cout << "Incorrect: " << incorrect << std::endl;

    std::string s;
    std::cin >> s;

	return 0;
}