/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/digital/toneMelody/
*/
#include "pitches.h"

const int speakerPin = 8;
const int buttonPin = 2;
int buttonState = 0;

const int melody[] = {
  NOTE_E4, NOTE_E4, NOTE_E4, NOTE_C4, NOTE_E4, NOTE_G4, 0, NOTE_G3
};

const int noteDurations[] = {
  8, 4, 4, 8, 4, 4, 4, 4
};

const int totalNotes = 8;
const int bpm = 100;

void setup() {
  pinMode(speakerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    playMario();
    delay(500);
  }
}

void playMario() {
  for (int thisNote = 0; thisNote < totalNotes; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = (240000 / bpm) / noteDurations[thisNote];
    tone(speakerPin, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(speakerPin);
  }
}
