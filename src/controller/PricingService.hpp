#include <model/Car.hpp>
#include <memory>


class PricingStrategy;

class PricingService {
public:
 static double calculateRentalPrice(const Car& car, int daysRented);

 static double calculateLateFee(const Car& car, int extraDays);

private:
 static std::shared_ptr<PricingStrategy> getPricingStrategy(Car::CarType type);
};