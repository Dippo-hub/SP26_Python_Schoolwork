#include <iostream>

class Account {
    private: 
        int id;
        double balance, annualInterest;
    public:
        Account() {
            this->balance = 0.0;
            this->id = 0;
            this->annualInterest = 0.0;
        }

        Account(int _id, double _balance, double _annualInterest) {
            this->balance = _balance;
            this->id = _id;
            this->annualInterest = _annualInterest;
        }

        void withdraw(double amount) {
            if (amount > balance)
                std::cout << "Declined, not enough funds" << std::endl;
            else 
                balance -= amount;
        }

        void deposit(double amount) {
            if (amount >=0) {
                balance += amount;
            } else {
                std::cout << "Cannot deposit negative numbers" << std::endl;
            }
        }

        double getBalance() {
            return balance;
        }

        double getInterest() {
            return annualInterest;
        }
};

int main(void) {
    Account bank(1122, 20000, 4.5);
    bank.withdraw(2500);
    bank.deposit(3000);
    std::cout << "Balance for account 1122: " << bank.getBalance() << " with annual interest rate: " << bank.getInterest() << std::endl;
}