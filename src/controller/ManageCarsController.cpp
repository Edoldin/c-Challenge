
#include <view/db/DatabaseView.hpp>
#include <controller/ManageCarsController.hpp>

ManageCarsController::ManageCarsController(DatabaseView& db) : database_(db) {}
bool ManageCarsController::addCar(const std::string& CarsId,
                                  const Car::CarType& type) {
  if (CarExists(CarsId)) {
    std::cerr << "Error: Cars with ID " << CarsId << " already exists.\n";
    return false;
  }

  database_.addCar(CarsId, type);
  std::cout << "Cars " << CarsId << " with type " << static_cast<int>(type)
            << " has been added successfully.\n";
  return true;
}

bool ManageCarsController::CarExists(const std::string& CarsId) const {
  return database_.getCar(CarsId) != nullptr;
}

void ManageCarsController::printAllCars(std::ostream& os) const {
  database_.printAllCars(os);
}
