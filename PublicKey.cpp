#include "PublicKey.h"

PublicKey PublicKey::generateKey(size_t size) {
	PublicKey pk = PublicKey();
	pk.m_size = size;
	pk.m_pk = MatrixNxM(pk.m_size, pk.m_size);
	pk.m_pk.populate(10, 99);
	return pk;
}

PublicKeyCode PublicKey::generateKeyCode(const PrivateKey& sk, const PublicKey& pk, size_t mod) {
	PublicKeyCode pkc{};
	pkc.pk = pk.m_pk;
	pkc.pkMod = pk.m_pk * sk.getKey();
	int sigma = pow(log(pkc.pkMod.length()), 2);
	for (size_t i = 0; i < pkc.pkMod.length(); i++) {
		uint16_t resultModPlusError = (pkc.pkMod[i] + generateError(sigma)) % mod;
		pkc.pkMod.set(i, resultModPlusError);
	}
	return pkc;
}

int PublicKey::generateError(int sigma) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(-sigma, sigma);
	int error = dis(gen);
	std::cout << "err: " << ((error >= 0) ? "+" : "") << error << std::endl;
	return error;
}

size_t PublicKey::size() const {
	return m_size;
}

void PublicKey::print() const {
	std::cout << "Public Key:" << std::endl;
	m_pk.print();
}