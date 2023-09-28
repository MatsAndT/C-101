//
// Created by Mats on 28.09.2023.
//

#include <stdio.h>

double toCelcius(double temp_fahrenheit) {
    return (temp_fahrenheit - 32) * 5 / 9;
}

int main(void) {
    double temp_fahrenheit = 27;
    printf("Temperature in Fahrenheit: %f\n", temp_fahrenheit);
    printf("Temperature in Celsius: %f\n", toCelcius(temp_fahrenheit));

    return 0;
}