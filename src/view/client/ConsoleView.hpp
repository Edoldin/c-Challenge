#ifndef CONSOLEVIEW_HPP
#define CONSOLEVIEW_HPP

#include <functional>
#include <iostream>
#include <string>
#include <view/client/ClientInterface.hpp>

namespace view {
namespace client {
class ConsoleView : public ClientInterface {
 public:
  void run() override {
    bool running = true;
    while (running) {
      displayMenu();
      int option;
      //bug only support numbers
      std::cin >> option;
      switch (option) {
        case 1:
          createUser();
          break;
        case 2:
          startTransaction();
          break;
        case 3:
          endTransaction();
          break;
        case 4:
          getCharges();
          break;
        case 5:
          if (printUsersCallback_)
            printUsersCallback_(std::cout);
          break;
        case 6:
          if (printTransactionsCallback_)
            printTransactionsCallback_(std::cout);
          break;
        case 7:
          if (printCarsCallback_)
            printCarsCallback_(std::cout);
          break;
        case 8:
          running = false;
          break;
        default:
          std::cerr << "Invalid option. Please try again.\n";
      }
    }
  }

 private:
  // Display menu options to the user
  void displayMenu() const {
    std::cout << "\n--- Car Rental System ---\n";
    std::cout << "1. Add a new user\n";
    std::cout << "2. Start a new transaction (rent a car)\n";
    std::cout << "3. End a transaction (return a car)\n";
    std::cout << "4. Get charges\n";
    std::cout << "5. Print all users\n";
    std::cout << "6. Print all transactions\n";
    std::cout << "7. Print all cars\n";
    std::cout << "8. Exit\n";
    std::cout << "Please select an option: ";
  }

  // Function to create a user
  void createUser() {
    if (!createUserCallback_)
      return;

    std::string userId, name;
    std::cout << "Enter User ID: ";
    std::cin >> userId;
    std::cout << "Enter User Name: ";
    std::cin >> name;

    createUserCallback_(userId, name);  // Call the provided callback
  }

  // Function to start a new transaction
  void startTransaction() {
    if (!startTransactionCallback_)
      return;

    std::string userId;
    std::cout << "Enter User ID to start a transaction: ";
    std::cin >> userId;

    std::string carId;
    std::cout << "Enter Car ID to start a transaction: ";
    std::cin >> carId;

    startTransactionCallback_(userId, carId);  // Call the provided callback
  }

  // Function to end a transaction
  void endTransaction() {
    if (!endTransactionCallback_)
      return;

    int transactionId;
    std::cout << "Enter Transaction ID to end: ";
    std::cin >> transactionId;

    endTransactionCallback_(transactionId);  // Call the provided callback
  }

  void getCharges() {
    if (!getUserChargesCallback_)
      return;

    std::string userId;
    std::cout << "Enter User ID to start a transaction: ";
    std::cin >> userId;

    getUserChargesCallback_(userId, std::cout);  // Call the provided callback
  }
};
}  // namespace client
}  // namespace view
#endif  // CONSOLEVIEW_HPP
