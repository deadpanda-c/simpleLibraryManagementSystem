#include <iostream>
#include "Book.hpp"

int main(void)
{
  try {
    Book book("livre1", "Author1", "978-1234", false, "");
    Book book2("livre2", "Author2", "978-1234", false, "");
    Book book3("livre3", "Author3", "978-1234", false, "");

    book.display();
    book2.display();
    book3.display();
  } catch (const std::exception& e) {
    Logging::LogError("An error occurred: " + std::string(e.what()));
  }
  return 0;
}
