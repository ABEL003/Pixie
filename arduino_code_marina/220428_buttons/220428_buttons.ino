// constants won't change. They're used here to set pin numbers:
const int button1 = 2;     // the number of the pushbutton pin
const int button2 = 3;
const int button3 = 4;
const int button4 = 5;
const int button5 = 6;
const int button6 = 7;
const int button7 = 8;
const int button8 = 9;
const int button9 = 10;


// variables will change:
int buttonState1 = 0;
int buttonState2 = 0; 
int buttonState3 = 0; 
int buttonState4 = 0; 
int buttonState5 = 0; 
int buttonState6 = 0; 
int buttonState7 = 0; 
int buttonState8 = 0; 
int buttonState9 = 0; 


void setup() {

  // initialize the pushbutton pin as an input:
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
  pinMode(button6, INPUT);
  pinMode(button7, INPUT);
  pinMode(button8, INPUT);
  pinMode(button9, INPUT);
  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
 buttonState1 = digitalRead(button1);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState1 == HIGH) {
    // turn LED on:
    Serial.println("Button1 pressed");
  };
  buttonState2 = digitalRead(button2);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState2 == HIGH) {
    // turn LED on:
    Serial.println("Button2 pressed");
  };
  buttonState3 = digitalRead(button3);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState3 == HIGH) {
    // turn LED on:
    Serial.println("Button3 pressed");
  };
  buttonState4 = digitalRead(button4);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState4 == HIGH) {
    // turn LED on:
    Serial.println("Button4 pressed");
  };
  buttonState5 = digitalRead(button5);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState5 == HIGH) {
    // turn LED on:
    Serial.println("Button5 pressed");
  };
  buttonState6 = digitalRead(button6);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState6 == HIGH) {
    // turn LED on:
    Serial.println("Button6 pressed");
  };
  buttonState7 = digitalRead(button7);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState7 == HIGH) {
    // turn LED on:
    Serial.println("Button7 pressed");
  };

 buttonState8 = digitalRead(button8);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState8 == HIGH) {
    // turn LED on:
    Serial.println("Button8 pressed");
  };
  buttonState9 = digitalRead(button9);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState9 == HIGH) {
    // turn LED on:
    Serial.println("Button9 pressed");
  };
}
