// Basic BPM (Beats Per Minute) Calculator for ESP32
#include <Arduino.h>
#include "display.h"


const int buttonPin = 0;

unsigned long clickTimes[4];
int clickCount = 0;
bool previousState = HIGH;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(115200);
  Display::display_init();
}

void loop() {
  bool currentState = digitalRead(buttonPin);

  // Detect button press (falling edge)
  if (previousState == HIGH && currentState == LOW) {
    if (clickCount < 4) {
      clickTimes[clickCount] = millis();
      clickCount++;
    }

    if (clickCount == 4) {
      unsigned long interval = clickTimes[3] - clickTimes[0]; // ms between 1st and 4th clicks
      float seconds = interval / 1000.0;
      float beats = 3.0;  // 4 clicks → 3 intervals
      float bpm = (beats / seconds) * 60.0;

      Serial.print("BPM: ");
      Serial.println(bpm);
      Display::display_show_bpm(bpm);


      clickCount = 0; // reset for next measurement
    }
  }

  previousState = currentState;
} 
