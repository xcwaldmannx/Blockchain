#pragma once

#include <iostream>
#include <cstdint>
#include <random>
#include <algorithm>
#include <memory>

class VectorN {
public:
	VectorN() {
	}

	VectorN(size_t n) : m_size(n) {
		m_data.resize(m_size);
		for (size_t i = 0; i < m_size; i++) {
			m_data[i] = 0;
		}
	}

	~VectorN() {
	}

	void populate(uint16_t low, uint16_t high) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<> dis(0.0, 1.0);

		for (size_t i = 0; i < m_size; i++) {
			double random_num = dis(gen);
			uint16_t num = std::clamp<uint16_t>(low + (uint16_t)(random_num * (1 + high - low)), low, high);
			m_data[i] = num;
		}
	}

	void set(size_t index, uint16_t value) {
		m_data[index] = value;
	}

	static size_t dot(const VectorN& v1, const VectorN& v2) {
		size_t output = 0;
		if (v1.m_size == v2.m_size) {
			for (size_t i = 0; i < v1.m_size; i++) {
				output += v1.m_data[i] * v2.m_data[i];
			}
		}
		return output;
	}

	size_t length() {
		return m_size;
	}

	void print() const {
		for (size_t i = 0; i < m_size; i++) {
			std::cout << m_data[i] << ", ";
		}
		std::cout << std::endl;
	}

	uint16_t& operator[] (size_t index) {
		return m_data[index];
	}

private:
	size_t m_size = 0;
	std::vector<uint16_t> m_data{};
};