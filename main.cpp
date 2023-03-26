#include "Blockchain.h"

#include <iostream>
#include <vector>

#include "KeySet.h"
#include "SystemSolver.h"

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

    KeySet keySet = KeySet(5000);
    std::cout << "KeySet:" << std::endl;
    //keySet.print();

    PublicKeyCode pkc = keySet.generatePublicKeyCode(5);
    std::cout << "Public Key Code:" << std::endl;
    //pkc.print();

    std::cout << "done." << std::endl;
    std::cout << "Solving System:" << std::endl;

    std::vector<std::vector<double>> pkDouble;
    for (const auto& vec : pkc.getRawKey()) {
        std::vector<double> d_vec(vec.begin(), vec.end());
        pkDouble.push_back(d_vec);
    }
    std::vector<double> pkAnswerDouble;
    for (int i = 0; i < pkc.getRawAnswer().size(); i++) {
        pkAnswerDouble.push_back((double) pkc.getRawAnswer()[i]);
    }

    std::vector<double> solution = SystemSolver::solveSystem(pkDouble, pkAnswerDouble);

    for (int i = 0; i < solution.size(); i++) {
        std::cout << solution[i] << std::endl;
    }

    std::string s;
    std::cin >> s;

	return 0;
}