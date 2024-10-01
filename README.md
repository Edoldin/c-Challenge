# 🚗 Car Rental System - C++ Challenge

Welcome to the **Car Rental System**, a C++ challenge project designed to demonstrate object-oriented analysis, modeling skills, and API design principles. This project follows clean code and architecture practices while using modern C++ features.

## 🛠 Environment Setup Decisions

For this project, I made several key environment choices:

- **Operating System**: Windows (for office work) with **WSL** (Windows Subsystem for Linux) as the solution for everything else.
- **IDE**: Visual Studio Code (VSCode) due to its transparency and high configurability.
- **Build System**: CMake, since it's already installed. Otherwise, I would use GCC commands.
- **Version Control**: Git, for source control management.
- **Testing**: A separate binary is used for testing to save time.

## 📦 Dependencies

- **HTTP Library**: [cpp-httplib](https://github.com/yhirose/cpp-httplib) is used for handling HTTP requests, chosen because it is header-only, making compilation easier.

## 🔧 Build Instructions

To compile the project, follow these steps:

```bash
cd build && cmake ..
make
```
This will generate the necessary binaries in the bin/ folder.

## 🚀 Running the Application

- **Test binary** and **CarRentalSystem binary** are both generated in the `bin/` directory. You can execute them directly.

## 🏗 Project Structure

The project follows the **Model-View-Controller (MVC)** architecture pattern, separating concerns between the interface (views), business logic (controllers), and data management (models).

### Views
- **ConsoleView** and **HttpView** can be instantiated independently, providing flexibility in the user interface.
- In the `main.cpp`, views are linked with controllers to manage the flow of data and user interactions.

### Controllers
- Controllers manage data and the business logic, interacting with the model (database) through the `DatabaseView`.
- Ideally, I would have implemented an event-based **linker visitor pattern** to decouple components further, but due to time constraints, I used a simpler approach.

### Models
- The model is managed through `DatabaseView`, which could be extended with a factory pattern (similar to `ClientFactory`) to make the database layer independent of the business logic.

### Pricing Strategy
- A **Strategy Pattern** is used to calculate rental prices based on the type of car (Premium, SUV, or Small), ensuring flexibility and scalability.

## ⚠️ Known Issues and Improvements

- The current implementation calculates the amount owed when the car is returned, but I misread the original problem statement. It doesn't allow setting a rental period at the beginning.
- If time permits, I'll update the implementation to match the exact requirements of the problem statement.
- Like in real life time didn't permited testing.

