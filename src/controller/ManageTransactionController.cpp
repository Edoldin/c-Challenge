#include <controller/ManageTransactionController.hpp>
#include <view/db/DatabaseView.hpp>

bool ManageTransactionController::startTransaction(const std::string& userId,
                                                   const std::string& carId) {
  auto user = database_.getUser(userId);
  if (user == nullptr) {
    std::cerr << "Error: User with ID " << userId << " not found.\n";
    return false;
  }

  auto car = database_.getCar(carId);
  if (car == nullptr) {
    std::cerr << "Error: Car with ID " << carId << " not found.\n";
    return false;
  }

  // Start a new transaction for this user (use the current time as the rental date)
  auto rentalDate = std::chrono::system_clock::now();
  database_.startTransaction(userId, carId, rentalDate);

  std::cout << "Transaction started for user " << userId << " and carId "
            << carId << " at "
            << std::chrono::system_clock::to_time_t(rentalDate) << ".\n";
  return true;
}


bool ManageTransactionController::endTransaction(int transactionId) {
  auto transactionOpt = database_.getTransaction(transactionId);
  if (!transactionOpt.has_value()) {
    std::cerr << "Error: Transaction with ID " << transactionId
              << " not found.\n";
    return false;
  }

  // Set the return date as now
  auto returnDate = std::chrono::system_clock::now();
  bool success = database_.setTransactionReturnDate(transactionId, returnDate);
  if (success) {
    auto transaction = transactionOpt.value();
    std::cout << "Transaction " << transactionId
              << " ended. Total days rented: "
              << transaction->calculateRentalDays() << "\n";
    return true;
  }

  std::cerr << "Error: Could not set the return date for transaction ID "
            << transactionId << ".\n";
  return false;
}


void ManageTransactionController::getUserCharges(const std::string& userId,
                                                 std::ostream& os) {
  double dinero = 0;
  for (auto transaction : database_.getUserTransactions(userId)) {
    const auto& car = *database_.getCar(transaction->getCarId());
    dinero += PricingService::calculateRentalPrice(
        car, transaction->calculateRentalDays());
  }
  os << "El precio a pagar por el usuario " << userId << " es " << dinero
     << std::endl;
}


void ManageTransactionController::printTransactions(std::ostream& os) const {
  database_.printAllTransactions(os);
}
