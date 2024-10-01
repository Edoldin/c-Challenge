#ifndef CAR_HPP
#define CAR_HPP

#include <string>

class Car {
 public:
  enum class CarType { Premium, SUV, Small };

  Car(const std::string& id, CarType type) : id_(id), type_(type) {}

  std::string geId() const { return id_; }
  CarType getType() const { return type_; }

 private:
  std::string id_;
  CarType type_;
};
#endif  // CAR_HPP