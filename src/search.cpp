#include "login.hpp"
#include <cpr/cpr.h>
#include <iostream>

json search(std::string token, std::string seriesName) {

  while (seriesName.find(" ") != std::string::npos) {
    seriesName.replace(seriesName.find(" "), 1, "%20");
  }

  cpr::Response r = cpr::Get(
      cpr::Url{APIURL + "/search/series?name=" + seriesName},
      cpr::Bearer{token}, cpr::Header{{"Content-Type", "application/json"}},
      cpr::Timeout{10000});

  if (r.status_code != 200) {
    std::cerr << "Error searching for series." << std::endl;
    exit(EXIT_FAILURE);
  }

  return json::parse(r.text);
}