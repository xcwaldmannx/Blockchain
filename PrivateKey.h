#pragma once

#include "VectorN.h"

class PrivateKey {
public:
	static PrivateKey generateKey(size_t size);

	VectorN getKey() const;

	size_t size() const;
	void print() const;

private:
	size_t m_size = 0;
	VectorN m_sk{};
};