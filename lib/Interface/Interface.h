#pragma once
#include "../Weather/Weather.h"
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include "ftxui/dom/node.hpp"
#include "ftxui/screen/color.hpp"
using namespace ftxui;

class Interface {
 public:
  std::vector<Weather> &info;
 public:
  Interface(std::vector<Weather> &weather) : info(weather) {};

  Element moon() {
	return vbox({
					color(Color::GrayLight, text("   *      *    ")),
					color(Color::GrayLight, text("        *      ")),
					color(Color::GrayLight, text(" *          )  ")),
					color(Color::GrayLight, text("        *      ")),
					color(Color::GrayLight, text("   *         * ")),
				});
  }

  Element cloudy_night() {
	return vbox({
					color(Color::GrayLight, text("     *    *   ")),
					color(Color::GrayLight, text("      .--.  ) ")),
					color(Color::GrayLight, text(" * .-(    ).  ")),
					color(Color::GrayLight, text("  (___.__)__) ")),
					color(Color::GrayLight, text("              ")),
				});
  }

  Element sun() {
	return vbox({
					color(Color::Gold1, text("     \\   /     ")),
					color(Color::Gold1, text("      .-.      ")),
					color(Color::Gold1, text("   ― (   ) ―   ")),
					color(Color::Gold1, text("      `-’     ")),
					color(Color::Gold1, text("     /   \\    ")),
				});
  }

  Element fog() {
	return vbox({
					color(Color::SteelBlue, text("              ")),
					color(Color::SteelBlue, text("  _ - _ - _ -  ")),
					color(Color::SteelBlue, text("   _ - _ - _   ")),
					color(Color::SteelBlue, text("  _ - _ - _ -  ")),
					color(Color::SteelBlue, text("               ")),

				});
  }

  Element cloud() {
	return vbox({
					color(Color::White, text("               ")),
					color(Color::White, text("      .--.    ")),
					color(Color::White, text("   .-(    ).   ")),
					color(Color::White, text("  (___.__)__) ")),
					color(Color::White, text("              ")),
				});
  }

  Element sun_cloud() {
	return vbox({
					color(Color::Gold1, text("    \\  /       ")),
					hbox({color(Color::Gold1, text("  _ /\"\"")), color(Color::White, text(".-.    "))}),
					hbox({color(Color::Gold1, text("    \\_")), color(Color::White, text("(   ).   "))}),
					hbox({color(Color::Gold1, text("    /")), color(Color::White, text("(___(__)  "))}),
					text("               "),

				});
  }

  Element snow() {
	return vbox({
					color(Color::GrayLight, text("      .--.    ")),
					color(Color::GrayLight, text("   .-(    ).   ")),
					color(Color::GrayLight, text("  (___.__)__) ")),
					color(Color::White, text("  *  *  *  *  ")),
					color(Color::White, text(" *  *  *  *   ")),

				});
  }

  Element thunder() {
	return vbox({
					color(Color::White, text("      .--.    ")),
					color(Color::White, text("   .-(    ).   ")),
					color(Color::White, text("  (__..__)__) ")),
					color(Color::White, text("  ‘  /  ‘  ‘   ")),
					color(Color::White, text(" ‘   \  ‘  ‘   ")),

				});
  }

  Element rain() {
	return vbox({
					color(Color::GrayLight, text("      .--.    ")),
					color(Color::GrayLight, text("   .-(    ).   ")),
					color(Color::GrayLight, text("  (___.__)__) ")),
					color(Color::DeepSkyBlue2, text("  ‘  ‘  ‘  ‘  ")),
					color(Color::DeepSkyBlue2, text(" ‘  ‘  ‘  ‘   ")),

				});
  }

  Element What_weather(int time, int cur_day, int cur_city) {
	if (info[cur_city].weather_code[cur_day][time] == 0 || info[cur_city].weather_code[cur_day][time] == 1) {
	  if (time == 0) {
		return moon();
	  } else {
		return sun();
	  }
	} else if (info[cur_city].weather_code[cur_day][time] == 2) {
	  if (time == 0) {
		return cloudy_night();
	  } else {
		return sun_cloud();
	  }
	} else if (info[cur_city].weather_code[cur_day][time] == 4) {
	  return cloud();
	} else if (info[cur_city].weather_code[cur_day][time] == 45 || info[cur_city].weather_code[cur_day][time] == 48) {
	  return fog();
	} else if (info[cur_city].weather_code[cur_day][time] == 51 ||
		info[cur_city].weather_code[cur_day][time] == 53 ||
		info[cur_city].weather_code[cur_day][time] == 55 ||
		info[cur_city].weather_code[cur_day][time] == 56 ||
		info[cur_city].weather_code[cur_day][time] == 57 ||
		info[cur_city].weather_code[cur_day][time] == 61 ||
		info[cur_city].weather_code[cur_day][time] == 63 ||
		info[cur_city].weather_code[cur_day][time] == 65 ||
		info[cur_city].weather_code[cur_day][time] == 66 ||
		info[cur_city].weather_code[cur_day][time] == 67 ||
		info[cur_city].weather_code[cur_day][time] == 80 ||
		info[cur_city].weather_code[cur_day][time] == 81 ||
		info[cur_city].weather_code[cur_day][time] == 82) {
	  return rain();
	} else if (info[cur_city].weather_code[cur_day][time] == 71 ||
		info[cur_city].weather_code[cur_day][time] == 73 ||
		info[cur_city].weather_code[cur_day][time] == 75 ||
		info[cur_city].weather_code[cur_day][time] == 77 ||
		info[cur_city].weather_code[cur_day][time] == 85 ||
		info[cur_city].weather_code[cur_day][time] == 86) {
	  return snow();
	} else if (info[cur_city].weather_code[cur_day][time] == 95 ||
		info[cur_city].weather_code[cur_day][time] == 96 ||
		info[cur_city].weather_code[cur_day][time] == 99) {
	  return thunder();
	}
  }

  std::string What_weather_in_string(int time, int cur_day, int cur_city) {
	if (info[cur_city].weather_code[cur_day][time] == 0 || info[cur_city].weather_code[cur_day][time] == 1) {
	  return "Clear";
	} else if (info[cur_city].weather_code[cur_day][time] == 2) {
	  return "Partly Cloudy";
	} else if (info[cur_city].weather_code[cur_day][time] == 4) {
	  return "Cloudy";
	} else if (info[cur_city].weather_code[cur_day][time] == 45 || info[cur_city].weather_code[cur_day][time] == 48) {
	  return "Foggy";
	} else if (info[cur_city].weather_code[cur_day][time] == 51 ||
		info[cur_city].weather_code[cur_day][time] == 53 ||
		info[cur_city].weather_code[cur_day][time] == 55 ||
		info[cur_city].weather_code[cur_day][time] == 56 ||
		info[cur_city].weather_code[cur_day][time] == 57 ||
		info[cur_city].weather_code[cur_day][time] == 61 ||
		info[cur_city].weather_code[cur_day][time] == 63 ||
		info[cur_city].weather_code[cur_day][time] == 65 ||
		info[cur_city].weather_code[cur_day][time] == 66 ||
		info[cur_city].weather_code[cur_day][time] == 67 ||
		info[cur_city].weather_code[cur_day][time] == 80 ||
		info[cur_city].weather_code[cur_day][time] == 81 ||
		info[cur_city].weather_code[cur_day][time] == 82) {
	  return "Rainy";
	} else if (info[cur_city].weather_code[cur_day][time] == 71 ||
		info[cur_city].weather_code[cur_day][time] == 73 ||
		info[cur_city].weather_code[cur_day][time] == 75 ||
		info[cur_city].weather_code[cur_day][time] == 77 ||
		info[cur_city].weather_code[cur_day][time] == 85 ||
		info[cur_city].weather_code[cur_day][time] == 86) {
	  return "Snowy";
	} else if (info[cur_city].weather_code[cur_day][time] == 95 ||
		info[cur_city].weather_code[cur_day][time] == 96 ||
		info[cur_city].weather_code[cur_day][time] == 99) {
	  return "Thunder";
	}
  }

  Element BoxConstruct(const std::string &daytime, const std::string &weather, int time, int cur_day, int cur_city) {
	return vbox({
					text(daytime) | center,
					separator(),
					hbox({
							 What_weather(time, cur_day, cur_city),
							 vbox({
									  text(weather),
									  text(info[cur_city].temperature[cur_day][time] + "C"),
									  text(info[cur_city].windspeed[cur_day][time] + "km/h"),
									  text(info[cur_city].precipitation_probability[cur_day][time] + "%"),
								  }),
						 }),
				});
  };

  Element DayConstruct(int cur_city, int cur_day) {
	return vbox({text(info[cur_city].date[cur_day]) | center, hbox({
																	   BoxConstruct("Night",
																					What_weather_in_string(0,
																										   cur_day,
																										   cur_city),
																					0,
																					cur_day,
																					cur_city),
																	   separator(),
																	   BoxConstruct("Morning",
																					What_weather_in_string(1,
																										   cur_day,
																										   cur_city),
																					1,
																					cur_day,
																					cur_city),
																	   separator(),
																	   BoxConstruct("Day",
																					What_weather_in_string(2,
																										   cur_day,
																										   cur_city),
																					2,
																					cur_day,
																					cur_city),
																	   separator(),
																	   BoxConstruct("Evening",
																					What_weather_in_string(3,
																										   cur_day,
																										   cur_city),
																					3,
																					cur_day,
																					cur_city),
																   }) | borderStyled(ROUNDED)});
  };

  void print(int cur_city, int cur_day) {
	auto document = DayConstruct(cur_city, cur_day);
	auto screen =
		Screen::Create(Dimension::Fit(document), Dimension::Fit(document));
	Render(screen, document);
	screen.Print();
	std::cout << '\n';
  }
};

