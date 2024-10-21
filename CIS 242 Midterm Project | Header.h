#pragma once
#include <string>

class BankAccount {
protected:
	std::string username;
	std::string password;
	std::string userInputUsername;
	std::string userInputPassword;
public:
	BankAccount();
};

class BankActions : public BankAccount{
private:
	double savingsAccountBalance;
	double AnnualPercentageYeild;
	double savingsAccountAPY;
public:
	void checkAccountCredentials(bool& validSelection);
	BankActions();
	std::string displayBalance();
	std::string displayUserInputAmount(double& userDecimalInput);
	void checkValidSelection(int& userNumberInput);
	void depositAmount(double& userDecimalInput);
	void withdrawalAmount(double& userDecimalInput);
	void displayAnnualPercentageYeild();
};
