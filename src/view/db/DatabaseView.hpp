#ifndef DATABASEVIEW_HPP
#define DATABASEVIEW_HPP

#include <map>
#include <memory>
#include <model/Car.hpp>
#include <model/Transaction.hpp>
#include <model/User.hpp>
#include <optional>
#include <string>
#include <vector>

class DatabaseView {
 public:
  DatabaseView() {
    // Fill initial Data
    addCar("1", Car::CarType::Premium);
    addCar("2", Car::CarType::Small);
    addCar("3", Car::CarType::SUV);
    addUser("1", "Pedro");
    addUser("2", "Juan");
    addUser("3", "Sergio");
  }
  // Add a new user to the database
  void addUser(const std::string& userId, const std::string& name) {
    users_.emplace(userId, std::make_shared<User>(userId, name));
  }

  // Get a user by ID
  std::shared_ptr<User> getUser(const std::string& userId) const {
    auto it = users_.find(userId);
    if (it != users_.end()) {
      return it->second;
    }
    return nullptr;  // User not found
  }

  // Add a new car to the database
  void addCar(const std::string& carId, const Car::CarType& type) {
    cars_.emplace(carId, std::make_shared<Car>(carId, type));
  }

  // Get a car by ID
  std::shared_ptr<Car> getCar(const std::string& carId) const {
    auto it = cars_.find(carId);
    if (it != cars_.end()) {
      return it->second;
    }
    return nullptr;  // User not found
  }

  // Start a new transaction (rental)
  void startTransaction(const std::string& userId, const std::string& carId,
                        const Transaction::TimePoint& rentalDate) {
    if (users_.find(userId) != users_.end()) {
      // Create a new transaction
      auto transaction =
          std::make_shared<Transaction>(userId, carId, rentalDate);
      transactions_.emplace(nextTransactionId_++, transaction);
    } else {
      std::cerr << "User ID " << userId
                << " not found. Transaction not started.\n";
    }
  }

  // Set the return date of a transaction (finish rental)
  bool setTransactionReturnDate(int transactionId,
                                const Transaction::TimePoint& returnDate) {
    auto it = transactions_.find(transactionId);
    if (it != transactions_.end()) {
      it->second->setReturnDate(returnDate);
      return true;
    }
    return false;  // Transaction not found
  }

  // Retrieve a transaction by its ID
  std::optional<std::shared_ptr<Transaction>> getTransaction(
      int transactionId) const {
    auto it = transactions_.find(transactionId);
    if (it != transactions_.end()) {
      return it->second;
    }
    return std::nullopt;
  }

  // List all transactions for a specific user
  std::vector<std::shared_ptr<Transaction>> getUserTransactions(
      const std::string& userId) const {
    std::vector<std::shared_ptr<Transaction>> userTransactions;
    for (const auto& pair : transactions_) {
      if (pair.second->getUserId() == userId) {
        userTransactions.push_back(pair.second);
      }
    }
    return userTransactions;
  }

  // Print all users (for debugging)
  void printAllUsers(std::ostream& os) const {
    for (const auto& pair : users_) {
      os << "User ID: " << pair.second->getUserId()
         << ", Name: " << pair.second->getName() << std::endl;
    }
  }

  // Print all transactions (for debugging)
  void printAllTransactions(std::ostream& os) const {
    for (const auto& pair : transactions_) {
      os << "Transaction ID: " << pair.first
         << ", User ID: " << pair.second->getUserId()
         << ", Car ID: " << pair.second->getCarId()
         << ", Rental Days: " << pair.second->calculateRentalDays()
         << std::endl;
    }
  }
  // Print all transactions (for debugging)
  void printAllCars(std::ostream& os) const {
    for (const auto& pair : cars_) {
      os << "car ID: " << pair.first
         << ", car Type: " << static_cast<int>(pair.second->getType())
         << std::endl;
    }
  }

 private:
  std::map<std::string, std::shared_ptr<User>>
      users_;  // Map of users (userId -> User)
  std::map<std::string, std::shared_ptr<Car>>
      cars_;  // Map of users (userId -> User)
  std::map<int, std::shared_ptr<Transaction>>
      transactions_;  // Map of transactions (transactionId -> Transaction)
  int nextTransactionId_ = 1;  // Auto-incrementing transaction ID
};

#endif  // DATABASEVIEW_HPP
