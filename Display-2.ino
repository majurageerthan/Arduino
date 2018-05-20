

/*
  LiquidCrystal Library - display() and noDisplay()

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD and uses the
 display() and noDisplay() functions to turn on and off
 the display.

 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalDisplay

*/

// include the library code:
#include <Keypad.h>
#include <LiquidCrystal.h>

const byte ROWS = 2; //four rows
const byte COLS = 2; //three columns
char keys[ROWS][COLS] = {
  {'1','2'},
  {'4','5'},
  
};
byte rowPins[ROWS] = {6, 7}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 9}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
boolean onOrOff =false;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  //lcd.begin(cols, rows)
    lcd.begin(7, 4);
  // Print a message to the LCD.
 lcd.noDisplay();
 //addToCart();
  
}

void loop() {
//turn on .off - 4
//total price - 5
//ok - 1
//cancel - 2
  
   char key = keypad.getKey();
   lcd.setCursor(1, 2);
    if (key=='1'){
    sucess();   
  }else if (key=='2'){
    no();   
  }else if (key=='5'){
    totalPrice(); 
  }else if (key=='4'){
    turnOnOff(); 
  }
   

}

void addToCart(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Smart cart");
  
  lcd.setCursor(9, 4);
  lcd.print("Add to cart?");
  
  lcd.setCursor(17, 2);
  lcd.print("..........");
 
  lcd.setCursor(1, 4);
  lcd.print("yes");
  lcd.setCursor(7, 4);
  lcd.print("no");  


  //////////////////////////////////
//    lcd.setCursor(0, 0);
//  lcd.print("Smart cart");
//  
//  lcd.setCursor(1, 2);
//  lcd.print("Add to cart?");
//  
//  lcd.setCursor(17, 2);
//  lcd.print("..........");
// 
//  lcd.setCursor(9, 4);
//  lcd.print("yes");
//  lcd.setCursor(13, 4);
//  lcd.print("no"); 
  
  delay(500);
}

void sucess(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Product added"); 

}

void no(){
  lcd.clear();
  lcd.home();
  lcd.print("Product canceled"); 

}

void totalPrice(){
   lcd.clear();
   lcd.setCursor(0, 1);
   lcd.print("Total price");
   lcd.setCursor(17, 2);
   lcd.print("..........");
 
  lcd.setCursor(1, 4);
  lcd.print("Rs 2400");
  delay(2000);
  addToCart();
}

void welcome(){

  
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("Smart  cart");
      
      lcd.setCursor(11, 4);
      lcd.print("WELCOME");
      lcd.setCursor(1, 4);
     
      lcd.print("................");
     
       lcd.setCursor(17, 2);
      lcd.print("UOP Super Market");
   
  
}

void turnOnOff(){
  if(onOrOff == true){
    onOrOff = false;
    lcd.noDisplay();
  }else{
    onOrOff = true;
    lcd.display();
    welcome();
    
  }
}



