//Code by haneefputtur.com
//Using Push Buttons to create 4 X 4 Switch matrix. Can be extended to more buttons
//Data will be displayed in serial monitor for testing project
byte h = 0, v = 0; //variables used in for loops
const unsigned long period = 50; //little period used to prevent error
unsigned long kdelay = 0;      // variable used in non-blocking delay
const byte rows = 4;           //number of rows of keypad
const byte columns = 3;          //number of columnss of keypad
const byte Output[rows] = {5, 6, 7, 8}; //array of pins used as output for rows of keypad
const byte Input[columns] = {2, 3, 4}; //array of pins used as input for columnss of keypad
int buttonState1;
int buttonState2;
int buttonState3;
int buttonState4;
int buttonState5;
int buttonState6;
int buttonState7;
int buttonState8;
int buttonState9;
int buttonState10;
int buttonState11;
int buttonState12;
byte keypad() // function used to detect which button is used

{
  static bool no_press_flag = 0; //static flag used to ensure no button is pressed
  for (byte x = 0; x < columns; x++) // for loop used to read all inputs of keypad to ensure no button is pressed
  {
    if (digitalRead(Input[x]) == HIGH); //read evry input if high continue else break;
    else
      break;
    if (x == (columns - 1)) //if no button is pressed
    {
      no_press_flag = 1;
      h = 0;
      v = 0;
    }
  }
  if (no_press_flag == 1) //if no button is pressed
  {
    for (byte r = 0; r < rows; r++) //for loop used to make all output as low
      digitalWrite(Output[r], LOW);
    for (h = 0; h < columns; h++) // for loop to check if one of inputs is low
    {
      if (digitalRead(Input[h]) == HIGH) //if specific input is remain high (no press on it) continue
        continue;
      else    //if one of inputs is low
      {
        for (v = 0; v < rows; v++) //for loop used to specify the number of row
        {
          digitalWrite(Output[v], HIGH);  //make specified output as HIGH
          if (digitalRead(Input[h]) == HIGH) //if the input that selected from first sor loop is change to high
          {
            no_press_flag = 0;              //reset the no press flag;
            for (byte w = 0; w < rows; w++) // make all outputs as low
              digitalWrite(Output[w], LOW);
            return v * 4 + h; //return number of button
          }
        }
      }
    }
  }
  return 50;
}
void setup()
{
  for (byte i = 0; i < rows; i++) //for loop used to make pin mode of outputs as output
  {
    pinMode(Output[i], OUTPUT);
  }
  for (byte s = 0; s < columns; s++) //for loop used to make pin mode of inputs as inputpullup
  {
    pinMode(Input[s], INPUT_PULLUP);
  } Serial.begin(9600); //to use serial monitor we set the buad rate
}
void loop() {
  if (millis() - kdelay > period) //used to make non-blocking delay
  {
    kdelay = millis(); //capture time from millis function
    switch (keypad())  //switch used to specify which button
    {
      case 0:
        Serial.print(1);
        Serial.print(", ");
        buttonState1 = 1;
        Serial.print("button State: ");
        Serial.println(buttonState1);
        break;
      case 1:
        Serial.print(5);
        Serial.print(", ");
        buttonState5 = 1;
        Serial.print("button State: ");
        Serial.println(buttonState5);
        break;
      case 2:
        Serial.print(9);
        Serial.print(", ");
        buttonState9 = 1;
        Serial.print("button State: ");
        Serial.println(buttonState9);
        break;
      case 3:
        Serial.print("geht nicht");
        Serial.print(", ");
        buttonState4 = 1;
        Serial.print("button State: ");
        Serial.println(buttonState4);
        break;
      case 4:
        Serial.print(2);
        Serial.print(", ");
        Serial.print("button State: ");
        Serial.println(buttonState2);
        break;
      case 5:
        Serial.print(6);
        Serial.print(", ");
        buttonState6 = 1;
        Serial.print("button State: ");
        Serial.println(buttonState6);
        break;
      case 6:
        Serial.print(10);
        Serial.print(", ");
        buttonState10 = 1;
        Serial.print("button State: ");
        Serial.println(buttonState10);
        break;
      case 7:
        Serial.print("geht nicht");
        Serial.print(", ");
        buttonState8 = 1;
        Serial.print("button State: ");
        Serial.println(buttonState8);
        break;
      case 8:
        Serial.print(3);
        Serial.print(", ");
        buttonState3 = 1; 
        Serial.print("button State: ");
        Serial.println(buttonState3);
        break;
      case 9:
        Serial.print(7);
        Serial.print(", ");
        buttonState7 = 1; 
        Serial.print("button State: ");
        Serial.println(buttonState7);
        break;
      case 10:
        Serial.print(11);
        Serial.print(", ");
        buttonState11 = 1;
        Serial.print("button State: ");
        Serial.println(buttonState11);
        break;
      case 11:
        Serial.print("geht nicht");
        Serial.print(", ");
        buttonState12 = 1; 
        Serial.print("button State: ");
        Serial.println(buttonState12);
        break;
        ;
    }
  }
}
