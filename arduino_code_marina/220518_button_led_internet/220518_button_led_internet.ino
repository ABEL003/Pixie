#include <Keypad.h>
#include <FastLED.h>
 
#define LED_PIN     5
#define NUM_LEDS    16
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define BRIGHTNESS  250
CRGB leds[NUM_LEDS];
 
int player=1;
int n,i,e=0,j=0;
char a[16]={'1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16'};
char key;
int w=0;
 
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {A0,A1,A2,A3}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {A4,A5,2,3}; //connect to the column pinouts of the keypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
 
void setup(){
  Serial.begin(9600);
  LEDS.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  for(int m=0;m<3;m++)
  {
        leds[0].setRGB(0, 204, 255);
        leds[1].setRGB(0, 204, 255);
        leds[2].setRGB(0, 204, 255);
        leds[3].setRGB(0, 204, 255);
        leds[4].setRGB(0, 204, 255);
        leds[5].setRGB(0, 204, 255);
        leds[6].setRGB(0, 204, 255);
        leds[7].setRGB(0, 204, 255);
        leds[8].setRGB(0, 204, 255);
        leds[9].setRGB(0, 204, 255);
        leds[10].setRGB(0, 204, 255);
        leds[11].setRGB(0, 204, 255);
        leds[12].setRGB(0, 204, 255);
        leds[13].setRGB(0, 204, 255);
        leds[14].setRGB(0, 204, 255);
        leds[15].setRGB(0, 204, 255);
        FastLED.show();
        delay(500);
        leds[0].setRGB(255, 0, 225);
        leds[1].setRGB(255, 0, 225);
        leds[2].setRGB(255, 0, 225);
        leds[3].setRGB(255, 0, 225);
        leds[4].setRGB(255, 0, 225);
        leds[5].setRGB(255, 0, 225);
        leds[6].setRGB(255, 0, 225);
        leds[7].setRGB(255, 0, 225);
        leds[8].setRGB(255, 0, 225);
        leds[9].setRGB(255, 0, 225);
        leds[10].setRGB(255, 0, 225);
        leds[11].setRGB(255, 0, 225);
        leds[12].setRGB(255, 0, 225);
        leds[13].setRGB(255, 0, 225);
        leds[14].setRGB(255, 0, 225);
        leds[15].setRGB(255, 0, 225);
        FastLED.show();
        delay(500);
  }
        FastLED.clear();
        FastLED.show();
}
  
void loop()
{
  key = customKeypad.getKey();
  if (key && player==1)
  {
    Serial.println("\nP1");
    Serial.println(key);
    n=number(key);
    Serial.println(n);
    leds[n].setRGB(0, 204, 255);
    FastLED.show();
    a[n]='X';
    Serial.println(a[n]);
    w=check(a,n);
    if(w==1)
    {
      Serial.println("Player 1 Wins!");
      while(1)
      {
        leds[0].setRGB(0, 204, 255);
        leds[1].setRGB(0, 204, 255);
        leds[2].setRGB(0, 204, 255);
        leds[3].setRGB(0, 204, 255);
        leds[4].setRGB(0, 204, 255);
        leds[5].setRGB(0, 204, 255);
        leds[6].setRGB(0, 204, 255);
        leds[7].setRGB(0, 204, 255);
        leds[8].setRGB(0, 204, 255);
        leds[9].setRGB(0, 204, 255);
        leds[10].setRGB(0, 204, 255);
        leds[11].setRGB(0, 204, 255);
        leds[12].setRGB(0, 204, 255);
        leds[13].setRGB(0, 204, 255);
        leds[14].setRGB(0, 204, 255);
        leds[15].setRGB(0, 204, 255);
        FastLED.show();
        delay(500);
        FastLED.clear();
        FastLED.show();
        delay(500);
    }
   }
    player++;
    delay(1000);
  }
  delay(20);
  key = customKeypad.getKey();
  if (key && player==2)
  {
    Serial.println("\nP2");
    Serial.println(key);
    n=number(key);
    Serial.println(n);
    leds[n].setRGB(255, 0, 225);
    FastLED.show();
    a[n]='0';
    Serial.println(a[n]);
    w=check(a,n);
    if(w==2)
    {
      Serial.println("Player 2 Wins!");
      while(1)
      {
        leds[0].setRGB(255, 0, 225);
        leds[1].setRGB(255, 0, 225);
        leds[2].setRGB(255, 0, 225);
        leds[3].setRGB(255, 0, 225);
        leds[4].setRGB(255, 0, 225);
        leds[5].setRGB(255, 0, 225);
        leds[6].setRGB(255, 0, 225);
        leds[7].setRGB(255, 0, 225);
        leds[8].setRGB(255, 0, 225);
        leds[9].setRGB(255, 0, 225);
        leds[10].setRGB(255, 0, 225);
        leds[11].setRGB(255, 0, 225);
        leds[12].setRGB(255, 0, 225);
        leds[13].setRGB(255, 0, 225);
        leds[14].setRGB(255, 0, 225);
        leds[15].setRGB(255, 0, 225);
        FastLED.show();
        delay(500);
        FastLED.clear();
        FastLED.show();
        delay(500);
        
        
    }
    }
    e++;
  player--;
   delay(1000);
  }
  if(e==8)
  {
    Serial.println("Game Draw");
    while(1)
    {
        leds[0].setRGB(255, 0, 0);
        leds[1].setRGB(255, 0, 0);
        leds[2].setRGB(255, 0, 0);
        leds[3].setRGB(255, 0, 0);
        leds[4].setRGB(255, 0, 0);
        leds[5].setRGB(255, 0, 0);
        leds[6].setRGB(255, 0, 0);
        leds[7].setRGB(255, 0, 0);
        leds[8].setRGB(255, 0, 0);
        leds[9].setRGB(255, 0, 0);
        leds[10].setRGB(255, 0, 0);
        leds[11].setRGB(255, 0, 0);
        leds[12].setRGB(255, 0, 0);
        leds[13].setRGB(255, 0, 0);
        leds[14].setRGB(255, 0, 0);
        leds[15].setRGB(255, 0, 0);
        FastLED.show();
        delay(1000);
        FastLED.clear();
        FastLED.show();
        delay(500);
  }
  }
  delay(20);
}
 
int number(char keyn)
{
  if(keyn == '1')
    return 0;
  if(keyn == '2')
    return 1;
  if(keyn == '3')
    return 2;
  if(key == 'A')
    return 3;
  if(keyn == '4')
    return 4;
  if(keyn == '5')
    return 5;
  if(keyn == '6')
    return 6;
  if(keyn == 'B')
    return 7;
  if(keyn == '7')
    return 8;
  if(keyn == '8')
    return 9;
  if(keyn == '9')
    return 10;
  if(keyn == 'C')
    return 11;
  if(key == '*')
    return 12;
  if(keyn == '0')
    return 13;
  if(keyn == '#')
    return 14;
  if(keyn == 'D')
    return 15;
}
 
int check(char a[16],int n)
{
  
  if(a[0]=='X' && a[1]=='X' && a[2]=='X' && a[3]=='X')
    return 1;
  if(a[0]=='0' && a[1]=='0' && a[2]=='0' && a[3]=='0')
    return 2;
  if(a[0]=='X' && a[4]=='X' && a[8]=='X' && a[12]=='X')
    return 1;
  if(a[0]=='0' && a[4]=='0' && a[8]=='0' && a[12]=='0')
    return 2;
  if(a[0]=='X' && a[5]=='X' && a[10]=='X' && a[15]=='X')
    return 1;
  if(a[0]=='0' && a[5]=='0' && a[10]=='0' && a[15]=='0')
    return 2;
  if(a[1]=='X' && a[5]=='X' && a[9]=='X' && a[13]=='X')
    return 1;
  if(a[1]=='0' && a[5]=='0' && a[9]=='0' && a[13]=='0')
    return 2;
  if(a[2]=='X' && a[6]=='X' && a[10]=='X' && a[14]=='X')
    return 1;
  if(a[2]=='0' && a[6]=='0' && a[10]=='0' && a[14]=='0')
    return 2;
  if(a[3]=='X' && a[7]=='X' && a[11]=='X' && a[15]=='X')
    return 1;
  if(a[3]=='0' && a[7]=='0' && a[11]=='0' && a[15]=='0')
    return 2;
  if(a[3]=='X' && a[6]=='X' && a[9]=='X' && a[12]=='X')
    return 1;
  if(a[3]=='0' && a[6]=='0' && a[9]=='0' && a[12]=='0')
    return 2;
  if(a[4]=='X' && a[5]=='X' && a[6]=='X' && a[7]=='X')
    return 1;
  if(a[4]=='0' && a[5]=='0' && a[6]=='0' && a[7]=='0')
    return 2;
  if(a[8]=='X' && a[9]=='X' && a[10]=='X' && a[11]=='X')
    return 1;
  if(a[8]=='0' && a[9]=='0' && a[10]=='0' && a[11]=='0')
    return 2;
  if(a[12]=='X' && a[13]=='X' && a[14]=='X' && a[15]=='X')
    return 1;
  if(a[12]=='0' && a[13]=='0' && a[14]=='0' && a[15]=='0')
    return 2;
}
