#include <iostream>
#include <cmath> // Library to use math functions e.g pow

using namespace std;

// CreditCard structure with attributes
struct CreditCard {
   string name;
   double balance;
   double annualInterestRate;
   int numberOfMonths;
};

// Calculate payment on following formula
// Monthly Payment = (Balance * (Interest Rate / 12) * (1 + (Interest Rate / 12))^Number of Months) / ((1 + (Interest Rate / 12))^Number of Months - 1)
double calculatePayment(CreditCard card) {
   double interestRate = card.annualInterestRate / 12 / 100;
   double powerFactor = pow(1 + interestRate, card.numberOfMonths);
   double payment = (card.balance * interestRate * powerFactor) / (powerFactor - 1);
   return payment;
}

int main() {
   CreditCard card; // Object of structure
   
   // Welcome header
   cout << "Welcome to the Credit Card Payment Calculator!" << endl;
   cout<<endl;

   // Input data
   cout << "Please enter your name: ";
   getline(cin, card.name);
   cout << "Please enter your current credit card balance: $";
   cin >> card.balance;
   cout << "Please enter the annual interest rate (in percentage): ";
   cin >> card.annualInterestRate;
   cout << "Please enter the desired number of months to pay off the balance: ";
   cin >> card.numberOfMonths;
   
   // Calculation
   double monthlyPayment = calculatePayment(card);

   // Print output
   cout << "\nHi " << card.name << ",";
   cout << endl << endl;
   cout << "With a current credit card balance of $" << card.balance << "," <<endl;
   cout << "an annual interest rate of " << card.annualInterestRate << "%," <<endl;
   cout << "and a goal to pay off the balance in " << card.numberOfMonths << " months," <<endl;
   cout << "your required monthly payment is $" << monthlyPayment << ".";

   cout << endl << endl;
   cout << "Thank you for using the Credit Card Payment Calculator!" << endl;

   return 0;
}
