#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <uuid/uuid.h>
#include <exception>
#include <cstring>
#include <stdint.h>
#include <array>

#include "Logging.hpp"

class User {
  public:
    class UserException : public std::exception {
      public:
        UserException(const std::string& message) : msg(message) {}
        virtual const char* what() const noexcept override {
            return msg.c_str();
        }
      private:
        std::string msg;
    };

    User(const std::string &name);
    ~User();

    void display() const;
    void borrowBook(const std::string &bookISBN);

    std::string getStringUuid() const;
    std::array<uint8_t, 16> getUuid() const;
    std::string getName() const;

  private:
    std::string _name;
    uuid_t _uuid;
    std::vector<std::string> _borrowedBooksISBNs;
};
