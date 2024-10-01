#ifndef HTTPVIEW_HPP
#define HTTPVIEW_HPP

#include <../3rdparty/cpp-httplib/httplib.h>
#include <functional>
#include <string>
#include <view/client/ClientInterface.hpp>
namespace view {
namespace client {

class HttpView : public ClientInterface {
 public:
  // Start the HTTP server
  void run() override {
    // Endpoint to create a new user
    server_.Post("/createUser", [&](const httplib::Request& req,
                                    httplib::Response& res) {
      auto userId = req.get_param_value("userId");
      auto name = req.get_param_value("name");

      if (createUserCallback_) {
        createUserCallback_(userId, name);
        res.set_content("User created successfully\n", "text/plain");
      } else {
        res.set_content("Error: createUserCallback is not set\n", "text/plain");
      }
    });

    // Endpoint to start a new transaction
    server_.Post("/startTransaction", [&](const httplib::Request& req,
                                          httplib::Response& res) {
      auto userId = req.get_param_value("userId");
      auto carId = req.get_param_value("carId");

      if (startTransactionCallback_) {
        startTransactionCallback_(userId, carId);
        res.set_content("Transaction started successfully\n", "text/plain");
      } else {
        res.set_content("Error: startTransactionCallback is not set\n",
                        "text/plain");
      }
    });

    // Endpoint to end a transaction
    server_.Post("/endTransaction", [&](const httplib::Request& req,
                                        httplib::Response& res) {
      auto transactionId = std::stoi(req.get_param_value("transactionId"));

      if (endTransactionCallback_) {
        endTransactionCallback_(transactionId);
        res.set_content("Transaction ended successfully\n", "text/plain");
      } else {
        res.set_content("Error: endTransactionCallback is not set\n",
                        "text/plain");
      }
    });

    // Endpoint to get charges
    server_.Post("/getUserCharges", [&](const httplib::Request& req,
                                        httplib::Response& res) {
      auto userId = req.get_param_value("userId");

      if (getUserChargesCallback_) {
        std::ostringstream os;
        getUserChargesCallback_(userId, os);
        res.set_content(os.str(), "text/plain");
      } else {
        res.set_content("Error: getUserCharges is not set\n", "text/plain");
      }
    });

    // Endpoint to print all users
    server_.Get("/printUsers", [&](const httplib::Request& /*req*/,
                                   httplib::Response& res) {
      if (printUsersCallback_) {
        std::ostringstream os;
        printUsersCallback_(os);
        res.set_content(os.str(), "text/plain");
      } else {
        res.set_content("Error: printUsersCallback is not set\n", "text/plain");
      }
    });

    // Endpoint to print all transactions
    server_.Get("/printTransactions", [&](const httplib::Request& /*req*/,
                                          httplib::Response& res) {
      if (printTransactionsCallback_) {
        std::ostringstream os;
        printTransactionsCallback_(os);
        res.set_content(os.str(), "text/plain");
      } else {
        res.set_content("Error: printTransactionsCallback is not set\n",
                        "text/plain");
      }
    });

    server_.Get("/printCars", [&](const httplib::Request& /*req*/,
                                  httplib::Response& res) {
      if (printTransactionsCallback_) {
        std::ostringstream os;
        printCarsCallback_(os);
        res.set_content(os.str(), "text/plain");
      } else {
        res.set_content("Error: printTransactionsCallback is not set\n",
                        "text/plain");
      }
    });

    // Start the server on the specified port
    server_.listen("localhost", 3030);
  }

 private:
  httplib::Server server_;  // HTTP server instance
};
}  // namespace client
}  // namespace view
#endif  // HTTPVIEW_HPP
