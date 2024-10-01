#include <controller/ManageUsersController.hpp>
#include <view/db/DatabaseView.hpp>

bool ManageUserController::addUser(const std::string& userId,
                                   const std::string& name) {
  if (userExists(userId)) {
    std::cerr << "Error: User with ID " << userId << " already exists.\n";
    return false;
  }

  database_.addUser(userId, name);
  std::cout << "User " << name << " with ID " << userId
            << " has been added successfully.\n";
  return true;
}

bool ManageUserController::userExists(const std::string& userId) const {
  return database_.getUser(userId) != nullptr;
}

void ManageUserController::printAllUsers(std::ostream& os) const {
  database_.printAllUsers(os);
}
