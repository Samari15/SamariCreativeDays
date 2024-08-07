/*
 * 30 Days - Lost in Space
 * Day 9 - A Better Way to Do Things
 *
 * Learn more at https://learn.inventr.io/adventure
 *
 * Now that we know how to measure our battery charging rate and we know how to display
 * multiple colors with the RGB LED, let's combine those two concepts to display different
 * colors as our battery charges to give a good indication of our current battery state.
 *
 * Alex Eschenauer
 * David Schmidt
 * Greg Lyzenga
 */

/*
 * Arduino concepts introduced/documented in this lesson.
 * - float:   Variable type for decimal numbers that include a decimal point
 * - else if: Control structure for making multiple if decisions together
 *
 * Parts and electronics concepts introduced in this lesson.
 */

// Explicitly include Arduino.h
#include "Arduino.h"

// Our photoresistor will give us a reading of the current light level on this analog pin
const byte PHOTORESISTOR_PIN = A0;  // Photoresistor analog pin

// RGB LED pins
const byte RED_PIN = 11;    // pin controlling the red leg of our RGB LED
const byte GREEN_PIN = 10;  // pin ccontrolling the green leg of our RGB LED
const byte BLUE_PIN = 9;    // pin ccontrolling the blue leg of our RGB LED
const int LIGHT = 300;

/*
 * Display a color on our RGB LED by providing an intensity for
 * our red, green and blue LEDs.
 */
void displayColor(
  byte red_intensity,    // red LED intensity (0-255)
  byte green_intensity,  // green LED intensity (0-255)
  byte blue_intensity    // blue LED intensity (0-255)
) {
  analogWrite(RED_PIN, red_intensity);      // write red LED intensity using PWM
  analogWrite(GREEN_PIN, green_intensity);  // write green LED intensity using PWM
  analogWrite(BLUE_PIN, blue_intensity);    // write blue LED intensity using PWM
}

void setup() {
  // Declare the RGB LED pins as outputs:
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  // Start serial monitor
  Serial.begin(9600);
}

void loop() {
  int lightlevel =analogRead(PHOTORESISTOR_PIN);
  Serial.println(lightlevel);

if (lightlevel > 500) {
displayColor(255, 255, 255);
}
else {

displayColor(0, 0, 0);
}
  // Use static because we need this variable to maintain it's value across
  // multiple loop() runs.
}