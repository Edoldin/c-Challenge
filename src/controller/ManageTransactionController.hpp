#ifndef MANAGETRANSACTIONCONTROLLER_HPP
#define MANAGETRANSACTIONCONTROLLER_HPP

#include <chrono>
#include <controller/PricingService.hpp>
#include <iostream>

class DatabaseView;

class ManageTransactionController {
 public:
  ManageTransactionController(DatabaseView& db) : database_(db) {}

  // Start a transaction for renting a car
  bool startTransaction(const std::string& userId, const std::string& carId);

  // Set the return date for an existing transaction
  bool endTransaction(int transactionId);

  void getUserCharges(const std::string& userId, std::ostream& os);

  // Print all transactions (for debugging or reporting purposes)
  void printTransactions(std::ostream& os) const;

 private:
  DatabaseView& database_;  // Reference to the mock database
};

#endif  // MANAGETRANSACTIONCONTROLLER_HPP