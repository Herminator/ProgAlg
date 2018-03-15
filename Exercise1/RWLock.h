#pragma once

#include <mutex>
#include <condition_variable>

using namespace std;

class RWLock {
	mutex m_mutex;				// re-entrance not allowed
	condition_variable m_readingAllowed, m_writingAllowed;
	bool m_writeLocked = false;	// locked for writing
	size_t m_readLocked = 0;	// number of concurrent readers

public:
	size_t getReaders() const {
		return m_readLocked;
	}

	void lockR() {
        unique_lock<mutex> monitor(m_mutex);
        while (m_writeLocked == true) m_readingAllowed.wait(monitor);

        m_readLocked++;
	}

	void unlockR() {
        unique_lock<mutex> monitor(m_mutex);

        if (m_readLocked > 0)
        {
            m_readLocked--;
            if (m_readLocked == 0)
            {
                m_writingAllowed.notify_one();
            }
        }

	}

	void lockW() {
        unique_lock<mutex> monitor(m_mutex);
        while (m_readLocked > 0 || m_writeLocked == true) m_writingAllowed.wait(monitor);

        m_writeLocked = true;

	}

	void unlockW() {
        unique_lock<mutex> monitor(m_mutex);

        m_writeLocked = false;
        m_readingAllowed.notify_all();
        m_writingAllowed.notify_one();
	}
};