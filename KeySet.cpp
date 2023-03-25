#include "KeySet.h"

#include <iostream>

KeySet::KeySet(size_t size)
	: m_sk(PrivateKey::generateKey(size)), m_pk(PublicKey::generateKey(size)) {
}

KeySet::~KeySet() {
}

PublicKeyCode KeySet::generatePublicKeyCode(size_t mod) {
	return m_pk.generateKeyCode(m_sk, m_pk, mod);
}

void KeySet::print() {
	m_sk.print();
	m_pk.print();
}
