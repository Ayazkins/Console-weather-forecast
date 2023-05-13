#pragma once
#include "../Weather/Weather.h"
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include "ftxui/dom/node.hpp"
#include "ftxui/screen/color.hpp"

class Interface {
 private:
  std::vector<Weather> info;
 public:
  Interface(std::vector<Weather> weather) : info(weather) {};

  ftxui::Element moon() {
	return ftxui::vbox({
					color(ftxui::Color::GrayLight, ftxui::text("   *      *    ")),
					color(ftxui::Color::GrayLight, ftxui::text("        *      ")),
					color(ftxui::Color::GrayLight, ftxui::text(" *          )  ")),
					color(ftxui::Color::GrayLight, ftxui::text("        *      ")),
					color(ftxui::Color::GrayLight, ftxui::text("   *         * ")),
				});
  }

  ftxui::Element cloudy_night() {
	return ftxui::vbox({
					color(ftxui::Color::GrayLight,ftxui::text("     *    *   ")),
					color(ftxui::Color::GrayLight, ftxui::text("      .--.  ) ")),
					color(ftxui::Color::GrayLight, ftxui::text(" * .-(    ).  ")),
					color(ftxui::Color::GrayLight, ftxui::text("  (___.__)__) ")),
					color(ftxui::Color::GrayLight, ftxui::text("              ")),
				});
  }

  ftxui::Element sun() {
	return ftxui::vbox({
					color(ftxui::Color::Gold1, ftxui::text("     \\   /     ")),
					color(ftxui::Color::Gold1, ftxui::text("      .-.      ")),
					color(ftxui::Color::Gold1, ftxui::text("   ― (   ) ―   ")),
					color(ftxui::Color::Gold1, ftxui::text("      `-’     ")),
					color(ftxui::Color::Gold1, ftxui::text("     /   \\    ")),
				});
  }

  ftxui::Element fog() {
	return ftxui::vbox({
					color(ftxui::Color::SteelBlue, ftxui::text("              ")),
					color(ftxui::Color::SteelBlue, ftxui::text("  _ - _ - _ -  ")),
					color(ftxui::Color::SteelBlue, ftxui::text("   _ - _ - _   ")),
					color(ftxui::Color::SteelBlue, ftxui::text("  _ - _ - _ -  ")),
					color(ftxui::Color::SteelBlue, ftxui::text("               ")),

				});
  }

  ftxui::Element cloud() {
	return ftxui::vbox({
					color(ftxui::Color::White, ftxui::text("               ")),
					color(ftxui::Color::White, ftxui::text("      .--.    ")),
					color(ftxui::Color::White, ftxui::text("   .-(    ).   ")),
					color(ftxui::Color::White, ftxui::text("  (___.__)__) ")),
					color(ftxui::Color::White, ftxui::text("              ")),
				});
  }

  ftxui::Element sun_cloud() {
	return ftxui::vbox({
					color(ftxui::Color::Gold1, ftxui::text("    \\  /       ")),
					ftxui::hbox({color(ftxui::Color::Gold1, ftxui::text("  _ /\"\"")), color(ftxui::Color::White, ftxui::text(".-.    "))}),
					ftxui::hbox({color(ftxui::Color::Gold1, ftxui::text("    \\_")), color(ftxui::Color::White, ftxui::text("(   ).   "))}),
					ftxui::hbox({color(ftxui::Color::Gold1, ftxui::text("    /")), color(ftxui::Color::White, ftxui::text("(___(__)  "))}),
					ftxui::text("               "),

				});
  }

  ftxui::Element snow() {
	return ftxui::vbox({
					color(ftxui::Color::GrayLight, ftxui::text("      .--.    ")),
					color(ftxui::Color::GrayLight, ftxui::text("   .-(    ).   ")),
					color(ftxui::Color::GrayLight, ftxui::text("  (___.__)__) ")),
					color(ftxui::Color::White, ftxui::text("  *  *  *  *  ")),
					color(ftxui::Color::White, ftxui::text(" *  *  *  *   ")),

				});
  }

  ftxui::Element thunder() {
	return ftxui::vbox({
					color(ftxui::Color::White, ftxui::text("      .--.    ")),
					color(ftxui::Color::White, ftxui::text("   .-(    ).   ")),
					color(ftxui::Color::White, ftxui::text("  (__..__)__) ")),
					color(ftxui::Color::White, ftxui::text("  ‘  /  ‘  ‘   ")),
					color(ftxui::Color::White, ftxui::text(" ‘   \  ‘  ‘   ")),

				});
  }

  ftxui::Element rain() {
	return ftxui::vbox({
					color(ftxui::Color::GrayLight, ftxui::text("      .--.    ")),
					color(ftxui::Color::GrayLight, ftxui::text("   .-(    ).   ")),
					color(ftxui::Color::GrayLight, ftxui::text("  (___.__)__) ")),
					color(ftxui::Color::DeepSkyBlue2, ftxui::text("  ‘  ‘  ‘  ‘  ")),
					color(ftxui::Color::DeepSkyBlue2, ftxui::text(" ‘  ‘  ‘  ‘   ")),

				});
  }

  ftxui::Element What_weather(int time, int cur_day, int cur_city) {
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
	} else if (info[cur_city].weather_code[cur_day][time] == 3) {
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
	} else if (info[cur_city].weather_code[cur_day][time] == 3) {
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

  ftxui::Element BoxConstruct(const std::string &daytime, const std::string &weather, int time, int cur_day, int cur_city) {
	return ftxui::vbox({
						   ftxui::text(daytime) | ftxui::center,
						   ftxui::separator(),
						   ftxui::hbox({
							 What_weather(time, cur_day, cur_city),
							 ftxui::vbox({
											 ftxui::text(weather),
											 ftxui::text(info[cur_city].temperature[cur_day][time] + "C"),
											 ftxui::text(info[cur_city].windspeed[cur_day][time] + "km/h"),
											 ftxui::text(info[cur_city].precipitation_probability[cur_day][time] + "%"),
								  }),
						 }),
				});
  };

  ftxui::Element DayConstruct(int cur_city, int cur_day) {
	return ftxui::vbox({ftxui::text(info[cur_city].date[cur_day]) | ftxui::center, ftxui::hbox({
																	   BoxConstruct("Night",
																					What_weather_in_string(0,
																										   cur_day,
																										   cur_city),
																					0,
																					cur_day,
																					cur_city),
																	   ftxui::separator(),
																	   BoxConstruct("Morning",
																					What_weather_in_string(1,
																										   cur_day,
																										   cur_city),
																					1,
																					cur_day,
																					cur_city),
																	   ftxui::separator(),
																	   BoxConstruct("Day",
																					What_weather_in_string(2,
																										   cur_day,
																										   cur_city),
																					2,
																					cur_day,
																					cur_city),
																	   ftxui::separator(),
																	   BoxConstruct("Evening",
																					What_weather_in_string(3,
																										   cur_day,
																										   cur_city),
																					3,
																					cur_day,
																					cur_city),
																   }) | borderStyled(ftxui::ROUNDED)});
  };

  void print(int cur_city, int cur_day) {
	auto document = DayConstruct(cur_city, cur_day);
	auto screen =
		ftxui::Screen::Create(ftxui::Dimension::Fit(document), ftxui::Dimension::Fit(document));
	Render(screen, document);
	screen.Print();
  }
};

