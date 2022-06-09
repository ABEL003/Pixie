#include <FastLED.h>

#define NUM_LEDS 12
#define DATA_PIN 11

CRGB leds[NUM_LEDS];

//timer 5s ledStart
unsigned long startTime;
boolean timing;
unsigned long timeOut = 5000;

//Zeile mit Input Pins
byte rows[] = {2, 3, 4, 5};
const int rowCount = sizeof(rows) / sizeof(rows[0]); //rechnet die Länge der Liste aus

//Spalte mit Output Pins
byte cols[] = {8, 9, 10};
const int colCount = sizeof(cols) / sizeof(cols[0]); //rechnet die Länge der Liste aus

byte keys[colCount][rowCount]; //Liste der Tastenzustände

int ledStartState = 1;
int ledChangeState = 1;
int ledChangeStateZero = 0;


void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(84);

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


void ledStart() {
  //drei Hauptbuttons
  int simonsaysStart = keys[0][3];
  int tiktactoeStart = keys[1][3];
  int sendButton = keys[2][3];

  if (simonsaysStart == 0)
  {
    ledStartState = ledChangeState;
    Serial.println("ledStart");
    Serial.print("ledStartState zuerst: ");
    Serial.println(ledStartState);
    //Serial.println("ledStart");
    //for(int i=0; i<=8; i++) {
    leds[2] = CRGB::Purple;
    delay(50);
    FastLED.show();
    leds[1] = CRGB::Blue;
    delay(50);
    leds[3] = CRGB::Blue;
    delay(50);
    FastLED.show();
    leds[0] = CRGB::Green;
    delay(50);
    leds[4] = CRGB::Green;
    delay(50);
    leds[8] = CRGB::Green;
    delay(50);
    FastLED.show();
    leds[5] = CRGB::Orange;
    delay(50);
    leds[7] = CRGB::Orange;
    delay(50);
    FastLED.show();
    leds[6] = CRGB::Red;
    delay(50);
    FastLED.show();

    leds[2] = CRGB::Black;
    delay(50);
    FastLED.show();
    leds[1] = CRGB::Black;
    delay(50);
    leds[3] = CRGB::Black;
    delay(50);
    FastLED.show();
    leds[0] = CRGB::Black;
    delay(50);
    leds[4] = CRGB::Black;
    delay(50);
    leds[8] = CRGB::Black;
    delay(50);
    FastLED.show();
    leds[5] = CRGB::Black;
    delay(50);
    leds[7] = CRGB::Black;
    delay(50);
    FastLED.show();
    leds[6] = CRGB::Black;
    delay(50);
    FastLED.show();

    leds[6] = CRGB::Purple;
    delay(50);
    FastLED.show();
    leds[7] = CRGB::Blue;
    delay(50);
    leds[5] = CRGB::Blue;
    delay(50);
    FastLED.show();
    leds[0] = CRGB::Green;
    delay(50);
    leds[4] = CRGB::Green;
    delay(50);
    leds[8] = CRGB::Green;
    delay(50);
    FastLED.show();
    leds[3] = CRGB::Orange;
    delay(50);
    leds[1] = CRGB::Orange;
    delay(50);
    FastLED.show();
    leds[2] = CRGB::Red;
    delay(50);
    FastLED.show();

    leds[6] = CRGB::Black;
    delay(50);
    FastLED.show();
    leds[7] = CRGB::Black;
    delay(50);
    leds[5] = CRGB::Black;
    delay(50);
    FastLED.show();
    leds[0] = CRGB::Black;
    delay(50);
    leds[4] = CRGB::Black;
    delay(50);
    leds[8] = CRGB::Black;
    delay(50);
    FastLED.show();
    leds[3] = CRGB::Black;
    delay(50);
    leds[1] = CRGB::Black;
    delay(50);
    FastLED.show();
    leds[2] = CRGB::Black;
    delay(50);
    FastLED.show();
    //}

    startTime = millis();
    timing = true;

    ledStartState = ledChangeStateZero;
    Serial.print("ledStartState danach: ");
    Serial.println(ledStartState);
  }

  if (timing == true) {
    if (millis() - startTime >= timeOut && simonsaysStart == 1) {
      for (int i = 0; i <= 8; i++) {
        leds[i] = CRGB::Black;
        FastLED.show();
      }
      timing = false;
    }
  }
}


void inputButtonSequence() {
  if (ledStartState == 0) {
    for (int i = 0; i <= 8; i++) {
      leds[i] = CRGB::Blue;
      FastLED.show();
    }
    delay(1000);
    ledStartState == 1;

    //if (key 0 0
    //blau
    //1a  == TRUE //void, die schaut, ob 1a true ist.
  }
  else {
    if (ledStartState == 1) {
      for (int i = 0; i <= 8; i++) {
        leds[i] = CRGB::Black;
        FastLED.show();
      }
    }
  }
}


//void 1, die schaut ob 1a true ist und kombiniert mit 1b und sendet an server/js.

//void 2, die gesendeten code aufrbicht und auswertet und in reihenfolge anzeigt.

//void/if 3, der sagt, ob kombi richtig oder falsch eingegeben wurde.


void loop() {
  readMatrix();

  printMatrix();

  ledStart();

  inputButtonSequence();
}
