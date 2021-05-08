#include "Keyboard.h"

#define DEBOUNCE_TIME 50
#define NUM_KEYS 8

int pins[] = { 10, 16, 14, 15, 18, 19, 20, 21 };

bool states[] = { LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW };
bool lastState[] = { LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW };
int lastChange[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

int now = 0;

boolean readSwitch(int i) {
  bool val = digitalRead(pins[i]);

  //Note the time a switch value has changed.
  if (val != lastState[i]) {
    lastChange[i] = now;
    lastState[i] = val;
  }

  //If different from current state, check debounce time before setting new state and sending macro
  if (val != states[i]) {
    if (lastChange[i] < (now - DEBOUNCE_TIME)) {
      states[i] = val;
      if (val == LOW) {
        switch(i) {
          case 0:
            Keyboard.print("Ba");
            break;
          case 1:
            Keyboard.print("na");
            break;
          case 2:
            Keyboard.print("na");
            break;
          case 3:
            Keyboard.print("na");
            break;
          case 4:
            Keyboard.print("na");
            break;
          case 5:
            Keyboard.print("na");
            break;
          case 6:
            Keyboard.print("na");
            break;
          case 7:
            Keyboard.print("na!");
            break;
          default:
            break;
        }
        
      } else {
        // On key up
      }
    }    
  }

  //Clock Rollover - millis rolls over every 49 days or so
  if (lastChange[i] > now) {
    lastChange[i] = 0;
  }

  //Return pin val
  return states[i];
}


void setup() {
  for (int i = 0; i < NUM_KEYS; i++) {
    pinMode(pins[i], INPUT_PULLUP);
  }
  Keyboard.begin();
}

void loop() {
  now = millis();
  
  for (int i = 0; i < NUM_KEYS; i++) {
    readSwitch(i);
  }

}
