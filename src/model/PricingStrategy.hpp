#ifndef PRICINGSTRATEGY_HPP
#define PRICINGSTRATEGY_HPP

class PricingStrategy {
 public:
  virtual double calculatePrice(int daysRented) const = 0;
  virtual double calculateLateFee(int extraDays) const = 0;
  virtual ~PricingStrategy() = default;
  static constexpr float premium_price_ = 300;
  static constexpr float suv_price_ = 150;
  static constexpr float small_price_ = 50;
};

class PremiumPricingStrategy : public PricingStrategy {
 public:
  double calculatePrice(int daysRented) const override {
    return daysRented * premium_price_;
  }

  double calculateLateFee(int extraDays) const override {
    return extraDays * (premium_price_ * 1.2);
  }
};

class SuvPricingStrategy : public PricingStrategy {
  double calculatePrice(int daysRented) const override {
    if (daysRented <= 7)
      return daysRented * suv_price_;
    else if (daysRented <= 30)
      return daysRented * suv_price_ * 0.8;
    else
      return daysRented * suv_price_ * 0.5;
  }

  double calculateLateFee(int extraDays) const override {
    return extraDays * (suv_price_ + small_price_ * 0.6);
  }
};

class SmallPricingStrategy : public PricingStrategy {
  double calculatePrice(int daysRented) const override {
    if (daysRented <= 7)
      return daysRented * small_price_;
    else if (daysRented <= 30)
      return daysRented * small_price_ * 0.8;
    else
      return daysRented * small_price_ * 0.5;
  }

  double calculateLateFee(int extraDays) const override {
    return extraDays * small_price_ * 1.3;
  }
};
#endif  // PRICINGSTRATEGY_HPP