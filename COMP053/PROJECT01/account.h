#ifndef PROJECT01_ACCOUNT_H
#define PROJECT01_ACCOUNT_H

#include <string>
#include "id.h"

using namespace std;

/**
 * Storage for Account with balance and ID.
 *
 */

class Account : public Id {
private:
	int balance;
public:
	/**
	 * Initialize balance.
	 *
	 * @param initAmount Amount set in new account.
	 */
	const void initializeBal(const int initAmount) { this-> balance = initAmount; }
	/**
	 * Deposit into balance.
	 *
	 * @param depositAmount Amount to deposit in account.
	 */
	const void deposit(const int depositAmount) { this->balance += depositAmount; }
	/**
	 * Withdraw from balance.
	 *
	 * @param withdrawAmount Amount to withdraw from account.
	 */
	const void withdraw(const int withdrawAmount) { this->balance -= withdrawAmount; }
	/**
	 * Get balance amount.
	 *
	 * @return Current balance in account.
	 */
	const int getBalance() { return balance; }
};

#endif