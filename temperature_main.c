#include "temperature.h"
#include "stdio.h"
#include <ctype.h>

int main() {

    float input;
    char unit;
    char convertTo;

    float celsius;
    float fahrenheit;
    float kelvin = -1;

    do {
        printf("Enter temperature to convert (exclude unit suffix): ");
        scanf("%f", &input);

        printf("Enter input unit as a single character ('f', 'c', or 'k'): ");
        scanf(" %c", &unit);

        // Ensure that the input unit is always a single lowercase character
        unit = tolower(unit);

        if(unit != 'c' && unit != 'f' && unit != 'k') {
            printf("ERROR: Invalid unit input, use 'f', 'c', or 'k' only\n");
            continue;
        }

        if(unit == 'c') {
            celsius = input;
        } else if (unit == 'f'){
            celsius = fahrenheit_to_celsius(input);
        } else {
            celsius = kelvin_to_celsius(input);
        }
        fahrenheit = celsius_to_fahrenheit(celsius);
        kelvin = celsius_to_kelvin(celsius);

        if(kelvin < 0) {
            printf("ERROR: Temperature cannot be less than aboslute zero\n");
            continue;
        }
    } while(kelvin < 0);

    do {
        printf("Enter unit to convert to in same format: ");
        scanf(" %c", &convertTo);

        // Ensure that the unit to convert to is always a single lowercase character
        convertTo = tolower(convertTo);

        if(convertTo != 'c' && convertTo != 'f' && convertTo != 'k') {
            printf("ERROR: Invalid unit input, use 'f', 'c', or 'k' only\n");
            continue;
        }

        if(convertTo == unit) {
            printf("ERROR: Cannot convert to same unit\n");
            continue;
        }
    } while (convertTo != 'c' && convertTo != 'f' && convertTo != 'k'); 

    if(convertTo == 'c') {
        printf("Converted temperature: %f C\n", celsius);
    } else if(convertTo == 'f') {
        printf("Converted temperature: %f F\n", fahrenheit);
    } else {
        printf("Converted temperature: %f K\n", kelvin);
    }

    categorize_temperature(celsius);

}
