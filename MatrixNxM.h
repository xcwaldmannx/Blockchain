#pragma once

#include <iostream>
#include <cstdint>
#include <random>
#include <algorithm>

#include "VectorN.h"

class MatrixNxM {
public:
	MatrixNxM() {
	}

	MatrixNxM(size_t n, size_t m) : m_width(n), m_height(m) {
		m_data.resize(m_width);
		for (size_t i = 0; i < m_width; i++) {
			m_data[i] = std::vector<uint16_t>(m_height);
		}

		for (size_t i = 0; i < m_width; i++) {
			for (size_t j = 0; j < m_height; j++) {
				m_data[i][j] = 0;
			}
		}
	}

	~MatrixNxM() {
	}

	void populate(uint16_t low, uint16_t high) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<> dis(0.0, 1.0);

		for (size_t i = 0; i < m_width; i++) {
			for (size_t j = 0; j < m_height; j++) {
				double random_num = dis(gen);
				uint16_t num = std::clamp<uint16_t>(low + (uint16_t)(random_num * (1 + high - low)), low, high);
				m_data[i][j] = num;
			}
		}
	}

	VectorN getRow(unsigned int row) const {
		VectorN vector = VectorN(m_width);
		for (size_t i = 0; i < m_width; i++) {
			vector.set(i, m_data[i][row]);
		}
		return vector;
	}

	void print() const {
		for (size_t j = 0; j < m_height; j++) {
			for (size_t i = 0; i < m_width; i++) {
				std::cout << m_data[i][j] << ", ";
			}
			std::cout << std::endl;
		}
	}

	VectorN operator* (const VectorN& vector) const {
		VectorN output = VectorN(m_height);
		for (size_t i = 0; i < m_height; i++) {
			VectorN row = getRow(i);
			output.set(i, VectorN::dot(row, vector));
		}
		return output;
	}

	size_t m_width = 0;
	size_t m_height = 0;
	std::vector<std::vector<uint16_t>> m_data{};
};