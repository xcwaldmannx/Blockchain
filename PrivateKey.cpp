#include "PrivateKey.h"

PrivateKey PrivateKey::generateKey(size_t size) {
	PrivateKey sk = PrivateKey();
	sk.m_size = size;
	sk.m_sk = VectorN(sk.m_size);
	sk.m_sk.populate(10, 99);
	return sk;
}

VectorN PrivateKey::getKey() const {
	return m_sk;
}

size_t PrivateKey::size() const {
	return m_size;
}

void PrivateKey::print() const {
	std::cout << "Private Key:" << std::endl;
	m_sk.print();
}