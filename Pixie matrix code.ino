
int state[]={1,2,3,4,5,6,7,8,9};      // the current state of the output pin
int reading[]={1,2,3,4,5,6,7,8,9};    // the current reading from the input pin
int previous[]={1,2,3,4,5,6,7,8,9};   // the previous reading from the input pin

long time = 0;         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers

int led_rows[]={8,9,10};
int led_cols[]={11,12,13};
const byte rows = 3; 
const byte cols = 3; 
char keys[rows][cols] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
};

byte rowPins[rows] = {5, 6, 7}; 
byte colPins[cols] = {2, 3, 4}; 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );

void setup(){
  Serial.begin(9600);
  
  for(int i=1;i<10;i++){
  state[i]=LOW;
  }
  
  for(int i=1;i<10;i++){
  reading[i]=LOW;
  }
  
  for(int i=1;i<10;i++){
  previous[i]=LOW;
  }
  
  for(int i=0;i<3;i++){
  pinMode(led_cols[i], OUTPUT);
  digitalWrite (led_cols[i], HIGH);
  }
  
  for(int i=0;i<3;i++){
  pinMode(led_rows[i], OUTPUT);
  digitalWrite (led_rows[i], LOW);
  }
  
}

void Led1_On(){
  digitalWrite (led_rows[0], HIGH);
  digitalWrite (led_cols[0], LOW);
}

void Led1_Off(){
  digitalWrite (led_rows[0], LOW);
  digitalWrite (led_cols[0], HIGH);
}

void Led2_On(){
  digitalWrite (led_rows[0], HIGH);
  digitalWrite (led_cols[1], LOW);
}

void Led2_Off(){
  digitalWrite (led_rows[0], LOW);
  digitalWrite (led_cols[1], HIGH);
}

void Led3_On(){
  digitalWrite (led_rows[0], HIGH);
  digitalWrite (led_cols[2], LOW);
}

void Led3_Off(){
  digitalWrite (led_rows[0], LOW);
  digitalWrite (led_cols[2], HIGH);
}

void Led4_On(){
  digitalWrite (led_rows[1], HIGH);
  digitalWrite (led_cols[0], LOW);
}

void Led4_Off(){
  digitalWrite (led_rows[1], LOW);
  digitalWrite (led_cols[0], HIGH);
}

void Led5_On(){
  digitalWrite (led_rows[1], HIGH);
  digitalWrite (led_cols[1], LOW);
}

void Led5_Off(){
  digitalWrite (led_rows[1], LOW);
  digitalWrite (led_cols[1], HIGH);
}

void Led6_On(){
  digitalWrite (led_rows[1], HIGH);
  digitalWrite (led_cols[2], LOW);
}

void Led6_Off(){
  digitalWrite (led_rows[1], LOW);
  digitalWrite (led_cols[2], HIGH);
}

void loop(){
  char key = keypad.getKey();
  
  if (key == '1' && previous[1] == LOW && millis() - time > debounce) {
    if (state[1] == HIGH)
     { 
      state[1] = LOW;
      Led1_Off();
     }
    else
      {
      state[1] = HIGH;
      Led1_On();
      Serial.println(state[1]);
      }

    time = millis();    
  }
  
  previous[1] = reading[1];
  
  if (key == '2' && previous[2] == LOW && millis() - time > debounce) {
    if (state[2] == HIGH)
     { 
      state[2] = LOW;
      Led2_Off();
     }
    else
      {
      state[2] = HIGH;
      Led2_On();
      Serial.println(state[2]);
      }

    time = millis();    
  }
  
  previous[2] = reading[2];
  
  if (key == '3' && previous[3] == LOW && millis() - time > debounce) {
    if (state[3] == HIGH)
     { 
      state[3] = LOW;
      Led3_Off();
     }
    else
      {
      state[3] = HIGH;
      Led3_On();
      Serial.println(state[3]);
      }

    time = millis();    
  }
  
  previous[3] = reading[3];
  
  if (key == '4' && previous[1] == LOW && millis() - time > debounce) {
    if (state[4] == HIGH)
     { 
      state[4] = LOW;
      Led4_Off();
     }
    else
      {
      state[4] = HIGH;
      Led4_On();
      Serial.println(state[4]);
      }

    time = millis();    
  }
  
  previous[4] = reading[4];
  
  if (key == '5' && previous[5] == LOW && millis() - time > debounce) {
    if (state[5] == HIGH)
     { 
      state[5] = LOW;
      Led5_Off();
     }
    else
      {
      state[5] = HIGH;
      Led5_On();
      Serial.println(state[5]);
      }

    time = millis();    
  }
  
  previous[5] = reading[5];
  
  if (key == '6' && previous[6] == LOW && millis() - time > debounce) {
    if (state[6] == HIGH)
     { 
      state[6] = LOW;
      Led6_Off();
     }
    else
      {
      state[6] = HIGH;
      Led6_On();
      Serial.println(state[6]);
      }

    time = millis();    
  }
  
  previous[1] = reading[6];
}