#include <FastLED.h>

#define NUM_LEDS 12
#define DATA_PIN 11

CRGB leds[NUM_LEDS];

String inputArray[20];
int arrayCounter = 0;

//timer 5s
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

//Buttons in der gedrückten Reihenfolge
String inputString = "";
//wv Knöpfe gedrückt wurden
int x = 0;
int xSendingLength = 0;
int xInputLength = 0;
//wv Knöpfe gedrückt werden dürfen
int y = x + 1;

String userString = "";
String sendingString = "";

//Rundenzähler
int level = 0;

//Button drücken und einmal printen statt multiple times
int key1state;
int key1previousState = 0;

int key2state;
int key2previousState = 0;

int key3state;
int key3previousState = 0;

int key4state;
int key4previousState = 0;

int key5state;
int key5previousState = 0;

int key6state;
int key6previousState = 0;

int key7state;
int key7previousState = 0;

int key8state;
int key8previousState = 0;

int key9state;
int key9previousState = 0;

//State for wrong sequence
int wrongSequence = 0;

//
String checkString = "";
char stringComplete = "";


void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(10);

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


void ledStart() {
  //drei Hauptbuttons
  int simonsaysStart = keys[0][3];
  int receiveButton = keys[1][3];
  int sendButton = keys[2][3];

  if (simonsaysStart == 0 || wrongSequence == 1) {
    ledStartState = ledChangeState;
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

    startTime = millis();
    timing = true;

    ledStartState = ledChangeStateZero;

    x = 0;
    inputString = "";
    level = 0;
    wrongSequence = 0;
  }

  if (simonsaysStart == 0) {
    sendingString = "";
  }

  if (timing == true)
  {
    if (millis() - startTime >= timeOut && simonsaysStart == 1)
    {
      for (int i = 0; i <= 8; i++) {
        leds[i] = CRGB::Black;
      }
      FastLED.show();
      timing = false;
    }
  }
}


int previousSendButtonState = 0;

void inputButtonSequence() {

  int sendButton = keys[2][3];
  int stateSendButton = 0;

  if (keys[0][0] == 0 && key1previousState == 0) {
    key1previousState = 1;
    leds[0] = CRGB::Purple;
    FastLED.show();
    inputString += "1a;";       //"Name" des Knopfes, der gedrückt wurde wird dem String zugefügt.
    xInputLength += 1;
    delay(100);
  }

  if (keys[0][0] == 1 && key1previousState == 1) {
    key1previousState = 0;
  }

  if (keys[1][0] == 0 && key2previousState == 0) {
    key2previousState = 1;
    leds[1] = CRGB::Purple;
    FastLED.show();
    inputString += "2a;";
    xInputLength += 1;
  }

  if (keys[1][0] == 1 && key2previousState == 1) {
    key2previousState = 0;
  }

  if (keys[2][0] == 0 && key3previousState == 0) {
    key3previousState = 1;
    leds[2] = CRGB::Purple;
    FastLED.show();
    inputString += "3a;";
    xInputLength += 1;
  }

  if (keys[2][0] == 1 && key3previousState == 1) {
    key3previousState = 0;
  }

  if (keys[0][1] == 0 && key4previousState == 0) {
    key4previousState = 1;
    leds[5] = CRGB::Purple;
    FastLED.show();
    inputString += "1b;";
    //x += 1;
    xInputLength += 1;
  }

  if (keys[0][1] == 1 && key4previousState == 1) {
    key4previousState = 0;
  }

  if (keys[1][1] == 0 && key5previousState == 0) {
    key5previousState = 1;
    leds[4] = CRGB::Purple;
    FastLED.show();
    inputString += "2b;";
    //x += 1;
    xInputLength += 1;
  }

  if (keys[1][1] == 1 && key5previousState == 1) {
    key5previousState = 0;
  }

  if (keys[2][1] == 0 && key6previousState == 0) {
    key6previousState = 1;
    leds[3] = CRGB::Purple;
    FastLED.show();
    inputString += "3b;";
    //x += 1;
    xInputLength += 1;
  }

  if (keys[2][1] == 1 && key6previousState == 1) {
    key6previousState = 0;
  }

  if (keys[0][2] == 0 && key7previousState == 0) {
    key7previousState = 1;
    leds[6] = CRGB::Purple;
    FastLED.show();
    inputString += "1c;";
    //x += 1;
    xInputLength += 1;
  }

  if (keys[0][2] == 1 && key7previousState == 1) {
    key7previousState = 0;
  }


  if (keys[1][2] == 0 && key8previousState == 0) {
    key8previousState = 1;
    leds[7] = CRGB::Purple;
    FastLED.show();
    inputString += "2c;";
    //x += 1;
    xInputLength += 1;
  }

  if (keys[1][2] == 1 && key8previousState == 1) {
    key8previousState = 0;
  }

  if (keys[2][2] == 0 && key9previousState == 0) {
    key9previousState = 1;
    leds[8] = CRGB::Purple;
    FastLED.show();
    inputString += "3c;";
    //x += 1;
    xInputLength += 1;
  }

  if (keys[2][2] == 1 && key9previousState == 1) {
    key9previousState = 0;
  }

  //Serial.println(sendButton);

  //send inputString to Server
  if (sendButton == previousSendButtonState) {
    if (sendButton == 0) {
      Serial.println(inputString);
      stateSendButton = sendButton;

      // Alle LEDs aus bei senden
      for (int i = 0; i <= 8; i++) {
        leds[i] = CRGB::Black;
        FastLED.show();
      }
    }


  }
  previousSendButtonState = sendButton;
}


void serialEvent() {                           //Empfangen vom checkString
  while (Serial.available()) {                  //solange in schleife, wie Daten reinkommen
    char inChar = (char)Serial.read();          //in inChar wird z.B. "1a;" und dann "1a; 3b;" usw. gespeichert.

    if (inChar == 'E') {                        //wenn E am Ende, dann ist der String zu ende.
      stringComplete = 'E';
      stringToArray(checkString, ';');

    } else {
      checkString += inChar;
    }
  }
  //  Serial.print("checkString: ");
  //  Serial.println(checkString);
}


void stringToArray(String text, char splitChar) {   //Der String wird geteilt (von "1a; 3b;" zu "1a" und "3b") und die Werte in das inputArray gepackt.
  int r = 0;
  arrayCounter = 0;
  for (int i = 0; i < text.length(); i++) {
    if (text.charAt(i) == splitChar) {
      inputArray[arrayCounter] = text.substring(r, i);
      r = (i + 1);
      arrayCounter++;
    }
  }
//    Serial.println(inputArray[0]);
//    Serial.println(inputArray[1]);
//    Serial.println(inputArray[2]);
//    Serial.println(inputArray[3]);
//    Serial.println(inputArray[4]);
//    Serial.println(inputArray[5]);
}


int previousReceiveButtonState = 0;
void displayMatrix() {
  int receiveButton = keys[1][3];

  if (receiveButton = 0 && previousReceiveButtonState == 0) {
    previousReceiveButtonState = 1;
    leds[7] = CRGB::Blue;
    FastLED.show();
    delay(500);
    leds[7] = CRGB::Black;
    FastLED.show();
    delay(500);
  
    leds[3] = CRGB::Blue;
    FastLED.show();
    delay(500);
    leds[3] = CRGB::Black;
    FastLED.show();
    delay(500);
  
    leds[5] = CRGB::Blue;
    FastLED.show();
    delay(500);
    leds[5] = CRGB::Black;
    FastLED.show();
    delay(500);
  } 
  if (previousReceiveButtonState == 1) {
    previousReceiveButtonState = 0;
  }
}


void comparison() {
  int receiveButton = keys[1][3];
}


void addElement() {

}

















/*int sendButtonPreviousState = 0;

  void comparison() {

  int sendButton = keys[2][3];
  int sendButtonState;

  if (sendButton == 0 && sendButtonPreviousState == 0) {

  //    xSendingLength = xInputLength;
  //    xInputLength = 0;

    sendButtonPreviousState = 1;
    sendButtonState = 1;

    Serial.print(xInputLength); Serial.print(" - ");
    Serial.println(xSendingLength);

    if (xInputLength == xSendingLength) {
      if (inputString == sendingString) {
        for (int i = 0; i <= 8; i++) {
          leds[i] = CRGB::Green;
          FastLED.show();
        }
        delay(1000);
        for (int i = 0; i <= 8; i++) {
          leds[i] = CRGB::Black;
          FastLED.show();
        }


      }
      else {
        for (int i = 0; i <= 8; i++) {
          leds[i] = CRGB::Red;
          FastLED.show();
        }
        delay(1000);
        wrongSequence = 1;
      }
    }

    if (sendButton == 0 && sendButtonPreviousState == 1) {
      //sendButtonPreviousState = 0;
      sendButtonState = 0;
    }
  }
  }*/


void loop() {

  readMatrix();

  //printMatrix();

  ledStart();

  inputButtonSequence();

  serialEvent();

  //stringToArray(String text, char splitChar);         // ???

  displayMatrix();

  //comparison();

  //addElement();


  //SequenceComparison();                             // delete.


  if (stringComplete == 'E') {


    checkString = "";
    stringComplete = "";
  }

  /*splitCommand(checkString, ';');
    for (int i = 0; i < arrayCounter; i++) {
    Serial.println(inputArray[i]);
    }*/
}
