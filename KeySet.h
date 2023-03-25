#pragma once

#include "PrivateKey.h"
#include "PublicKey.h"
#include "VectorN.h"
#include "MatrixNxM.h"

class KeySet {
public:
	KeySet(size_t size);
	~KeySet();

	PublicKeyCode generatePublicKeyCode(size_t mod);
	void print();

private:
	const PrivateKey m_sk;
	const PublicKey m_pk;
};