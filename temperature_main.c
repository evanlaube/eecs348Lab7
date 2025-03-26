#include "temperature.h"
#include "stdio.h"
#include <ctype.h>

int main() {
    // float to store user input of unknown unit to begin
    float input;
    // single character to store unit of input
    char unit;
    // single character to store unit to convert to
    char convertTo;

    // Float to store temp in C
    float celsius;
    // Float to store temp in F
    float fahrenheit;
    // Float to store temp in K
    float kelvin = -1;

    // Repeat while the temp value is still undefined (kelvin < 0)
    do {
        // Prompt user to enter a unitless temperature
        printf("Enter temperature to convert (exclude unit suffix): ");
        // Take input and store in 'input'
        scanf("%f", &input);

        // Prompt user to enter unit of input temperature
        printf("Enter input unit as a single character ('f', 'c', or 'k'): ");
        // Take input char and store in unit
        scanf(" %c", &unit);

        // Ensure that the input unit is always a single lowercase character
        unit = tolower(unit);

        // If the unit is not within the expected input labels
        if(unit != 'c' && unit != 'f' && unit != 'k') {
            // Print an error to the user
            printf("ERROR: Invalid unit input, use 'f', 'c', or 'k' only\n");
            // Repeat the loop
            continue;
        }

        // If the unit is celsius
        if(unit == 'c') {
            // Set the celsius value to the input
            celsius = input;
        } else if (unit == 'f'){ // If the unit is fahrenheit
            // Convert to celsius and store
            celsius = fahrenheit_to_celsius(input);
        } else { // If the unit is Kelvin
            // Convert to celsius and store
            celsius = kelvin_to_celsius(input);
        }
        // Calculate the fahrenheit value for the temp
        fahrenheit = celsius_to_fahrenheit(celsius);
        // Calculate the kelvin value for the temp
        kelvin = celsius_to_kelvin(celsius);

        // If the temperature is below absolute zero (impossible)
        if(kelvin < 0) {
            // Print an error to the user
            printf("ERROR: Temperature cannot be less than aboslute zero\n");
            // Repeat the loop to try for a different input
            continue;
        }
    } while(kelvin < 0);

    // While the unit to convert to is not within the valid units
    do {
        // Prompt the user to input the unit to convert to
        printf("Enter unit to convert to in same format: ");
        // Take input and store in convertTo
        scanf(" %c", &convertTo);

        // Ensure that the unit to convert to is always a single lowercase character
        convertTo = tolower(convertTo);

        // If the character is not either 'c', 'f', or 'k'
        if(convertTo != 'c' && convertTo != 'f' && convertTo != 'k') {
            // Print an error to the user
            printf("ERROR: Invalid unit input, use 'f', 'c', or 'k' only\n");
            // Repeat loop
            continue;
        }

        // If the input unit is already the unit to convert to
        if(convertTo == unit) {
            // Print an error to the user
            printf("ERROR: Cannot convert to same unit\n");
            // Repeat the loop
            continue;
        }
    } while (convertTo != 'c' && convertTo != 'f' && convertTo != 'k'); 

    if(convertTo == 'c') { // If should convert to C
        // Print the celsius temp rounded to 2 decimals
        printf("Converted temperature: %.2f C\n", celsius);
    } else if(convertTo == 'f') { // if should convert to F 
        // Print the fahrenheit temp rounded to 2 decimals
        printf("Converted temperature: %.2f F\n", fahrenheit);
    } else { // if should convert to K 
        // Print the kelvin temp rounded to 2 decimals
        printf("Converted temperature: %.2f K\n", kelvin);
    }

    // Print the category of the temperature, as well as a weather advisory
    categorize_temperature(celsius);
}
