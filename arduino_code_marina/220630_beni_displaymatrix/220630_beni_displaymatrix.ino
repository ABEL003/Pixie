String pinOut[9] [2] = 
{ 
  {"1a", "0"}, 
  {"2a", "1"}, 
  {"3a", "2"}, 
  {"1b", "3"}, 
  {"2b", "4"}, 
  {"3b", "5"}, 
  {"1c", "6"}, 
  {"2c", "7"}, 
  {"3c", "8"}, 
}; 

String inputArray[20] = {"2a", "3c", "1c"};
int arrayCounter = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  displayMatrix();

}

void displayMatrix() {
  for(int i = 0; i <= arrayCounter; i++) {
    for(int j = 0; j < 9; j++) {
      //Serial.println(pinOut[j][0]);
      if (pinOut[j][0] == inputArray[i]){
        String ledPin = pinOut[j][1];
        Serial.println(ledPin);
      }
    }
  }
}
