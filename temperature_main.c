#include "temperature.h"
#include "stdio.h"
#include <ctype.h>

int main() {

    int input;
    char unit;
    char convertTo;


    printf("Enter temperature to convert (exclude unit suffix): ");
    scanf("%d", &input);

    printf("Enter input unit as a single character ('f', 'c', or 'k'): ");
    scanf(" %c", &unit);

    // Ensure that the input unit is always a single lowercase character
    unit = tolower(unit);

    if(unit != 'c' && unit != 'f' && unit != 'k') {
        printf("ERROR: Invalid unit input, use 'f', 'c', or 'k' only\n");
        return 1;
    }

    int celsius;
    int fahrenheit;
    int kelvin;

    if(unit == 'c') {
        celsius = input;
    } else if (unit == 'f'){
        celsius = fahrenheit_to_celsius(input);
    } else {
        celsius = kelvin_to_celsius(input);
    }
    fahrenheit = celsius_to_fahrenheit(celsius);
    kelvin = celsius_to_kelvin(celsius);

    printf("Enter unit to convert to in same format: ");
    scanf(" %c", &convertTo);

    // Ensure that the unit to convert to is always a single lowercase character
    convertTo = tolower(convertTo);

    if(convertTo != 'c' && convertTo != 'f' && convertTo != 'k') {
        printf("ERROR: Invalid unit input, use 'f', 'c', or 'k' only\n");
        return 1;
    }

    if(convertTo == unit) {
        printf("ERROR: Cannot convert to same unit\n");
        return 1;
    }

    if(convertTo == 'c') {
        printf("Converted temperature: %d C\n", celsius);
    } else if(convertTo == 'f') {
        printf("Converted temperature: %d F\n", fahrenheit);
    } else {
        printf("Converted temperature: %d K\n", kelvin);
    }

    categorize_temperature(celsius);

}
