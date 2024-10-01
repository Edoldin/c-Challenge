#include <string>

class User {
public:
    User(std::string id, std::string name) : userId_(std::move(id)), name_(std::move(name)) {}

    const std::string& getUserId() const {
        return userId_;
    }

    const std::string& getName() const {
        return name_;
    }

private:
    std::string userId_;
    std::string name_;
};
