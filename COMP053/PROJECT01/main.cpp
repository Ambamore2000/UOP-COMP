#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include "bankaccount.h"
#include "bank.h"
#include "checkingaccount.h"
#include "savingaccount.h"

using namespace std;

int BankAccount::bankAccountAmount = 0;
int SavingAccount::savingAccountAmount = 0;
int CheckingAccount::checkingAccountAmount = 0;

/**
 * Prints out from console (in RED).
 *
 * @param output Message to print out.
 */
const void printConsole(const string output) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout << "\t| " << output << endl;
}

/**
 * serviceArray[] options for printServices() function.
 */
const string bankService[] = {
		"A -- Number of Bank-Accounts",
		"S -- Number of Saving-Accounts",
		"H -- Number of Checking-Accounts",
		"O -- Open Bank-Account",
		"C -- Close Bank-Account",
		"M -- Modify Bank-Account",
		"D -- Detailed Bank-Accounts",
		"B -- Brief Bank-Accounts Info Sorted Based on Aggregated Balances",
		"X -- Exit"
};
const string bankAccService[] = {
		"S -- Open Saving Sub-Account",
		"C -- Open Checking Sub-Account",
		"M -- Modify a Sub-Account",
		"E -- Close a Sub-Account",
		"D -- Detailed Bank Account Info Sorted Based on Balances of Sub-Accounts",
		"B -- Brief Bank Account Info",
		"X -- Exit"
};
const string checkingAccService[] = {
		"D -- Deposit",
		"W -- Withdraw",
		"C -- Max Capacity",
		"L -- Lock Sub-Account",
		"U -- Unlock Sub-Account",
		"X -- Exit"
};
const string savingAccService[] = {
		"D -- Deposit",
		"W -- Withdraw",
		"X -- Exit"
};

/**
 * Prints out services (in YELLOW).
 *
 * @param service Current Bank service.
 * @param serviceArray Array of options to print for specific service.
 * @param size Size of service array.
 */
void printServices(const string service, const string serviceArray[], const int size) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	cout << "Eligiable services for " << service << endl;
	for (int i = 0; i < size; i++) { cout << "\t\t" << serviceArray[i] << endl; }
	cout << "Please enter your selection:";
}

/**
 * inputOutput[] options for printInputArray() function.
 */
const string bankInitialize[] = {
		"Enter the name of the bank: ",
		"Enter the address of the bank: ",
		"Enter the working hours: "
};
const string accountInitialize[] = {
		"\tEnter the first name of the account holder: ",
		"\tEnter the last name of the account holder: ",
		"\tEnter the SSN of the account holder: "
};
const string accModifyInitialize[] = {
		"\tEnter the bank-account number to modify: "
};
const string accCloseInitialize[] = {
		"\tEnter the bank-account number to be closed: "
};
const string subModifyInitialize[] = {
		"\tEnter the sub-account number to modify: "
};
const string subCloseInitialize[] = {
		"\tEnter the sub-account number to be closed: "
};
const string depositInitialize[] = {
		"\tEnter the amount to deposit: "
};
const string withdrawInitialize[] = {
		"\tEnter the amount to withdraw: "
};
const string capInitialize[] = {
		"\tEnter the new maximum capacity: "
};
const string savingInitialize[] = {
		"\tEnter the initial balance: "
};
const string checkingInitialize[] = {
		"\tEnter the initial balance: ",
		"\tEnter the desired maximum capacity: ",
		"\tDefine initial state: (L - locked, Otherwise - Unlocked) "
};

/**
 * Prints out input option by line.
 *
 * @param userInput User input string to store.
 * @param inputOutput Input option to print.
 */
const void printInput(string &userInput, const string inputOutput) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	cout << inputOutput;

	while (userInput.size() == 0)
		getline(cin, userInput);
	cin.clear();
}

/**
 * Prints out input options line by line.
 *
 * @param userInputArray Array of input options to store.
 * @param size Size of input options array.
 * @param inputOutput Array of input options to print for specific service.
 */
const void printInputArray(string userInputArray[], const int size, const string inputOutput[]) {
	for (int i = 0; i < size; i++) {
		string userInput;
		printInput(userInput,inputOutput[i]);
		userInputArray[i] = userInput;
	}
}

/**
 * Initialize Saving Account menu.
 *
 * @param savingAcc Saving Account Pointer to be set.
 */
const void initializeSavingAccount(SavingAccount* savingAcc) {
	char savingAccInput = ' ';
	while (savingAccInput != 'X' && savingAccInput != 'x') {
		printServices("sub-account SAV" + to_string(savingAcc->getId()),savingAccService,3);
		cin >> savingAccInput;
		if (savingAccInput == 'D' || savingAccInput == 'd') {
			string inputArr[1];
			printInputArray(inputArr, 1, depositInitialize);
			int depositAmount;
			try {
				depositAmount = stoi(inputArr[0]);
			} catch (invalid_argument) {
				depositAmount = -1;
			}
			if (depositAmount > 0) {
				savingAcc->deposit(depositAmount);
				printConsole("Deposit was successful.");
				printConsole("The current balance is " + to_string(savingAcc->getBalance()));
			} else {
				printConsole("Deposit was unsuccessful.");
			}
			cout << endl << endl << endl;
		} else if (savingAccInput == 'W' || savingAccInput == 'w') {
			string inputArr[1];
			printInputArray(inputArr, 1, withdrawInitialize);
			int withdrawAmount;
			try {
				withdrawAmount = stoi(inputArr[0]);
			} catch (invalid_argument) {
				withdrawAmount = INT_MAX;
			}
			if (savingAcc->getBalance() - withdrawAmount >= 0) {
				savingAcc->withdraw(withdrawAmount);
				printConsole("Withdraw was successful.");
				printConsole("The current balance is " + to_string(savingAcc->getBalance()));
			} else {
				printConsole("Withdraw was unsuccessful.");
			}
			cout << endl << endl << endl;
		}
	}
	printConsole("End of service for sub-account SAV" + to_string(savingAcc->getId()));
}

/**
 * Initialize Checking Account menu.
 *
 * @param checkingAcc Checking Account Pointer to be set.
 */
const void initializeCheckingAccount(CheckingAccount* checkingAcc) {
	char checkingAccInput = ' ';
	while (checkingAccInput != 'X' && checkingAccInput != 'x') {
		printServices("sub-account CHK" + to_string(checkingAcc->getId()),checkingAccService,6);
		cin >> checkingAccInput;
		if (checkingAccInput == 'D' || checkingAccInput == 'd') {
			string inputArr[1];
			printInputArray(inputArr, 1, depositInitialize);
			int depositAmount;
			try {
				depositAmount = stoi(inputArr[0]);
			} catch (invalid_argument) {
				depositAmount = -1;
			}

			if (checkingAcc->isLocked()) {
				printConsole("The account is currently locked!");
				printConsole("The deposit was unsuccessful.");
				continue;
			}

			if (depositAmount > 0) {
				checkingAcc->deposit(depositAmount);
				printConsole("Deposit was successful.");
				printConsole("The current balance is " + to_string(checkingAcc->getBalance()));
			} else {
				printConsole("Deposit was unsuccessful.");
			}
			cout << endl << endl << endl;
		} else if (checkingAccInput == 'W' || checkingAccInput == 'w') {
			string inputArr[1];
			printInputArray(inputArr, 1, withdrawInitialize);
			int withdrawAmount;
			try {
				withdrawAmount = stoi(inputArr[0]);
			} catch (invalid_argument) {
				withdrawAmount = INT_MAX;
			}

			if (checkingAcc->isLocked()) {
				printConsole("The account is currently locked!");
				printConsole("The withdraw was unsuccessful.");
				continue;
			}

			if (checkingAcc->getBalance() - withdrawAmount >= 0) {
				checkingAcc->withdraw(withdrawAmount);
				printConsole("Withdraw was successful.");
				printConsole("The current balance is " + to_string(checkingAcc->getBalance()));
			} else {
				printConsole("Withdraw was unsuccessful.");
			}
			cout << endl << endl << endl;
		} else if (checkingAccInput == 'C' || checkingAccInput == 'c') {
			string inputArr[1];
			int maxCap;
			try {
				do {
					printInputArray(inputArr, 1, capInitialize);
					maxCap = stoi(inputArr[0]);
				} while (maxCap < 0 || maxCap < checkingAcc->getBalance());

				checkingAcc->setCap(maxCap);
				printConsole("Max capacity has been set.");
			} catch (invalid_argument) {
				printConsole("Error setting max capacity.");
			}
		} else if (checkingAccInput == 'L' || checkingAccInput == 'l') {
			checkingAcc->setLocked(true);
			printConsole("The sub-account CHK" + to_string(checkingAcc->getId()) + " is locked now!");
		} else if (checkingAccInput == 'U' || checkingAccInput == 'u') {
			checkingAcc->setLocked(false);
			printConsole("The sub-account CHK" + to_string(checkingAcc->getId()) + " is unlocked now!");
		}
	}
	printConsole("End of service for sub-account CHK" + to_string(checkingAcc->getId()));
}

/**
 * Initialize Checking Account menu.
 *
 * @param bankAcc Bank Account Pointer to be set.
 * @param checkingAcc Checking Account Pointer to be set.
 * @param savingAcc Saving Account Pointer to be set.
 */
const void initializeBankAccount(BankAccount* bankAcc, CheckingAccount* checkingAcc, SavingAccount* savingAcc) {
	char bankAccInput = ' ';
	while (bankAccInput != 'X' && bankAccInput != 'x') {
		printServices("Bank-Account BNK" + to_string(bankAcc->getId()),bankAccService,7);
		cin >> bankAccInput;
		if (bankAccInput == 'S' || bankAccInput == 's') {
			string inputArr[1];
			int initBal;
			try {
				do {
					printInputArray(inputArr, 1, savingInitialize);
					initBal = stoi(inputArr[0]);
				} while (initBal < 0);

				savingAcc = bankAcc->createNewSavingAccount(initBal);
				printConsole("A new Saving Sub-Account SAV" + to_string(savingAcc->getId()) + " was successfully created.");
				savingAcc = nullptr;
			} catch (invalid_argument) {
				printConsole("Error creating new Saving Sub-Account.");
			}
		} else if (bankAccInput == 'C' || bankAccInput == 'c') {
			string inputArr[3];
			int initBal;
			int maxCap;
			try {
				do {
					printInputArray(inputArr, 3, checkingInitialize);
					initBal = stoi(inputArr[0]);
					maxCap = stoi(inputArr[1]);
				} while (initBal < 0 || maxCap < 0 || initBal > maxCap);

				bool locked = false;
				if (inputArr[2] == "L" || inputArr[2] == "l")
					locked = true;
				checkingAcc = bankAcc->createNewCheckingAccount(initBal, maxCap, locked);
				printConsole("A new Checking Sub-Account CHK" + to_string(checkingAcc->getId()) +
							 " was successfully created.");
				checkingAcc = nullptr;
			} catch (invalid_argument) {
				printConsole("Error creating new Checking Sub-Account");
			}
		} else if (bankAccInput == 'M' || bankAccInput == 'm') {
			string inputArr[1];
			printInputArray(inputArr, 1, subModifyInitialize);

			string accType;
			int accNumber;

			if (inputArr[0].length() >= 7) {
				accType = inputArr->substr(0,3);
				try {
					accNumber = stoi(inputArr->substr(3, 4));
				} catch (invalid_argument) { /* do nothing */}
			}

			bool foundAccount = false;

			if (accType == "SAV") {
				foundAccount = bankAcc->getSavingAccount(accNumber, savingAcc);
				if (foundAccount)
					initializeSavingAccount(savingAcc);
			} else if (accType == "CHK") {
				foundAccount = bankAcc->getCheckingAccount(accNumber, checkingAcc);
				if (foundAccount)
					initializeCheckingAccount(checkingAcc);
			}
			if (!foundAccount)
				printConsole("Invalid sub-account.");
		} else if (bankAccInput == 'E' || bankAccInput == 'e') {
			string inputArr[1];
			printInputArray(inputArr, 1, subCloseInitialize);

			string accType;
			int accNumber;

			if (inputArr[0].length() >= 7) {
				accType = inputArr->substr(0,3);
				try {
					accNumber = stoi(inputArr->substr(3, 4));
				} catch (invalid_argument) { /* do nothing */}
			}

			bool foundAccount = false;

			if (accType == "SAV") {
				foundAccount = bankAcc->deleteSavingAccount(accNumber);
			} else if (accType == "CHK") {
				foundAccount = bankAcc->deleteCheckingAccount(accNumber);
			}
			if (foundAccount)
				printConsole("Sub-account " + accType + to_string(accNumber) + " was successfully closed.");
			else
				printConsole("Invalid sub-account.");
		} else if (bankAccInput == 'D' || bankAccInput == 'd') {
			string toPrint[100];
			bankAcc->getDetailedPrint(toPrint);
			for (int x = 0; x < 100; x++) {
				if (toPrint[x].empty())
					break;
				if (toPrint[x] == "\n") {
					cout << endl;
					continue;
				}
				printConsole(toPrint[x]);
			}
		} else if (bankAccInput == 'B' || bankAccInput == 'b') {
			printConsole("Aggregated Balance of the bank account : BNK" + to_string(bankAcc->getId()) + " with " +
			to_string(bankAcc->getAccSize()) + " Sub-Accounts is " + to_string(bankAcc->getAggBalance()));
		}
		cout << endl << endl;
	}
	printConsole("End of service for bank-account BNK" + to_string(bankAcc->getId()));
}

/**
 * Initialize Bank menu.
 *
 */
const void initializeBank() {
	string bankInfoArray[3];
	printInputArray(bankInfoArray, 3, bankInitialize);
	cout << endl << endl;

	Bank* bank = new Bank(bankInfoArray[0], bankInfoArray[1], bankInfoArray[2]);
	BankAccount* bankAccount = nullptr;
	CheckingAccount* checkingAccount = nullptr;
	SavingAccount* savingAccount = nullptr;

	char mainBankInput = ' ';
	while (mainBankInput != 'X' && mainBankInput != 'x') {
		printServices(bank->getName(),bankService,9);
		cin >> mainBankInput;

		if (mainBankInput == 'A' || mainBankInput == 'a') {
			printConsole("The number of Bank-Account is " + to_string(BankAccount::bankAccountAmount));
		} else if (mainBankInput == 'S' || mainBankInput == 's') {
			printConsole("The number of Saving-Account is " + to_string(SavingAccount::savingAccountAmount));
		} else if (mainBankInput == 'H' || mainBankInput == 'h') {
			printConsole("The number of Checking-Account is " + to_string(CheckingAccount::checkingAccountAmount));
		} else if (mainBankInput == 'O' || mainBankInput == 'o') {
			cout << endl;
			string inputArr[3];
			printInputArray(inputArr, 3, accountInitialize);
			bankAccount = bank->createNewBankAccount(inputArr[0],inputArr[1],inputArr[2]);
			cout << endl;
			printConsole("A new Bank Account BNK" + to_string(bankAccount->getId()) + " was successfully created.");
			cout << endl << endl;
			initializeBankAccount(bankAccount, checkingAccount, savingAccount);
		} else if (mainBankInput == 'C' || mainBankInput == 'c') {
			string inputArr[1];
			printInputArray(inputArr, 1, accCloseInitialize);

			string accType;
			int accNumber;

			if (inputArr[0].length() >= 8) {
				accType = inputArr->substr(0,3);
				try {
					accNumber = stoi(inputArr->substr(3, 5));
				} catch (invalid_argument) { /* do nothing */}
			}

			bool foundAccount = false;

			if (accType == "BNK") {
				foundAccount = bank->getAccount(accNumber, bankAccount);
			}
			if (foundAccount) {
				bank->deleteAccount(accNumber);
				printConsole("Bank-account " + accType + to_string(accNumber) + " was successfully closed.");
			} else
				printConsole("Invalid bank-account.");
		} else if (mainBankInput == 'M' || mainBankInput == 'm') {
			string inputArr[1];
			printInputArray(inputArr, 1, accModifyInitialize);

			string accType;
			int accNumber;

			if (inputArr[0].length() >= 8) {
				accType = inputArr->substr(0,3);
				try {
					accNumber = stoi(inputArr->substr(3, 5));
				} catch (invalid_argument) { /* do nothing */}
			}

			bool foundAccount = false;

			if (accType == "BNK") {
				foundAccount = bank->getAccount(accNumber, bankAccount);
				if (foundAccount)
					initializeBankAccount(bankAccount, checkingAccount, savingAccount);
			}
			if (!foundAccount)
				printConsole("Invalid bank-account.");
		} else if (mainBankInput == 'D' || mainBankInput == 'd') {
			cout << endl << endl;
			printConsole("Bank Name: " + bank->getName());
			printConsole("Bank Address: " + bank->getAddress());
			printConsole("Bank Working Hours: " + bank->getHours());
			printConsole("Aggregated Balance: " + to_string(bank->getAggBalance()));
			printConsole("Consists of " + to_string(bank->getBankAccounts().size()) + " Bank-Accounts");

			cout << endl << endl;
			for (BankAccount bA : bank->getBankAccounts()) {

				cout << endl << endl;
				printConsole("Bank Account Number: BNK" + to_string(bA.getId()));
				printConsole("Account Holder Full Name: " + bA.getName());
				printConsole("Account Holder SSN: " + bA.getSSN());
				printConsole("Aggregated Balance: " + to_string(bA.getAggBalance()));
				printConsole("Consists of " + to_string(bA.getAccSize()) + " Sub-Accounts");

				string toPrint[100];
				bA.getDetailedPrint(toPrint);
				for (int x = 0; x < 100; x++) {
					if (toPrint[x].empty())
						break;
					if (toPrint[x] == "\n") {
						cout << endl;
						continue;
					}
					printConsole(toPrint[x]);
				}
			}
		} else if (mainBankInput == 'B' || mainBankInput == 'b') {
			cout << endl << endl;
			printConsole("Bank Name: " + bank->getName());
			printConsole("Bank Address: " + bank->getAddress());
			printConsole("Bank Working Hours: " + bank->getHours());
			printConsole("Aggregated Balance: " + to_string(bank->getAggBalance()));
			printConsole("Consists of " + to_string(bank->getBankAccounts().size()) + " Bank-Accounts");
			for (BankAccount bA : bank->getBankAccounts()) {
				printConsole("Aggregated Balance of the bank account : BNK" + to_string(bA.getId()) + " with " +
							 to_string(bA.getAccSize()) + " Sub-Accounts is " +
							 to_string(bA.getAggBalance()));
			}
		}
		cout << endl << endl;
	}

	printConsole("End of service for bank " + bank->getName());

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	system("PAUSE");
}

/**
 * Start of program.
 *
 */
int main() {

	initializeBank();

	return 0;
}
