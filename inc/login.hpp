#ifndef __LOGIN__
#define __LOGIN__

#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

std::string login();
json search(std::string token, std::string seriesName);

const json APIKEY = "{\"apikey\": \"4205WF0K63GQTEAO\"}";
const std::string APIURL = "https://api.thetvdb.com";

#endif