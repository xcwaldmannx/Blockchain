#include "PublicKey.h"

PublicKey PublicKey::generateKey(size_t size) {
	PublicKey pk = PublicKey();
	pk.m_size = size;
	pk.m_pk = MatrixNxM(pk.m_size, pk.m_size);
	pk.m_pk.populate(1, 9);
	return pk;
}

PublicKeyCode PublicKey::generateKeyCode(const PrivateKey& sk, const PublicKey& pk, size_t mod) {
	PublicKeyCode pkc{};
	pkc.pk = pk.m_pk;
	pkc.pkMod = pk.m_pk * sk.getKey();
	for (size_t i = 0; i < pkc.pkMod.length(); i++) {
		pkc.pkMod.set(i, pkc.pkMod[i] % mod);
	}
	return pkc;
}

size_t PublicKey::size() const {
	return m_size;
}

void PublicKey::print() const {
	std::cout << "Public Key:" << std::endl;
	m_pk.print();
}