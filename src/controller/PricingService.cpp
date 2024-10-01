#include <controller/PricingService.hpp>
#include <model/PricingStrategy.hpp>
#include <stdexcept>

double PricingService::calculateRentalPrice(const Car& car, int daysRented) {
  auto pricingStrategy = getPricingStrategy(car.getType());
  return pricingStrategy->calculatePrice(daysRented);
}

double PricingService::calculateLateFee(const Car& car, int extraDays) {
  auto pricingStrategy = getPricingStrategy(car.getType());
  return pricingStrategy->calculateLateFee(extraDays);
}

std::shared_ptr<PricingStrategy> PricingService::getPricingStrategy(
    Car::CarType type) {
  switch (type) {
    case Car::CarType::Premium:
      return std::make_shared<PremiumPricingStrategy>();
    case Car::CarType::SUV:
      return std::make_shared<SuvPricingStrategy>();
    case Car::CarType::Small:
      return std::make_shared<SmallPricingStrategy>();
  }
  throw std::invalid_argument("Unknown car type");
}
