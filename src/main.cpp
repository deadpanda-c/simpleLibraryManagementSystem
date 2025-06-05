#include <iostream>
#include "User.hpp"

int main(void)
{
  try {
    uuid_t userId;
    std::vector<std::string> books = {"1984", "Brave New World", "Fahrenheit 451"};

    uuid_generate(userId);

    User user1("Toto", userId, books);

    user1.display();
  } catch (const std::exception& e) {
    Logging::LogError("An error occurred: " + std::string(e.what()));
  }
  return 0;
}
