#include <FastLED.h>

#define NUM_LEDS 8
#define DATA_PIN 11

CRGB leds[NUM_LEDS];

//Zeile mit Input Pins
byte rows[] = {2, 3, 4, 5};
const int rowCount = sizeof(rows) / sizeof(rows[0]); //rechnet die Länge der Liste aus

//Spalte mit Output Pins
byte cols[] = {8, 9, 10};
const int colCount = sizeof(cols) / sizeof(cols[0]); //rechnet die Länge der Liste aus

byte keys[colCount][rowCount]; //Liste der Tastenzustände

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  
  Serial.begin(9600);

  for (int x = 0; x < rowCount; x++) {
    pinMode(rows[x], INPUT);
  }

  for (int x = 0; x < colCount; x++) {
    pinMode(cols[x], INPUT_PULLUP);
  }
}

void readMatrix() {
  // Prüft die Spalten (col)
  for (int colIndex = 0; colIndex < colCount; colIndex++) {
    // col auf output low
    byte curCol = cols[colIndex];
    pinMode(curCol, OUTPUT);
    digitalWrite(curCol, LOW);

   // Prüft die Zeilen (row) der jeweiligen Spalte (col)
    for (int rowIndex = 0; rowIndex < rowCount; rowIndex++) {
      byte rowCol = rows[rowIndex];
      pinMode(rowCol, INPUT_PULLUP);
      keys[colIndex][rowIndex] = digitalRead(rowCol);
      pinMode(rowCol, INPUT);
    }
    // schaltet die Spalte wieder aus
    pinMode(curCol, INPUT);
  }
}

void printMatrix() {

  for (int rowIndex = 0; rowIndex < rowCount; rowIndex++) {

    Serial.print(F("R_"));
    Serial.print(rowIndex + 1); Serial.print(F(": ")); Serial.print("\t");

    for (int colIndex = 0; colIndex < colCount; colIndex++) {
      Serial.print(keys[colIndex][rowIndex]);
      if (colIndex < colCount)
        Serial.print("\t");
    }
    Serial.println("");
  }
  Serial.println("");
}

void ButtonToMatrix(){
  /*
    1a = keys[0][0]
    1b = keys[1][0]
    1c = keys[2][0]
    2a = keys[0][1]
    2b = keys[1][1]
    2c = keys[2][1]
    3a = keys[0][2]
    3b = keys[1][2]
    3c = keys[2][2]
    4a = keys[0][3]
    4b = keys[1][3]
    4c = keys[2][3]
  */

  /* right order:
    1a = keys[0][0]
    1b = keys[0][1]
    1c = keys[0][2]
    2a = keys[0][3]
    2b = keys[1][0]
    2c = keys[1][1]
    3a = keys[1][2]
    3b = keys[1][3]
    3c = keys[2][0]
    4a = keys[2][1]
    4b = keys[2][2]
    4c = keys[2][3]
  */

  
switch () {
  case 1a:
    Serial.println("1a")
    break;
  case 1b:
    Serial.println("1b")
    break;
  case 1c:
    Serial.println("1c")
    break;
  case 2a:
    Serial.println("2a")
    break;
  case 2b:
    Serial.println("2b")
    break;
  case 2c:
    Serial.println("2c")
    break;
  case 3a:
    Serial.println("3a")
    break;
  case 3b:
    Serial.println("3b")
    break;
  case 3c:
    Serial.println("3c")
    break;
  case 4a:
    Serial.println("4a")
    break;
  case 4b:
    Serial.println("4b")
    break;
  case 4c:
    Serial.println("4c")
    break;

    //denkbar auch als String?
  
  default:
    // Statement(s)
    break; // Wird nicht benötigt, wenn Statement(s) vorhanden sind
}
  

  
  }

void loop() {
  readMatrix();

  printMatrix();
  delay(1000);

}
