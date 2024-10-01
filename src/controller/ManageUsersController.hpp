#ifndef MANAGEUSERCONTROLLER_HPP
#define MANAGEUSERCONTROLLER_HPP

#include <string>
class DatabaseView;

class ManageUserController {
 public:
  ManageUserController(DatabaseView& db) : database_(db) {}

  // Add a new user
  bool addUser(const std::string& userId, const std::string& name);

  // Check if a user already exists
  bool userExists(const std::string& userId) const;

  // Print all users (for debugging)
  void printAllUsers(std::ostream& os) const;

 private:
  DatabaseView& database_;  // Reference to the mock database
};

#endif  // MANAGEUSERCONTROLLER_HPP