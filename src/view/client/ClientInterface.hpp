#ifndef CLIENTINTERFACE_HPP
#define CLIENTINTERFACE_HPP

#include <functional>
#include <string>

namespace view {
namespace client {

enum class ClientType { CONSOLE, HTTP };

class ClientInterface {
 public:
  // Setters for the callbacks
  void setCreateUserCallback(
      std::function<void(const std::string&, const std::string&)> callback) {
    createUserCallback_ = std::move(callback);
  }

  void setStartTransactionCallback(
      std::function<void(const std::string&, const std::string&)> callback) {
    startTransactionCallback_ = std::move(callback);
  }

  void setEndTransactionCallback(std::function<void(int)> callback) {
    endTransactionCallback_ = std::move(callback);
  }

  void getUserChargesCallback(
      std::function<void(const std::string&, std::ostream&)> callback) {
    getUserChargesCallback_ = std::move(callback);
  }

  void setPrintUsersCallback(std::function<void(std::ostream&)> callback) {
    printUsersCallback_ = std::move(callback);
  }

  void setPrintTransactionsCallback(
      std::function<void(std::ostream&)> callback) {
    printTransactionsCallback_ = std::move(callback);
  }

  void setPrintCarsCallback(std::function<void(std::ostream&)> callback) {
    printCarsCallback_ = std::move(callback);
  }

  virtual void run() = 0;

 protected:
  // Callback members
  std::function<void(const std::string&, const std::string&)>
      createUserCallback_;
  std::function<void(const std::string&, const std::string&)>
      startTransactionCallback_;
  std::function<void(int)> endTransactionCallback_;
  std::function<void(const std::string&, std::ostream&)>
      getUserChargesCallback_;
  std::function<void(std::ostream&)> printUsersCallback_;
  std::function<void(std::ostream&)> printCarsCallback_;
  std::function<void(std::ostream&)> printTransactionsCallback_;
};
}  // namespace client
}  // namespace view
#endif  // CLIENTINTERFACE_HPP
