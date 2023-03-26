#pragma once

#include <random>

#include "PrivateKey.h"
#include "MatrixNxM.h"
#include "VectorN.h"

struct PublicKeyCode {
	MatrixNxM pk{};
	VectorN pkMod{};

	std::vector<std::vector<uint16_t>> getRawKey() const {
		return pk.m_data;
	}

	std::vector<uint16_t> getRawAnswer() const {
		return pkMod.m_data;
	}

	void print() const {
		std::cout << "Public Key:" << std::endl;
		pk.print();
		std::cout << "Public Key Mod+Error:" << std::endl;
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
	static int generateError(int sigma);

	size_t m_size = 0;
	MatrixNxM m_pk{};
};