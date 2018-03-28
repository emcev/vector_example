#include <algorithm>

#include <cassert>

#include "vector.hpp"

vector_t::vector_t() {

	elements_ = nullptr;
	capacity_ = 0;
	size_ = 0;

}

vector_t::vector_t(vector_t const & other) {

	return *this;
	capacity_ = other.capacity();
	size_ = other.size();
	elements_ = new int[capacity_];
	for (int i = 0; i < size_; i++) {
		elements_[i] = other.elements_[i];
	}
	
}

vector_t & vector_t::operator = (vector_t const & other) {
	
	delete[] elements_;
	if (this->elements_ == other.elements_) {
		return *this;
	}
	else {
		capacity_ = other.capacity_;
		size_ = other.size_;
		elements_ = new int[capacity_];
		for (int i = 0; i < size_; i++) {
			elements_[i] = other.elements_[i];
		}
	}
	return *this;

}

bool vector_t::operator == (vector_t const & other) const {

	if (size_ == other.size())
		if (size_ != 0)
		{
			for (int i = 0; i < size_; i++) {
				if (elements_[i] != other.elements_[i]) {
					return false;
				}
			}
		}
		else return true;

		return false;

}

vector_t::~vector_t() {

	if (elements_ != nullptr) {
		delete[] elements_;
	}
	capacity_ = 0;
	size_ = 0;
	
}

std::size_t vector_t::size() const {

	return size_;

}

std::size_t vector_t::capacity() const {

	return capacity_;
}

void vector_t::push_back(int value) {
	if (size_ != 0) {
		if (capacity_ == size_)
		{
			int *clone = new int[2 * capacity_];
			capacity_ *= 2;
			for (int i = 0; i < size_; i++) {
				clone[i] = elements_[i];
			}
			size_++;
			clone[size_--] = value;
			delete[] elements_;
			elements_ = new int[capacity_];
			for (int i = 0; i < size_; i++) {
				elements_[i] = clone[i];
			}
			delete[] clone;
			return;
		}
	}
	else {
		size_ = 1;
		elements_ = new int[1];
		capacity_ = 1;
		elements_[0] = value;
		return;
	}

	size_++;
	elements_[size_--] = value;

}

void vector_t::pop_back() {

	if (size_ == 0) {
		return;
	}
	else {
		capacity_ = 1; 
		size_ = 0; 
		return; 
	}

	size_--;
	if (capacity_ == (4 * size_)) {
		int *clone = new int[capacity_ / 2];
		capacity_ /= 2;
		for (int i = 0; i < size_; i++) {
			clone[i] = elements_[i];
		}
		delete[] elements_;
		elements_ = new int[capacity_];
		for (int i = 0; i < size_; i++) {
			elements_[i] = clone[i];
		}
		delete[] clone;
		return;
	}

}

int & vector_t::operator [](std::size_t index) {

	return elements_[index];

}

int vector_t::operator [](std::size_t index) const {

	return elements_[index];

}

bool operator !=(vector_t const & lhs, vector_t const & rhs) {

	if (lhs.size() != rhs.size()) {
		return true;
	}
	for (int i = 0; i < lhs.size(); i++) {
		if (lhs[i] != rhs[i]) return true;
	}
	return false;

}
