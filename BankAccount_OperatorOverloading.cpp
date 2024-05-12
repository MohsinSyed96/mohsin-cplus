#include <iostream>
#include <string>
using namespace std;

//With overloading cout operator and to use it as a friend function
#include <iostream>
#include <string>
using namespace std;


class BankAccount {
private:
	int balance;
public:
	BankAccount(int initbalance) : balance{ initbalance } {};
	int getbalance() const {
		return this->balance;
	}
public:
	BankAccount operator+(const BankAccount& operandTwo) {
		cout << "Operator Overloading" << endl;
		BankAccount newAccount{ 0 };
		newAccount.balance = this->getbalance() + operandTwo.getbalance();
		return newAccount;
	}
	friend ostream& operator<<(ostream& out, const BankAccount& operandTwo) {
		out << "Current balance is " << operandTwo.balance;
		return out;
	}
	~BankAccount() {
		cout << "Destructor is called" << endl;
	}
};

int main() {
	BankAccount acc1(1000);
	BankAccount acc2(2000);
	cout << acc1 << endl;
	cout << acc2 << endl;
	BankAccount acc3 = acc1 + acc2;
	cout << acc3 << endl;
}