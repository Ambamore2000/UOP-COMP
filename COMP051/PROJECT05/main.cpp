#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

//Chart of Accounts
class ChartOfAccounts {
public:
    ChartOfAccounts(string number, string name, string type);
    string getNumber();
    string getName();
    string getType();
    int getBalance();
    void setBalance(int x);
private:
    //o	The account class definition consists of the following attributes:
    //	Number
    //	Name
    //	Type – Which will be “Revenue” or “Expense” or “Balance Sheet”
    //	Balance – Initialize to zero. This represents the total amount from all of the transactions per account.
    string number,
    name,
    type;
    int balance = 0;
};

//Create a general constructor and use this to initialize each slot in the array.
ChartOfAccounts::ChartOfAccounts(string number, string name, string type) {
    this->number = number;
    this->name = name;
    this->type = type;
}

//o	Create accessors for each of the attributes.
string ChartOfAccounts::getNumber() {
    return number;
}
string ChartOfAccounts::getName() {
    return name;
}
string ChartOfAccounts::getType() {
    return type;
}
int ChartOfAccounts::getBalance() {
    return balance;
}
/////////////////////////////////////////////////

//o	Create a mutator for balance.
void ChartOfAccounts::setBalance(int x) {
    balance = x;
}
/////////////////////////////////////////////////

//JE Transaction Header
class JETransactionHeader {
private:
    //o	Attributes:
    //	Date of JE – This can be represented as a string.
    //	Transaction ID – Uniquely identifies each journal
    //	Memo – Description of the entry
    //	Valid – Indicates whether the JE is valid or not
    //	Lines – This would be an array or vector (extra credit) of the debits and credits in the JE
    //	Line count – Represents the total number of lines in the journal (array size)
    string dateOfJE;
    string transactionID;
    string memo;
    bool valid;
    vector<string> lines;
    int lineCount; //vector size??
public:
    bool isValid(ChartOfAccounts chartOfAccounts[], string id);
    void updateBalance(ChartOfAccounts chartOfAccounts[], string id, int amount, bool isDebit);
    void create(string date, string id, string notes);
    void insertLine(string lineToAdd);
};

//	Create – Updates the date, transaction ID, and memo fields from the data file.
void JETransactionHeader::create(string date, string id, string description) {
    dateOfJE = date;
    transactionID = id;
    memo = description;
}
    //	Insert line – Inserts a line from the file into the journal.
void JETransactionHeader::insertLine(string lineToAdd) {
    lines.push_back(lineToAdd);
}

//0	8/31/19	AugustTransactions	JE-100
//1	50000	0	1000
string findLastWord(string &line) {
    if (line.rfind("\t\t") != string::npos) {
        line = line.replace(line.rfind("\t\t"), 2, "\t");
    }
    string word;
    word = line.substr(line.rfind('\t'), line.length() - line.rfind('\t'));
    word = word.substr(word.find_first_not_of('\t'), word.length() - word.find_first_not_of('\t'));
    line = line.substr(0, line.find_last_of('\t'));
    return word;
}

//	Validate – This is the key function to write.
// It will be easiest to read in all of the data from the file without error checking in that function (see below).
// After all of the data is read in, call this function to determine if a specific JE is valid or not.
// It will need to receive the chart of accounts array. And it should update the valid property of the class. Check for the following errors:
//	isValid – Returns whether the specific JE is valid. You only want to add valid JEs to the income statement report.
bool JETransactionHeader::isValid(ChartOfAccounts chartOfAccounts[], string id) {
    for (int x = 0; x < 13; x++) {
        if (chartOfAccounts[x].getNumber() == id)
            return true;
    }
    return false;
}
//	Update Balances – This function should go through every line on the journal and add (debit) or subtract (credit)
// the line amount from the appropriate account balance.
// It should only process a valid journal.
// A debit will increase the balance amount,
// while a credit will decrease a balance amount.
// Pass in the Chart of Accounts array to the function.

void JETransactionHeader::updateBalance(ChartOfAccounts chartOfAccounts[], string id, int amount, bool isDebit) {
    for (int x = 0; x < 13; x++) {
        if (chartOfAccounts[x].getNumber() == id) {
            if (isDebit)
                chartOfAccounts[x].setBalance(chartOfAccounts[x].getBalance() + amount);
            else
                chartOfAccounts[x].setBalance(chartOfAccounts[x].getBalance() - amount);
            break;
        }
    }
}

void readData(ChartOfAccounts chartOfAccounts[], JETransactionHeader jeTransactionHeader[]) { //TODO input parameter, array of some bullshit
    cout << endl << "Validating Journals:" << endl;
    ifstream readFile;
    readFile.open("C:\\Users\\Andki\\CLionProjects\\COMP51_Andrew_Kim_Project_Five\\journals.txt");

    string line;
    //bool continueUntilZero = false;
    int x = 0;
    while (getline(readFile, line)) {
        int debit = 0, credit = 0;
        string lineNumber, date, memo, transIDOrAccNum, transactionID, accountNumber;
        if (line.rfind('0', 0) == 0) {
            transactionID = findLastWord(line);
            memo = findLastWord(line);
            date = findLastWord(line);
            jeTransactionHeader[x].create(date, transactionID, memo);
        } else {
            jeTransactionHeader[x].insertLine(line);
            accountNumber = findLastWord(line);
            credit = stoi(findLastWord(line));
            debit = stoi(findLastWord(line));

            bool isDebit = false;
            int amount = credit;
            if (debit > 0) {
                isDebit = true;
                amount = debit;
            }

            jeTransactionHeader[x].updateBalance(chartOfAccounts, accountNumber, amount, isDebit);
        }
        /*
        int debit = 0, credit = 0;
        string lineNumber, date, memo, transIDOrAccNum, transactionID, accountNumber;
        if (line.rfind('0', 0) == 0) {
            transactionID = findLastWord(line);
            memo = findLastWord(line); //TODO Error
            date = findLastWord(line);
            jeTransactionHeader.create(date, transactionID, memo);
            x++;
            continueUntilZero = false;
        } else {
            if (continueUntilZero)
                continue;
            accountNumber = findLastWord(line);
            credit = stoi(findLastWord(line));
            debit = stoi(findLastWord(line));
            if ((!jeTransactionHeader.isValid(chartOfAccounts, accountNumber)) || (debit < 0 || credit < 0) || (debit > 0 && credit > 0)) {
                //  •	Invalid account number on transaction – match against the list in the Chart of Accounts.
                if (!jeTransactionHeader.isValid(chartOfAccounts, accountNumber))
                    cout << "Invalid account number = " << accountNumber << endl;
                //  •	Negative Debit or Credit on a line
                if (debit < 0 || credit < 0)
                    cout << "Debit or credit cannot be negative." << endl;
                //  •	Both debit and credit are non-zero on a line.
                if (debit > 0 && credit > 0)
                    cout << "Debit or credit cannot both be positive." << endl;
                continueUntilZero = true;
                //TODO •	The sum of the debits and credits are not equal.
            }

            bool isDebit = false;
            int amount = credit;
            if (debit > 0) {
                isDebit = true;
                amount = debit;
            }

            jeTransactionHeader.updateBalance(chartOfAccounts, accountNumber, amount, isDebit);
        }
         */
    }
    readFile.close();
}


class JETransactionLines {
private:
    string lineNumber, accountNumber;
    int debit, credit;
public:
    void set(string line, string account, int deb, int cred);
    string getLineNumber();
    string getAccountNumber();
    int getDebit();
    int getCredit();
};

void JETransactionLines::set(string line, string account, int deb = 0, int cred = 0) {
    lineNumber = line;
    accountNumber = account;
    debit = deb;
    credit = cred;
}

string JETransactionLines::getLineNumber() {
    return lineNumber;
}

string JETransactionLines::getAccountNumber() {
    return accountNumber;
}

int JETransactionLines::getDebit() {
    return debit;
}

int JETransactionLines::getCredit() {
    return credit;
}


int main() {
//TODO del ifstream to read

//o	You may hardcode the following account numbers into the array....Insert these in order to make life simpler on the income statement report.
    ChartOfAccounts a("1000","Sales","Revenue"),
    b("1010","Services","Revenue"),
    c("1020","Warranties","Revenue"),
    d("1030","Refunds","Revenue"),
    e("1040","Shipping","Revenue"),
    f("6000","Travel","Expense"),
    g("6005","Meals","Expense"),
    h("6010","Salaries","Expense"),
    i("6020","Supplies","Expense"),
    j("6050","Rent","Expense"),
    k("6060","Repairs","Expense"),
    l("2000","Accounts Receivable","Balance Sheet"),
    m("4000","Accounts Payable","Balance Sheet");
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//This can be represented as an array of Account objects (defined in main()).
    ChartOfAccounts chartOfAccounts[13] = {a, b, c, d, e, f, g, h, i, j, k, l, m};
/////////////////////////////////////////////////////////////////////////////


    cout << "COMP 51 Project 5 - Simple Journal Generator" << endl;

    JETransactionHeader jeTransactionHeader[10];

    readData(chartOfAccounts, jeTransactionHeader);

    system("pause");
    return 0;
}
