/*


  Sketch generated by the Arduino IoT Cloud Thing "LED_STRIPS"

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  CloudColoredLight rgb_led;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include <EEPROM.h>
#include "thingProperties.h"

#include <FastLED.h>
#include <Arduino.h>

//include the Arduino library for your real sensor here, e.g. <DHT.h>


char R_pin = D2;
char B_pin = D3;
char G_pin = D4;
float H, S;
int B;
int bright;
float sat, hue;

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(115200);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
  */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  pinMode(R_pin, OUTPUT);
  pinMode(B_pin, OUTPUT);
  pinMode(G_pin, OUTPUT);
  analogWriteRange(255);
}

void loop() {
  ArduinoCloud.update();
  delay(150);


}

void onRgbLedChange() {

  if (rgb_led.getSwitch()) {
    analogWrite(R_pin, 255);
    analogWrite(B_pin, 255);
    analogWrite(G_pin, 255);
    H = rgb_led.getValue().hue;
    S = rgb_led.getValue().sat;
    B = rgb_led.getValue().bri;
    CHSV hsv(H * 255 / 360, S * 255 / 100, B);
    CRGB rgb;
    hsv2rgb_spectrum(hsv, rgb);
    analogWrite(R_pin, rgb.r);
    analogWrite(B_pin, rgb.b);
    analogWrite(G_pin, rgb.g);
  }
  else if (!rgb_led.getSwitch()) {
    analogWrite(R_pin, 0);
    analogWrite(B_pin, 0);
    analogWrite(G_pin, 0);
  }
}