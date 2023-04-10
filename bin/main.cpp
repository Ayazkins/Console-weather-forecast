#include "../lib/Weather/Weather.h"
#include "../lib/Interface/Interface.h"
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>
#include <fstream>

using json = nlohmann::json;

std::vector<std::string> cities;
int update_frequency = 600000;
std::string forecast_days = "7";
std::vector<Weather> all_weather;
int day = 0;
int current_city_size = 0;

void LoadConfig(std::string str_config) {
  std::ifstream file(str_config);
  json config;
  file >> config;
  auto cities_it = config.find("cities");
  for (auto &city : *cities_it) {
	cities.push_back(city);
  }
  if (!(config.find("change_time") == config.end())) {
	update_frequency = std::stoi(config["change_time"].get<std::string>());
  };
  if (!(config.find("forecast_days") == config.end())) {
	forecast_days = config["forecast_days"].get<std::string>();
  };
}

void Update() {
  while (true) {
	std::this_thread::sleep_for(std::chrono::milliseconds(update_frequency));
	for (int i = 0; i < all_weather.size(); i++) {
	  all_weather[i].GetWeather(forecast_days);
	}
	system("cls");
	Interface hello(all_weather);
	std::cout << all_weather[current_city_size].city << '\n';
	for (int i = 0; i < day; i++) {
	  hello.print(current_city_size, i);
	}
  }
}

void Input() {
  const std::string config = "C:\\Users\\10a-y\\CLionProjects\\labwork-10-Ayazkins\\Config.json";
  int MaxDay = std::stoi(forecast_days);
  LoadConfig(config);
  for (int i = 0; i < cities.size(); i++) {
	all_weather.emplace_back(Weather(cities[i], "vTsHAQsuhpixjC8hq8ZTrC8vyRJxiTVV8TDWFph9", forecast_days));
  }
  Interface hello(all_weather);
  std::cout << all_weather[current_city_size].city << '\n';
  for (int i = 0; i < MaxDay; i++) {
	hello.print(current_city_size, i);
  }
  day = MaxDay;
  while (true) {
	int key = _getch();
	if (key == 'n' || key == 'N') {
	  current_city_size = (current_city_size + 1) % cities.size();
	  system("cls");
	  std::cout << all_weather[current_city_size].city << '\n';
	  for (int i = 0; i < day; i++) {
		hello.print(current_city_size, i);
	  }
	} else if (key == 27) {
	  exit(0);
	} else if (key == '+' || key == '=') {
	  day = day + 1;
	  if (day >= MaxDay) {
		day = MaxDay;
	  }
	  system("cls");
	  std::cout << all_weather[current_city_size].city << '\n';
	  for (int i = 0; i < day; i++) {
		hello.print(current_city_size, i);
	  }
	} else if (key == '-' || key == '_') {
	  day = day - 1;
	  if (day <= 0) {
		day = 1;
	  }
	  system("cls");
	  std::cout << all_weather[current_city_size].city << '\n';
	  for (int i = 0; i < day; i++) {
		hello.print(current_city_size, i);
	  }
	}
  }
}

int main() {
  std::thread t1(Update);
  std::thread t2(Input);
  t1.join();
  t2.join();
  return 0;
}


