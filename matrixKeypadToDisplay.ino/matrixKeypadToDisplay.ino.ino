#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#include <Keypad.h>
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9,8,7,6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5,4,3,2}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);

  Serial.println("SSD1306 allocation starting");
  // setting voltage for display at 3.3v, failing which we don't proceed
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  Serial.println("Started OLED");
  display.display();
  delay(1000);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,32);
  display.print("Start");
  display.display();
}

void loop(){
  char customKey = customKeypad.getKey();
  if (customKey){
    display.clearDisplay();
    Serial.println(customKey);
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,32);
    display.print(customKey);
    display.display();
  }
}
