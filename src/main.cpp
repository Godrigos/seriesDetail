#include "login.hpp"
#include <iomanip>
#include <iostream>

int main(int argc, char *argv[]) {

  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " \"series name\"." << std::endl;
    exit(EXIT_FAILURE);
  }

  std::string token =
      (std::string)json::parse(login()).value("token", "Not Authorized");

  json series = search(token, argv[1]);

  std::cout << std::setw(12) << std::left
            << "* Tile: " << (std::string)series["data"][0]["seriesName"]
            << "\n";
  std::cout << std::setw(12) << std::left
            << "* Status: " << (std::string)series["data"][0]["status"] << "\n";
  if (series["data"][0]["overview"].is_null()) {
    std::cout << std::setw(12) << std::left << "* Synopsis: "
              << "No synopsis available." << std::endl;
  } else {
    std::cout << std::setw(12) << std::left
              << "* Synopsis: " << (std::string)series["data"][0]["overview"]
              << std::endl;
  }

  return EXIT_SUCCESS;
}