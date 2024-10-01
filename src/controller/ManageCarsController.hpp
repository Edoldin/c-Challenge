#ifndef MANAGECARSCONTROLLER_HPP
#define MANAGECARSCONTROLLER_HPP

#include <iostream>
#include <model/Car.hpp>

class DatabaseView;

class ManageCarsController {
public:
 ManageCarsController(DatabaseView& db);

 bool addCar(const std::string& CarsId, const Car::CarType& type);

 bool CarExists(const std::string& CarsId) const;

 void printAllCars(std::ostream& os) const;

private:
    DatabaseView& database_;  // Reference to the mock database
};

#endif // MANAGECARSCONTROLLER_HPP