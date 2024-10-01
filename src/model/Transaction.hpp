#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include <chrono>
#include <optional>
#include <string>
#include <iostream>

class Transaction {
public:
    using Clock = std::chrono::system_clock;
    using TimePoint = std::chrono::time_point<Clock>;

    Transaction(const std::string& userId, const std::string& carId, const TimePoint& rentalDate)
        : userId_(userId), carId_(carId), rentalDate_(rentalDate), returnDate_(std::nullopt) {}

    void setReturnDate(const TimePoint& returnDate) {
        returnDate_ = returnDate;
    }

    int calculateRentalDays() const {
        TimePoint timepoint = returnDate_.has_value() ? returnDate_.value() : Clock::now();

        return std::chrono::duration_cast<std::chrono::hours>(timepoint - rentalDate_).count()%24;
    }

    bool isReturned() const {
        return returnDate_.has_value();
    }

    const std::string& getUserId() const {
        return userId_;
    }

    const std::string& getCarId() const {
        return carId_;
    }

    TimePoint getRentalDate() const {
        return rentalDate_;
    }

    std::optional<TimePoint> getReturnDate() const {
        return returnDate_;
    }

private:
    std::string userId_;              // ID of the user who rented the car
    std::string carId_;               // ID of the user who rented the car
    TimePoint rentalDate_;            // Date when the car was rented
    std::optional<TimePoint> returnDate_; // Date when the car was returned (optional)
};

#endif // TRANSACTION_HPP