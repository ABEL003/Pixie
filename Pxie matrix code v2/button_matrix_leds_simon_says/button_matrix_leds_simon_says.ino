//LED
#include <FastLED.h>

#define NUM_LEDS 12
#define DATA_PIN 11

CRGB leds[NUM_LEDS];

//Simon says
const int MAX_LEVEL = 100;
int sequence[MAX_LEVEL];
int your_sequence[MAX_LEVEL];
int level = 1;

int velocity = 5000;

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

/*void lightLeds() {
  //First button lights first LED
  if (keys[0][0] == 0) {
    // Turn the LED on
    leds[0] = CRGB::Red;                    //LED wird rot geschalten
    FastLED.show();                         //wird angezeigt
    delay(0);                               //warten
  }
  else if (keys[0][0] == 1) {
    // Turn the LED off
    leds[0] = CRGB::Black;
    FastLED.show();
    delay(0);
  }

  //Second button lights sixth LED
  if (keys[0][1] == 0) {
    leds[5] = CRGB::Red;
    FastLED.show();
    delay(0);
  }
  else if (keys[0][1] == 1) {
    leds[5] = CRGB::Black;
    FastLED.show();
    delay(0);
  }

  //Third button lights seventh LED
  if (keys[0][2] == 0) {
    leds[6] = CRGB::Red;
    FastLED.show();
    delay(0);
  }
  else if (keys[0][2] == 1) {
    leds[6] = CRGB::Black;
    FastLED.show();
    delay(0);
  }

  //Fourth button lights twelveth LED
  if (keys[0][3] == 0) {                        //Simon Says start button
    leds[11] = CRGB::Red;
    FastLED.show();
    delay(0);
  }
  else if (keys[0][3] == 1) {
    leds[11] = CRGB::Black;
    FastLED.show();
    delay(0);
  }

  //Fifth button lights second LED
  if (keys[1][0] == 0) {
    leds[1] = CRGB::Red;
    FastLED.show();
    delay(0);
  }
  else if (keys[1][0] == 1) {
    leds[1] = CRGB::Black;
    FastLED.show();
    delay(0);
  }

  //Sixth button lights fifeth LED
  if (keys[1][1] == 0) {
    leds[4] = CRGB::Red;
    FastLED.show();
    delay(0);
  }
  else if (keys[1][1] == 1) {
    leds[4] = CRGB::Black;
    FastLED.show();
    delay(0);
  }

  //Seventh button lights eighth LED
  if (keys[1][2] == 0) {
    leds[7] = CRGB::Red;
    FastLED.show();
    delay(0);
  }
  else if (keys[1][2] == 1) {
    leds[7] = CRGB::Black;
    FastLED.show();
    delay(0);
  }

  //Eighth button lights twelveth LED
  if (keys[1][3] == 0) {                        //Tik-Tac-Toe start button
    leds[10] = CRGB::Red;
    FastLED.show();
    delay(0);
  }
  else if (keys[1][3] == 1) {
    leds[10] = CRGB::Black;
    FastLED.show();
    delay(0);
  }

  //Nineth button lights third LED
  if (keys[2][0] == 0) {
    leds[2] = CRGB::Red;
    FastLED.show();
    delay(0);
  }
  else if (keys[2][0] == 1) {
    leds[2] = CRGB::Black;
    FastLED.show();
    delay(0);
  }

  //Tenth button lights fourth LED
  if (keys[2][1] == 0) {
    leds[3] = CRGB::Red;
    FastLED.show();
    delay(0);
  }
  else if (keys[2][1] == 1) {
    leds[3] = CRGB::Black;
    FastLED.show();
    delay(0);
  }

  //Eleventh button lights nineth LED
  if (keys[2][2] == 0) {
    leds[8] = CRGB::Red;
    FastLED.show();
    delay(0);
  }
  else if (keys[2][2] == 1) {
    leds[8] = CRGB::Black;
    FastLED.show();
    delay(0);
  }

  //Twelveth button lights tenth LED
  if (keys[2][3] == 0) {                        //send button
    leds[9] = CRGB::Red;
    FastLED.show();
    delay(0);
  }
  else if (keys[2][3] == 1) {
    leds[9] = CRGB::Black;
    FastLED.show();
    delay(0);
  }
}*/

void loop() {
  readMatrix();

  printMatrix();

  //lightLeds();

  if (level == 1) generate_sequence();//generate a sequence;

  if (keys[0][3] == 0 || level != 1) { //If start button is pressed or you're winning
    Serial.println("AXDFASDL");

    show_sequence();    //show the sequence
    get_sequence();     //wait for your sequence
  }
}

void show_sequence() {
  leds[0] = CRGB::Black;


  leds[1] = CRGB::Black;


  leds[2] = CRGB::Black;


  leds[5] = CRGB::Black;


  leds[6] = CRGB::Black;


  leds[7] = CRGB::Black;


  leds[8] = CRGB::Black;


  leds[9] = CRGB::Black;


  leds[10] = CRGB::Black;
  FastLED.show();

  /*keys[0][0] == 1;
    keys[0][1] == 1;
    keys[0][2] == 1;
    keys[1][0] == 1;
    keys[1][1] == 1;
    keys[1][2] == 1;
    keys[2][0] == 1;
    keys[2][1] == 1;
    keys[2][2] == 1;*/


  /*keys[0][0] == 1;
    keys[0][1] == 1;
    keys[0][2] == 1;
    keys[0][3] == 1;
    keys[1][0] == 1;
    keys[1][1] == 1;
    keys[1][2] == 1;
    keys[1][3] == 1;
    keys[2][0] == 1;
    keys[2][1] == 1;
    keys[2][2] == 1;
    keys[2][3] == 1;*/

  for (int i = 0; i < level; i++) {
    leds[sequence[i]] = CRGB::RoyalBlue;
    FastLED.show();
    delay(velocity);

    leds[sequence[i]] = CRGB::Black;
    FastLED.show();
    delay(200);

  }
}

void get_sequence() {
  int flag = 0; //this flag indicates if the sequence is correct

  for (int i = 0; i < level; i++) {
    flag = 0;
    while (flag == 0) {
      if (keys[0][0] == 1) {
        leds[8] = CRGB::RoyalBlue;
        FastLED.show();
        your_sequence[i] = 10;
        flag = 1;
        delay(200);

        if (your_sequence[i] != sequence[i]) {
          wrong_sequence();
          return;
        }

        leds[8] = CRGB::Black;
        FastLED.show();
      }

      if (keys[0][1] == 1) {
        leds[9] = CRGB::RoyalBlue;
        FastLED.show();
        your_sequence[i] = 9;
        flag = 1;
        delay(200);

        if (your_sequence[i] != sequence[i]) {
          wrong_sequence();
          return;
        }

        leds[9] = CRGB::Black;
        FastLED.show();
      }

      if (keys[0][2] == 1) {
        leds[10] = CRGB::RoyalBlue;
        FastLED.show();
        your_sequence[i] = 8;
        flag = 1;
        delay(200);

        if (your_sequence[i] != sequence[i]) {
          wrong_sequence();
          return;
        }

        leds[10] = CRGB::Black;
        FastLED.show();
      }

      if (keys[1][0] == 1) {
        leds[7] = CRGB::RoyalBlue;
        FastLED.show();
        your_sequence[i] = 7;
        flag = 1;
        delay(200);

        if (your_sequence[i] != sequence[i]) {
          wrong_sequence();
          return;
        }

        leds[7] = CRGB::Black;
        FastLED.show();
      }

      if (keys[1][1] == 1) {
        leds[7] = CRGB::RoyalBlue;
        FastLED.show();
        your_sequence[i] = 6;
        flag = 1;
        delay(200);

        if (your_sequence[i] != sequence[i]) {
          wrong_sequence();
          return;
        }

        leds[7] = CRGB::Black;
        FastLED.show();
      }

      if (keys[1][2] == 1) {
        leds[6] = CRGB::RoyalBlue;
        FastLED.show();
        your_sequence[i] = 5;
        flag = 1;
        delay(200);

        if (your_sequence[i] != sequence[i]) {
          wrong_sequence();
          return;
        }

        leds[6] = CRGB::Black;
        FastLED.show();
      }

      if (keys[2][0] == 1) {
        leds[0] = CRGB::RoyalBlue;
        FastLED.show();
        your_sequence[i] = 4;
        flag = 1;
        delay(200);

        if (your_sequence[i] != sequence[i]) {
          wrong_sequence();
          return;
        }

        leds[0] = CRGB::Black;
        FastLED.show();
      }

      if (keys[2][1] == 1) {
        leds[1] = CRGB::RoyalBlue;
        FastLED.show();
        your_sequence[i] = 3;
        flag = 1;
        delay(200);

        if (your_sequence[i] != sequence[i]) {
          wrong_sequence();
          return;
        }

        leds[1] = CRGB::Black;
        FastLED.show();
      }

      if (keys[2][2] == 1) {
        leds[2] = CRGB::RoyalBlue;
        FastLED.show();
        your_sequence[i] = 2;
        flag = 1;
        delay(200);

        if (your_sequence[i] != sequence[i]) {
          wrong_sequence();
          return;
        }

        leds[2] = CRGB::Black;
        FastLED.show();
      }
    }
    right_sequence();
  }
}
void generate_sequence() {
  //  randomSeed(millis()); //in this way is really random!!!

  for (int i = 0; i < MAX_LEVEL; i++) {
    sequence[i] = random(2, 6);
  }
}

void wrong_sequence() {
  for (int i = 0; i < 3; i++) {
    leds[0] = CRGB::Red;
    FastLED.show();

    leds[1] = CRGB::Red;
    FastLED.show();

    leds[2] = CRGB::Red;
    FastLED.show();

    leds[5] = CRGB::Red;
    FastLED.show();

    leds[6] = CRGB::Red;
    FastLED.show();

    leds[7] = CRGB::Red;
    FastLED.show();

    leds[8] = CRGB::Red;
    FastLED.show();

    leds[9] = CRGB::Red;
    FastLED.show();

    leds[10] = CRGB::Red;
    FastLED.show();

    delay(250);

    leds[0] = CRGB::Black;
    FastLED.show();

    leds[1] = CRGB::Black;
    FastLED.show();

    leds[2] = CRGB::Black;
    FastLED.show();

    leds[5] = CRGB::Black;
    FastLED.show();

    leds[6] = CRGB::Black;
    FastLED.show();

    leds[7] = CRGB::Black;
    FastLED.show();

    leds[8] = CRGB::Black;
    FastLED.show();

    leds[9] = CRGB::Black;
    FastLED.show();

    leds[10] = CRGB::Black;
    FastLED.show();

    delay(250);
  }
  level = 1;
  velocity = 1000;
}

void right_sequence() {


  leds[0] = CRGB::Black;
  FastLED.show();

  leds[1] = CRGB::Black;
  FastLED.show();

  leds[2] = CRGB::Black;
  FastLED.show();

  leds[5] = CRGB::Black;
  FastLED.show();

  leds[6] = CRGB::Black;
  FastLED.show();

  leds[7] = CRGB::Black;
  FastLED.show();

  leds[8] = CRGB::Black;
  FastLED.show();

  leds[9] = CRGB::Black;
  FastLED.show();

  leds[10] = CRGB::Black;
  FastLED.show();

  delay(250);

  leds[0] = CRGB::Green;
  FastLED.show();

  leds[1] = CRGB::Green;
  FastLED.show();

  leds[2] = CRGB::Green;
  FastLED.show();

  leds[5] = CRGB::Green;
  FastLED.show();

  leds[6] = CRGB::Green;
  FastLED.show();

  leds[7] = CRGB::Green;
  FastLED.show();

  leds[8] = CRGB::Green;
  FastLED.show();

  leds[9] = CRGB::Green;
  FastLED.show();

  leds[10] = CRGB::Green;
  FastLED.show();

  delay(500);

  leds[0] = CRGB::Black;
  FastLED.show();

  leds[1] = CRGB::Black;
  FastLED.show();

  leds[2] = CRGB::Black;
  FastLED.show();

  leds[5] = CRGB::Black;
  FastLED.show();

  leds[6] = CRGB::Black;
  FastLED.show();

  leds[7] = CRGB::Black;
  FastLED.show();

  leds[8] = CRGB::Black;
  FastLED.show();

  leds[9] = CRGB::Black;
  FastLED.show();

  leds[10] = CRGB::Black;
  FastLED.show();

  delay(500);

  if (level < MAX_LEVEL);
  level++;

  velocity -= 50; //increase difficulty
}
