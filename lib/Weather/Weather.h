#pragma once
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <iostream>

class Weather {
 public:
  std::string city_la;
  std::string city_lo;
  std::string city;
  std::vector<std::string> date;
  std::vector<std::vector<std::string>> temperature;
  std::vector<std::vector<std::string>> windspeed;
  std::vector<std::vector<int>> weather_code;
  std::vector<std::vector<std::string>> precipitation_probability;
  //они в паблике потому что в interface я их использую
  Weather(std::string city_name, std::string api, std::string days_amount = "1") {
	GetCoordinates(city_name, api);
	GetWeather(days_amount);
  }

  void GetCoordinates(std::string city_name, std::string api) {
	city = city_name;
	cpr::Response city_info = cpr::Get(cpr::Url{"https://api.api-ninjas.com/v1/city"},
									   cpr::Parameters{{"name", city_name}},
									   cpr::Header{{"X-Api-Key", api}});
	nlohmann::json parsed_info = nlohmann::json::parse(city_info.text);
	city_la = parsed_info[0]["latitude"].dump();
	city_lo = parsed_info[0]["longitude"].dump();
  }

  void GetWeather(std::string days_amount = "1") {
	temperature.clear();
	windspeed.clear();
	weather_code.clear();
	precipitation_probability.clear();
	date.clear();
	cpr::Response weather = cpr::Get(cpr::Url{"https://api.open-meteo.com/v1/forecast"},
									 cpr::Parameters{{"latitude", city_la},
													 {"longitude", city_lo},
													 {"timezone", "GMT"},
													 {"forecast_days", days_amount},
													 {"hourly", "temperature_2m"},
													 {"hourly", "windspeed_10m"},
													 {"hourly", "winddirection_10m"},
													 {"hourly", "weathercode"},
													 {"hourly", "visibility"},
													 {"hourly", "precipitation_probability"}
									 });
	int days = std::stoi(days_amount);
	temperature.resize(days);
	windspeed.resize(days);
	weather_code.resize(days);
	precipitation_probability.resize(days);
	nlohmann::json weather_ = nlohmann::json::parse(weather.text);
	for (int i = 0; i < days; i++) {
	  std::string date_and_time = weather_["hourly"]["time"][i * 24].get<std::string>();
	  date.emplace_back(date_and_time.substr(0, 10));
	  for (int j = 1; j <= 24; j += 6) {
		temperature[i].emplace_back(weather_["hourly"]["temperature_2m"][(i + 1) * j].dump());
		windspeed[i].emplace_back(weather_["hourly"]["windspeed_10m"][(i + 1) * j].dump());
		weather_code[i].emplace_back(weather_["hourly"]["weathercode"][(i + 1) * j].get<int>());
		precipitation_probability[i].emplace_back(weather_["hourly"]["precipitation_probability"][(i + 1)
			* j].dump());
	  }
	}
  }
};
