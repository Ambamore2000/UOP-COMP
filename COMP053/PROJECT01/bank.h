#ifndef PROJECT01_BANK_H
#define PROJECT01_BANK_H

#include "account.h"
#include <vector>

/**
 * Storage for Bank containing multiple Bank Accounts.
 *
 */

class Bank {
protected:
	string name;
	string address;
	string workingHours;


	vector<BankAccount> bankAccounts;

public:
	/**
	 * Create new Bank.
	 *
	 * @param name Name of the Bank.
	 * @param address Address of the Bank.
	 * @param workingHours Hours of the Bank.
	 */
	Bank(const string name, const string address, const string workingHours) {
		this->name = name;
		this->address = address;
		this->workingHours = workingHours;
	}

	/**
	 * Get Bank name.
	 *
	 * @return Name of the Bank.
	 */
	const string getName() { return name; }
	/**
	 * Get Bank address.
	 *
	 * @return Address of the Bank.
	 */
	const string getAddress() { return address; }
	/**
	 * Get Bank hours.
	 *
	 * @return Hours of the Bank.
	 */
	const string getHours() { return workingHours; }

	/**
	 * Create new Bank Account in Bank.
	 *
	 * @param firstName First name of Bank Account owner.
	 * @param lastName Last name of Bank Account owner.
	 * @param ssn SSN of Bank Account owner.
	 * @return New Bank Account.
	 */
	BankAccount* createNewBankAccount(const string firstName, const string lastName, const string ssn) {
		bankAccounts.push_back(BankAccount(firstName, lastName, ssn));
		return &bankAccounts.at(bankAccounts.size()-1);
	}

	/**
	 * Get Bank Accounts in Bank.
	 *
	 * @return Collection of Bank Accounts in Bank.
	 */
	const vector<BankAccount> getBankAccounts() { return bankAccounts; }

	/**
	 * Get aggregated balance of Bank Accounts in Bank.
	 *
	 * @return Sum of balance of Bank Accounts in Bank.
	 */
	const int getAggBalance() {
		int aggBal = 0;
		for (BankAccount bA : bankAccounts) { aggBal += bA.getAggBalance(); }
		return aggBal;
	}

	/**
	 * Get Bank Account of specific ID.
	 *
	 * @param id ID value of Bank Account to find and return.
	 * @param bAcc Bank Account Pointer to be set.
	 * @return If Bank Account ID was found or not.
	 */
	const bool getAccount(const int id, BankAccount* &bAcc) {
		for (int x = 0; x < bankAccounts.size(); x++) {
			if (bankAccounts.at(x).getId() == id) { bAcc = &bankAccounts.at(x); return true; }
		}
		return false;
	}

	/**
	 * Delete Bank Account of specific ID.
	 *
	 * @param id ID value of Bank Account to find and delete.
	 * @return If Bank Account ID was found and deleted or not.
	 */
	const bool deleteAccount(const int id) {
		for (vector<BankAccount>::iterator it = bankAccounts.begin(); it != bankAccounts.end(); ++it) {
			if (it->getId() == id) { bankAccounts.erase(it); return true; }
		}
		return false;
	}
};

#endif
