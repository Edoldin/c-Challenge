#include <controller/ManageCarsController.hpp>
#include <controller/ManageTransactionController.hpp>
#include <controller/ManageUsersController.hpp>
#include <view/client/ClientFactory.hpp>

int main() {
  //DB
  DatabaseView db;

  // Controllers
  ManageUserController userController(db);
  ManageTransactionController transactionController(db);
  ManageCarsController carsController(db);
  //ClientView
  view::client::ClientFactory clientFactory;
  const auto& clientView =
      clientFactory.createClient(view::client::ClientType::CONSOLE);

  // LinkCallbacks
  clientView->setCreateUserCallback([&](const std::string& userId,
                                        const std::string& name) {
    if (userController.addUser(userId, name)) {
      std::cout << "User " << name << " added successfully.\n";
    } else {
      std::cerr << "Error: Could not add user. User ID might already exist.\n";
    }
  });

  clientView->setStartTransactionCallback([&](const std::string& userId,
                                              const std::string& carId) {
    if (transactionController.startTransaction(userId, carId)) {
      std::cout << "Transaction started successfully.\n";
    } else {
      std::cerr
          << "Error: Could not start transaction. User ID might not exist.\n";
    }
  });

  clientView->setEndTransactionCallback([&](int transactionId) {
    if (transactionController.endTransaction(transactionId)) {
      std::cout << "Transaction ended successfully.\n";
    } else {
      std::cerr << "Error: Could not end transaction. Transaction ID might not "
                   "exist.\n";
    }
  });

  clientView->setPrintUsersCallback(
      [&](std::ostream& os) { userController.printAllUsers(os); });

  clientView->setPrintTransactionsCallback(
      [&](std::ostream& os) { transactionController.printTransactions(os); });

  clientView->setPrintCarsCallback(
      [&](std::ostream& os) { carsController.printAllCars(os); });

  // Run View
  clientView->run();

  return 0;
}
