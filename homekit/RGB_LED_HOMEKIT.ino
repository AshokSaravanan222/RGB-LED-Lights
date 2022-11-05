
/*
 * RGB_LED_HOMEKIT.ino
 *
 * 1. The program will look for the HSB input values in homekit.
 * 2. These HSB values will be converted into RGB values and then sent to the corresponding pins.
 *
 *  Created on: 2020-05-15
 *      Author: Mixiaoxiao (Wang Bin)
 *
 *  Modified on: 01-13-2022
 *      Author: Ashok Saravanan
 */
#include <FastLED.h>
#include <Arduino.h>
#include <arduino_homekit_server.h>
#include "wifi_info.h"
//include the Arduino library for your real sensor here, e.g. <DHT.h>

#define LOG_D(fmt, ...)   printf_P(PSTR(fmt "\n") , ##__VA_ARGS__);


char R_pin = D2;
char B_pin = D3;
char G_pin = D4;
int bright;
float sat, hue;


void setup() {
	Serial.begin(115200);
  pinMode(R_pin, OUTPUT);
  pinMode(B_pin, OUTPUT);
  pinMode(G_pin, OUTPUT);
  analogWriteRange(255);
	wifi_connect(); // in wifi_info.h
	my_homekit_setup();
}

void loop() {
	my_homekit_loop();
	delay(10);
}

//==============================
// Homekit setup and loop
//==============================

// access your homekit characteristics defined in my_accessory.c
extern "C" homekit_server_config_t config;
extern "C" homekit_characteristic_t cha_on;
extern "C" homekit_characteristic_t cha_bright;
extern "C" homekit_characteristic_t cha_sat;
extern "C" homekit_characteristic_t cha_hue;



void my_homekit_setup() {
	arduino_homekit_setup(&config);
}

void my_homekit_loop() {
	arduino_homekit_loop();
  delay(10);
	my_homekit_report();
	}


void my_homekit_report() {
	bright = cha_bright.value.int_value;
  sat = cha_sat.value.float_value;
  hue = cha_hue.value.float_value;
  CHSV hsv(hue*255/360, sat*255/100, bright);
  CRGB rgb;
  hsv2rgb_spectrum(hsv, rgb);
  if ((cha_on.value.bool_value) == true){
    analogWrite(R_pin, rgb.r);
    analogWrite(B_pin, rgb.b);
    analogWrite(G_pin, rgb.g);
  }

  else {
    analogWrite(R_pin, 0);
    analogWrite(B_pin, 0);
    analogWrite(G_pin, 0);
  }
  
}
