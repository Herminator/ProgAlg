#pragma once

#include "RWLock.h"
#include <chrono>

class BankAccount {
	mutable RWLock m_lock;	// mutable: can be modified even in const methods
	double m_balance = 0;	// bank account balance

public:
	void deposit(double amount) {
		// TODO
	}

	double getBalance() const {
		// TODO
		return 0;
	}

	size_t getReaders() const {
		// TODO
		return 0;
	}
};