#ifndef PROJECT01_CHECKINGACCOUNT_H
#define PROJECT01_CHECKINGACCOUNT_H

#include "account.h"

/**
 * Storage for Checking Account.
 *
 */

class CheckingAccount : public Account {
private:
	int maxCap;
	bool locked;
public:
	static int checkingAccountAmount;

	/**
	 * Create new Checking Account.
	 *
	 * @param initBal Amount set in new Checking Account.
	 * @param maxCap Maximum amount for new Checking Account.
	 * @param locked Whether new account is locked or not.
	 */
	CheckingAccount(const int initBal, const int maxCap, const bool locked) {
		setId(6000+checkingAccountAmount);

		initializeBal(initBal);
		this->maxCap = maxCap;
		this->locked = locked;

		checkingAccountAmount++;
	}

	/**
	 * Get maximum capacity.
	 *
	 * @return Maximum capacity of Checking Account.
	 */
	const int getCap() { return maxCap; }
	/**
	 * Check if Checking Account is locked or not.
	 *
	 * @return Whether Checking Account is locked or not.
	 */
	const bool isLocked() { return locked; }
	/**
	 * Set lock status for Checking Account
	 *
	 * @param lock Whether to or not to lock Checking Account.
	 */
	const void setLocked(const bool lock) { this->locked = lock; }
	/**
	 * Set maximum capacity.
	 *
	 * @param cap Maximum amount for Checking Account.
	 */
	const void setCap(const int cap) { this->maxCap = cap; }
};

#endif
