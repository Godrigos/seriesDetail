#include "login.hpp"
#include <cpr/cpr.h>
#include <iostream>

std::string login() {
  cpr::Response r = cpr::Post(cpr::Url{APIURL + "/login"}, cpr::Body{APIKEY},
                              cpr::Header{{"Content-Type", "application/json"}},
                              cpr::Timeout{10000});

  std::string token = r.text;

  if (r.status_code != 200) {
    std::cerr << "Error trying to login to The TVDB." << std::endl;
    exit(EXIT_FAILURE);
  }

  return token;
}