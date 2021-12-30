/*
  Project Name    : Multi Feedback Removable Parking Assistant
  Author          : Hırrimos
  Last Update     : 26.12.2021
  //*******************************************************************************************************************************************************************************************************************************************************
  Purpose         : To avoid low-speed parking accidents and thereby contribute the save time and money with LED ,LCD screen and buzzer warnings which are depending on measurement value of Ultrasonic Sensor value on the interval of [2-400] centimeters.
  //*******************************************************************************************************************************************************************************************************************************************************
  System Input    : 1) HC SR04               --> To measure the distance between sensor and driver's car
  
  Systen Output   : 1) 1602A LCD 16x2 screen --> To print distance value in centimeters that comes from the HC SR04
                    2) Green and Red LEDs    --> To give a response in different combinations at different distances
                    3) Buzzer                --> To make a sound in different delays at different distances 
  //*******************************************************************************************************************************************************************************************************************************************************
  System Work     : The distance is found by HC SR04 ultrasonic sensor with some equations, according to the distance value, appropriate section(if or else if) is applied and acts are carried out that is written in the section. Distance value in 
                    centimeters is printed on the LCD screen, a sound response with buzzer with the shorter the distance is more often and LEDs turns into GREEN to RED when the distance becomes shorter.
  //*******************************************************************************************************************************************************************************************************************************************************               
 */
 
 /*---Code with detailed explanation is given below---*/
 
#include <LiquidCrystal_I2C.h>  // To add necasarry libraries for 16x2 LCD screen
#include <Wire.h>               // To add necasarry libraries for 16x2 LCD screen

#define echoPin 2               // Attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3               // Attach pin D3 Arduino to pin Trig of HC-SR04
#define greenled1 4             // Digital 4 pin is connected with greenled1
#define greenled2 5             // Digital 5 pin is connected with greenled2
#define greenled3 6             // Digital 6 pin is connected with greenled3               The point of DEFINING PINS is give names to them and write code easier rather than dealing with hard to remember numbers 
#define greenled4 7             // Digital 7 pin is connected with greenled4
#define greenled5 8             // Digital 8 pin is connected with greenled5
#define greenled6 9             // Digital 9 pin is connected with greenled6
#define redled1 10              // Digital 10 pin is connected with redled1
#define buzzer 11               // Digital 11 pin is connected with buzzer
long mesafe;                    // The distance between obstacle and HC SR04 (Twice of the distance. Ultrasonic waves make round trip )
int sure ;                      // To store the time that ultrasonic wave hits the obstacle and turns back

LiquidCrystal_I2C ekran1(0x27,16,2); // The type of LCD screen is 27 and it contains 16 characters per each line. Also it has 2 lines

void setup()
{
pinMode(trigPin,OUTPUT);        // Trigger (transmitter) pin defined as OUTPUT
pinMode(echoPin,INPUT);         // Echo (receiver) pin defined as INPUT 
pinMode(greenled1,OUTPUT);      // greenled1 pin defined as OUTPUT
pinMode(greenled2,OUTPUT);      // greenled2 pin defined as OUTPUT
pinMode(greenled3,OUTPUT);      // greenled3 pin defined as OUTPUT
pinMode(greenled4,OUTPUT);      // greenled4 pin defined as OUTPUT
pinMode(greenled5,OUTPUT);      // greenled5 pin defined as OUTPUT
pinMode(greenled6,OUTPUT);      // greenled6 pin defined as OUTPUT
pinMode(redled1,OUTPUT);        // redled1 pin defined as OUTPUT
pinMode(buzzer,OUTPUT);         // buzzer pin defined as OUTPUT

  ekran1.init();                // It is a required line to print distance value on the screen 
  
  ekran1.backlight();           // It is a feature that increases the light and illuminates the dark part when part of the image is bright and part is dark
   
}

void loop()
{
  
digitalWrite(trigPin, HIGH);         // To set trinpin as HIGH        
delayMicroseconds(200);             // Wait for 1000 miliseconds
digitalWrite(trigPin, LOW);          // To set trinpin as LOW                         

sure = pulseIn(echoPin,HIGH);        // To define an equation for how to obtain elapsed time
mesafe = (sure/2) /29.1;             // To define an equation for how to obtain distance

                                     /*****************According to the value of HC SR 04*********************
                                     ***********************STATEMENTS GIVEN BELOW***************************/
                                     
if (mesafe < 10) {                   //  To do statements when distance < 10 centimeters
   digitalWrite(greenled3,HIGH);     // greenled3 is ON
   digitalWrite(greenled4,HIGH);     // greenled4 is ON
   delay(100);                       // Wait for 100 miliseconds
   digitalWrite(greenled2,HIGH);     // greenled2 is ON
   digitalWrite(greenled5,HIGH);     // greenled5 is ON
   delay(100);                       // Wait for 100 miliseconds
   digitalWrite(greenled6,HIGH);     // greenled6 is ON
   digitalWrite(greenled1,HIGH);     // greenled1 is ON
   delay(100);                       // Wait for 100 miliseconds
   digitalWrite(greenled1,LOW);      // greenled1 is OFF
   delay(100);                       // Wait for 100 miliseconds
   digitalWrite(greenled2,LOW);      // greenled2 is OFF
   delay(100);                       // Wait for 100 miliseconds
   digitalWrite(greenled3,LOW);      // greenled3is OFF
   delay(100);                       // Wait for 100 miliseconds
   digitalWrite(greenled4,LOW);      // greenled4 is OFF
   delay(100);                       // Wait for 100 miliseconds
   digitalWrite(greenled5,LOW);      // greenled5 is OFF
   delay(100);                       // Wait for 100 miliseconds
   digitalWrite(greenled6,LOW);      // greenled3 is OFF
   delay(100);                       // Wait for 100 miliseconds
   digitalWrite(redled1,HIGH);       // redled1 is ON
   digitalWrite(buzzer,HIGH);        // buzzer is ON
   
   ekran1.print("Mesafe = ");        // To inform the user what UNIT of MEASUREMENT from HC SR04 about (lenght)
   ekran1.print(mesafe);             // To print the instant distance
   ekran1.println(" cm   ");         // Unit of the measurement
   delay(250);                       // Wait for 250 miliseconds

 ekran1.clear();                     // Delete evereything on the LCD screen
   }
                                     //*************************************************************************
                                     
   else if (mesafe < 25) {           //  To do statements when distance < 25 cm && distance > 10 centimeters 

   digitalWrite(greenled1,LOW);      // greenled1 is OFF
   digitalWrite(greenled2,LOW);      // greenled2 is OFF
   digitalWrite(greenled3,HIGH);     // greenled3 is ON
   digitalWrite(greenled4,HIGH);     // greenled4 is ON
   digitalWrite(greenled5,LOW);      // greenled5 is OFF
   digitalWrite(greenled6,LOW);      // greenled6 is OFF
   digitalWrite(redled1,HIGH);       // redled1 is ON
   digitalWrite(buzzer,HIGH);        // buzzer is ON
   delay(550);                       // Wait for 550 miliseconds
   digitalWrite(buzzer,LOW);         // buzzer is OFF
   delay(550);                       // Wait for 550 miliseconds
   ekran1.print("Mesafe = ");        // To inform the user what UNIT of MEASUREMENT from HC SR04 about (lenght) 
   ekran1.print(mesafe);             // To print the instant distance
   ekran1.println(" cm  ");          // Unit of the lenght in that code
   delay(250);                       // Wait 250 miliseconds

 ekran1.clear();                     // To clear everything on the LCD screen 
}
                                    //*************************************************************************
                                    
else if (mesafe < 50) {              //  To do statements when distance < 50 cm && distance > 25 centimeters 
   digitalWrite(greenled1,LOW);      // greenled1 is OFF
   digitalWrite(greenled2,LOW);      // greenled2 is OFF
   digitalWrite(greenled3,HIGH);     // greenled3 is ON
   digitalWrite(greenled4,HIGH);     // greenled4 is ON
   digitalWrite(greenled5,LOW);      // greenled5 is OFF
   digitalWrite(greenled6,LOW);      // greenled6 is OFF
   digitalWrite(redled1,LOW);        // redled1 is OFF
   digitalWrite(buzzer,HIGH);        // buzzer is ON
   delay(750);                       // Wait for 750 miliseconds
   digitalWrite(buzzer,LOW);         // buzzer is OFF
   delay(750);                       // Wait for 750 miliseconds
   ekran1.print("Mesafe = ");        // To inform the user what UNIT of MEASUREMENT from HC SR04 about (lenght)
   ekran1.print(mesafe);             // To print the instant distance
   ekran1.println(" cm  ");          // Unit of the lenght in that code
   delay(250);                       // Wait for 250 miliseconds
 
 ekran1.clear();                     // To clear everything on the screen 
}
                                     //*************************************************************************
                                     
else if (mesafe <= 75) {             //  To do statements when distance <= 75 cm && distance > 50 centimeters 
   digitalWrite(greenled1,LOW);      // greenled1 is OFF
   digitalWrite(greenled2,HIGH);     // greenled2 is ON
   digitalWrite(greenled3,HIGH);     // greenled3 is ON
   digitalWrite(greenled4,HIGH);     // greenled4 is ON
   digitalWrite(greenled5,LOW);      // greenled5 is OFF
   digitalWrite(greenled6,HIGH);     // greenled6 is ON
   digitalWrite(redled1,LOW);        // redled1 is OFF
   digitalWrite(buzzer,HIGH);        // buzzer is ON
   delay(1000);                      // Wait for 1000 miliseconds
   digitalWrite(buzzer,LOW);         // buzzer is OFF
   delay(1000);                      // Wait for 1000 miliseconds
   ekran1.print("Mesafe = ");        // To inform the user what UNIT of MEASUREMENT from HC SR04 about (lenght)
   ekran1.print(mesafe);             // To print the instant distance
   ekran1.println(" cm  ");          // Unit of the lenght in that code
   delay(250);                       // Wait for 250 miliseconds

 ekran1.clear();                     // To clear everything on the screen 
}
                                     //*************************************************************************
                                    
else if (mesafe > 100) {             //  To do statements when distance > 100 centimeters 
   digitalWrite(greenled1,HIGH);     // greenled1 is ON
   digitalWrite(greenled2,HIGH);     // greenled2 is ON
   digitalWrite(greenled3,HIGH);     // greenled3 is ON
   digitalWrite(greenled4,HIGH);     // greenled4 is ON
   digitalWrite(greenled5,HIGH);     // greenled5 is ON
   digitalWrite(greenled6,HIGH);     // greenled6 is ON
   digitalWrite(redled1,LOW);        // redled1 is OFF
   digitalWrite(buzzer,HIGH);        // buzzer is ON
   delay(1500);                      // Wait for 1500 miliseconds
   digitalWrite(buzzer,LOW);         // buzzer is OFF
   delay(1500);                      // Wait for 1500 miliseconds
   ekran1.print("Mesafe = ");        // To inform the user what UNIT of MEASUREMENT from HC SR04 about (lenght)
   ekran1.print(mesafe);             // To print the instant distance
   ekran1.println(" cm  ");          // Unit of the lenght in that code
   delay(250);                       // Wait for 250 miliseconds
    

 ekran1.clear();                     // To clear everything on the screen 
}

}
