#include "Block.h"

Block::Block(uint32_t index, const std::string& data) : m_index(index), m_data(data) {
    m_nonce = -1;
    m_time = time(nullptr);
}

Block::~Block() {

}

void Block::mineBlock(uint32_t difficulty) {
    char* cstr = new char[difficulty + 1];
    memset(cstr, 0, sizeof(char) * (difficulty + 1));
    for (uint32_t i = 0; i < difficulty; ++i) {
        cstr[i] = '0';
    }
    cstr[difficulty] = '\0';

    std::string str(cstr);

    delete cstr;

    do {
        m_nonce++;
        m_hash = calculateHash();
    } while (m_hash.substr(0, difficulty) != str);

    std::cout << "Block mined: " << m_hash << std::endl;
}

std::string Block::getHash() {
    return m_hash;
}

std::string Block::calculateHash() const {
    std::stringstream stream{};
    stream << m_index << m_time << m_data << m_nonce << m_prevHash;

    return sha256(stream.str());
}
