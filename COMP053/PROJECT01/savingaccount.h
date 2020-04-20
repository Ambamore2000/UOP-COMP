#ifndef PROJECT01_SAVINGACCOUNT_H
#define PROJECT01_SAVINGACCOUNT_H

#include "account.h"

/**
 * Storage for Saving Account.
 *
 */

class SavingAccount : public Account {
public:
	static int savingAccountAmount;

	/**
	 * Create new Saving Account.
	 *
	 * @param initBal Amount set in new Saving Account.
	 */
	SavingAccount(const int initBal) {
		setId(1000+savingAccountAmount);
		initializeBal(initBal);
		savingAccountAmount++;
	}
};

#endif
