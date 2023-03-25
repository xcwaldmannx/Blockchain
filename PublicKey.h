#pragma once

#include "PrivateKey.h"
#include "MatrixNxM.h"
#include "VectorN.h"

struct PublicKeyCode {
	MatrixNxM pk{};
	VectorN pkMod{};

	void print() const {
		std::cout << "Public Key:" << std::endl;
		pk.print();
		std::cout << "Public Key Mod:" << std::endl;
		pkMod.print();
	}
};

class PublicKey {
public:
	static PublicKey generateKey(size_t size);

	static PublicKeyCode generateKeyCode(const PrivateKey& sk, const PublicKey& pk, size_t mod);

	size_t size() const;
	void print() const;

private:
	size_t m_size = 0;
	MatrixNxM m_pk{};
	VectorN m_pk_mod{};
};