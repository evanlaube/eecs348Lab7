#include "temperature.h"
#include <stdio.h>

void categorize_temperature(float celsius) {
    // If the temp is below 0C
    if(celsius < 0) {
        // Print current condition category and weather advisory
        printf("Current condition: Freezing\n");
        printf("Advisory: Put on a heavy coat, hat, and gloves. Limit time outside\n");
    } else if (celsius < 10) { // If temp between 0-10 C
        // Print current condition category and weather advisory
        printf("Current condition: Cold\n");
        printf("Advisory: A heavy jacket should be fine\n");
    } else if (celsius < 25) { // If temp between 10-25 C
        // Print current condition category and weather advisory
        printf("Current condition: Comfortable\n");
        printf("Advisory: Wear comfortable light clothes. Enjoy the nice weather!\n");
    } else if (celsius < 35) { // If temp between 25-35 C
        // Print current condition category and weather advisory
        printf("Current condition: Hot\n");
        printf("Advisory: Wear light clothes and be aware of overheating.\n");
    } else { // If temp is 35+
        // Print current condition category and weather advisory
        printf("Current condition: Extreme heat\n");
        printf("Advisory: It's too hot to be outside safely. Stay indoors.\n");
    }
}

float celsius_to_fahrenheit(float celsius) {
    // Calculate fahrenheit temp and return it
    return (9.0/5.0) * celsius + 32.0;
}

float fahrenheit_to_celsius(float fahrenheit) {
    // Calculate celsius temp and return it
    return (5.0/9.0) * (fahrenheit - 32.0);
}

float celsius_to_kelvin(float celsius) {
    // Calculate kelvin temp and return it
    return celsius + 273.15;
}

float kelvin_to_celsius(float celsius) {
    // Calculate celsius temp and return it
    return celsius - 273.15;
}
