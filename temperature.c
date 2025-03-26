#include "temperature.h"
#include <stdio.h>

void categorize_temperature(float celsius) {
    if(celsius < 0) {
        printf("Current condition: Freezing\n");
        printf("Advisory: Put on a heavy coat, hat, and gloves. Limit time outside\n");
    } else if (celsius < 10) {
        printf("Current condition: Cold\n");
        printf("Advisory: A heavy jacket should be fine\n");
    } else if (celsius < 25) {
        printf("Current condition: Comfortable\n");
        printf("Advisory: Wear comfortable light clothes. Enjoy the nice weather!\n");
    } else if (celsius < 35) {
        printf("Current condition: Hot\n");
        printf("Advisory: Wear light clothes and be aware of overheating.\n");
    } else {
        printf("Current condition: Extreme heat\n");
        printf("Advisory: It's too hot to be outside safely. Stay indoors.\n");
    }
}

float celsius_to_fahrenheit(float celsius) {
    return (9.0/5.0) * celsius + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (5.0/9.0) * fahrenheit - 32;
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float celsius) {
    return celsius - 273.15;
}
