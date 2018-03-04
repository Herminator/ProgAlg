#pragma once

#include <mutex>

using namespace std;

class RWLock {
	mutex m_mutex;				// re-entrance not allowed
	condition_variable m_readingAllowed, m_writingAllowed;
	bool m_writeLocked = false;	// locked for writing
	size_t m_readLocked = 0;	// number of concurrent readers

public:
	size_t getReaders() const {
		// TODO
		return 0;
	}

	void lockR() {
		// TODO
	}

	void unlockR() {
		// TODO
	}

	void lockW() {
		// TODO
	}

	void unlockW() {
		// TODO
	}
};