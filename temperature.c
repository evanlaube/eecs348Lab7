#include "temperature.h"
#include <stdio.h>

void categorize_temperature(float celsius) {
    printf("Categorizing temperature...\n");
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
