/*
 * my_accessory.c
 * Define the accessory in C language using the Macro in characteristics.h
 *
 *  Created on: 2020-05-15
 *      Author: Mixiaoxiao (Wang Bin)
 */

#include <homekit/homekit.h>
#include <homekit/characteristics.h>

// Called to identify this accessory. See HAP section 6.7.6 Identify Routine
// Generally this is called when paired successfully or click the "Identify Accessory" button in Home APP.
void my_accessory_identify(homekit_value_t _value) {
	printf("accessory identify\n");
}

// For TEMPERATURE_SENSOR,
// the required characteristics are: CURRENT_TEMPERATURE
// the optional characteristics are: NAME, STATUS_ACTIVE, STATUS_FAULT, STATUS_TAMPERED, STATUS_LOW_BATTERY
// See HAP section 8.41 and characteristics.h

// (required) format: float; HAP section 9.35; min 0, max 100, step 0.1, unit celsius
homekit_characteristic_t cha_on = HOMEKIT_CHARACTERISTIC_(ON, true);

// (optional) format: string; HAP section 9.62; max length 64
homekit_characteristic_t cha_name = HOMEKIT_CHARACTERISTIC_(NAME, "RGB LED Strips");
homekit_characteristic_t cha_bright = HOMEKIT_CHARACTERISTIC_(BRIGHTNESS, 100);
homekit_characteristic_t cha_sat = HOMEKIT_CHARACTERISTIC_(SATURATION, (float) 0);
homekit_characteristic_t cha_hue = HOMEKIT_CHARACTERISTIC_(HUE, (float) 180);



homekit_accessory_t *accessories[] = {
    HOMEKIT_ACCESSORY(.id=1, .category=homekit_accessory_category_lightbulb, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "RGB LED Strips"),
            HOMEKIT_CHARACTERISTIC(MANUFACTURER, "Arduino HomeKit"),
            HOMEKIT_CHARACTERISTIC(SERIAL_NUMBER, "0123456"),
            HOMEKIT_CHARACTERISTIC(MODEL, "ESP8266/ESP32"),
            HOMEKIT_CHARACTERISTIC(FIRMWARE_REVISION, "1.0"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, my_accessory_identify),
            NULL
        }),
        HOMEKIT_SERVICE(LIGHTBULB, .primary=true, .characteristics=(homekit_characteristic_t*[]) {
            &cha_name,
            &cha_on,
            &cha_bright,
            &cha_sat,
            &cha_hue,//optional
			//&cha_status_active,//optional
			//&cha_status_fault,//optional
			//&cha_status_tampered,//optional
			//&cha_status_low_battery,//optional
            NULL
        }),
		// Add this HOMEKIT_SERVICE if you has a HUMIDITY_SENSOR together
		/*
        HOMEKIT_SERVICE(HUMIDITY_SENSOR, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Humidity Sensor"),
            &cha_humidity,
            NULL
        }),*/
        NULL
    }),
    NULL
};

homekit_server_config_t config = {
		.accessories = accessories,
		.password = "111-11-111"
};
