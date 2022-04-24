#pragma once

#include "RedBlackTree.h"

template<class K, class V>
class Map
{
private:
	RedBlackTree<K, V>* tree = new RedBlackTree<K, V>();

public:
	void insert(K key, V val) {
		tree->insert(key, val);
	}

	V find(K key) {
		return tree->find(key);
	}

	void remove(K key) {
		tree->remove(key);
	}

	void clear() {
		tree->clear();
	}

	size_t size() {
		return tree->get_size();
	}

	K* get_keys() {
		return tree->get_keys();
	}

	V* get_values() {
		return tree->get_values();
	}

	friend std::ostream& operator<<(std::ostream& stream, Map &map) {
		K* keys = map.get_keys();
		V* vals = map.get_values();
		stream << "{\n";
		for (int i = 0; i < map.size(); i++) {
			stream << "\t" << keys[i] << " -> " << vals[i] << "\n";
		}
		stream << "}";
		return stream;
	}

	void print() {
		std::cout << *this;
	}
};

