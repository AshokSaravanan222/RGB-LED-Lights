# RGB-LED-Lights

Author: Ashok Saravanan

Created 01-13-2022

Added homekit/alexa implementation to existing RGB-LED Lights (using Arduino). Most of the homekit end of things comes from Mixiaoxiao's project on this:

https://github.com/Mixiaoxiao/Arduino-HomeKit-ESP8266

It is very detailed and is what allowed me to make my own implementation.

# Implementation

![RGB-LED 1](https://user-images.githubusercontent.com/90977640/200136047-2f474c31-8ba9-4bf5-ab76-81abd9282f48.JPG)

I connected the R, G, and B channel of my lights to a seperate transistor, and controlled them using arduino. I had to use 12V to power the lights, so I used an external power source.

# HomeKit/iPhone

<img src="https://user-images.githubusercontent.com/90977640/200136040-99e8e981-6bdc-479e-a202-b31730ef0eff.PNG" width=40% height=50%>

The ESP-8266 board (along with help from Mixiaoxiao's library) allowed me to connect the device to my phone over wifi. Whenever I changed the color of the lights on my phone, my lights correspondingly updated in real time.

# Alexa

<img src="https://user-images.githubusercontent.com/90977640/200179920-92e5ffb1-6f20-424d-9e63-352ddf21911b.jpg" width=40% height=50%>

I used Arduino IOT cloud to set this up, with the color of my lights chaning with corresponding updates from Alexa.

# Coming Soon

I am currently working on a program that can utilize both alexa and homekit into one program.

# Thanks
[Mixiaoxiao](https://github.com/Mixiaoxiao/Arduino-HomeKit-ESP8266)
