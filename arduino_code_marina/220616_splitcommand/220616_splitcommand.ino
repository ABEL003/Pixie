String inputArray[20];
int arrayCounter = 0;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
}
void loop() {
  splitCommand("123;456;789;999;", ';');
  for(int i = 0; i < arrayCounter; i++){
    Serial.println(inputArray[i]);
  }
  delay(7000);
}
void splitCommand(String text, char splitChar) {
  int r = 0;
  arrayCounter = 0;
  for (int i = 0; i < text.length(); i++) {
    if (text.charAt(i) == splitChar) {
      inputArray[arrayCounter] = text.substring(r, i);
      r = (i + 1);
      arrayCounter++;
    }
  }
}
