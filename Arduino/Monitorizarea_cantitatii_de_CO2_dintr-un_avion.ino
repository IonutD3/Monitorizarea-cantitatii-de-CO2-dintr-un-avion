// Sistem de monitorizare CO2 - codul utilizat in simularea Proteus.
// Codul de mai jos pastreaza logica proiectului original; au fost adaugate comentarii
// pentru a explica rolul pinilor si al fiecarei ramuri de functionare.

#include "DFRobot_RGBLCD1602.h"
#include  <Wire.h>
DFRobot_RGBLCD1602 lcd(16,2);

// Culoarea de baza a LCD-ului RGB.
const int colorR = 255;
const int colorG = 0;
const int colorB = 0;
// LED verde WARNING / LED rosu WARNING.
int WG = 13;
int WR = 12;
// LED verde ALARM / LED rosu ALARM.
int AG = 11;
int AR = 10;
// LED verde ERROR / LED rosu ERROR.
int EG = 9;
int ER = 8;
// Contor pentru citirile considerate eronate.
int a=0;

// Initializarea LCD-ului, LED-urilor, iesirii pentru ventilatie si a portului Serial.
void setup() {
  lcd.init();
  lcd.setRGB(colorR,colorG,colorB);
  pinMode(WG, OUTPUT);
  pinMode(WR, OUTPUT);
  pinMode(AG, OUTPUT);
  pinMode(AR, OUTPUT);
  pinMode(EG, OUTPUT);
  pinMode(ER, OUTPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);
}

// Citirea si evaluarea valorii CO2 se face o data pe secunda.
void loop() {
// Citeste valoarea analogica de la A0.
float pot = analogRead(A0);  
  // Intervalul WARNING: valoarea afisata este intre 0.10 si 0.30.
  if(pot>=100 && pot<300)
    {  
     lcd.setCursor(0,0);
     lcd.print(pot/1000);
     lcd.setCursor(5,0);
     lcd.print("WARNING");
     Serial.println(" WARNING ");
     Serial.println(pot/1000);
     digitalWrite(WG, LOW);
     digitalWrite(WR, HIGH);
     digitalWrite(AG, HIGH);
     digitalWrite(AR, LOW);
     digitalWrite(EG, HIGH);
     digitalWrite(ER, LOW);
     lcd.setCursor(0,1);
     lcd.print("               ");     
    }
    // Intervalul ALARM: valoarea afisata este intre 0.30 si 1.00.
    else if(pot>=300 && pot<1000)
    {
     lcd.setCursor(0,0);
     lcd.print(pot/1000);
     lcd.setCursor(5,0);
     lcd.print("ALARM");
     Serial.println(" ALARM ");
     Serial.println(pot/1000);
     digitalWrite(WG, HIGH);
     digitalWrite(WR, LOW);
     digitalWrite(AG, LOW);
     digitalWrite(AR, HIGH);
     digitalWrite(EG, HIGH);
     digitalWrite(ER, LOW);
     digitalWrite(7, HIGH);
     lcd.setCursor(0,1);
     lcd.print("Ventilatie ON     "); 
     Serial.println(" Se porneste instalatia de ventilatie ");
    }
    // Valori foarte mici: ventilatia este oprita.
    else if(pot >0 && pot<=50)
    {
     lcd.setCursor(0,0);
     lcd.print(pot/1000);
     lcd.setCursor(5,0);
     lcd.print("          ");
     Serial.println(pot/1000);
     digitalWrite(WG, HIGH);
     digitalWrite(WR, LOW);
     digitalWrite(AG, HIGH);
     digitalWrite(AR, LOW);
     digitalWrite(EG, HIGH);
     digitalWrite(ER, LOW); 
     digitalWrite(7, LOW);
     lcd.setCursor(0,1);
     lcd.print("Ventilatie OFF     ");
     Serial.println(" Instalatia de ventilatie se opreste ");
    }
    // Valoare considerata in afara intervalului acceptat.
    // Dupa trei citiri de acest tip se afiseaza ERROR.
    else if(pot<0 || pot>1000)
    { 
    a=a+1;
     lcd.setCursor(0,0);
     lcd.print(pot/1000);
     lcd.setCursor(5,0);
     lcd.print("          ");
     Serial.println(pot/1000);
     digitalWrite(WG, HIGH);
     digitalWrite(WR, LOW);
     digitalWrite(AG, HIGH);
     digitalWrite(AR, LOW);
     digitalWrite(EG, HIGH);
     digitalWrite(ER, LOW);
     lcd.setCursor(0,1);
     lcd.print("               ");
    if(a==3){
     lcd.setCursor(0,0);
     lcd.print(pot/1000);
     lcd.setCursor(5,0);
     lcd.print("EROR");
     Serial.println(" EROR ");
     Serial.println(pot/1000);
     digitalWrite(WG, HIGH);
     digitalWrite(WR, LOW);
     digitalWrite(AG, HIGH);
     digitalWrite(AR, LOW);
     digitalWrite(EG, LOW);
     digitalWrite(ER, HIGH);
     lcd.setCursor(0,1);
     lcd.print("               "); 
     a=0;
    } }
    // Valoare normala, fara WARNING sau ALARM.
    else if(pot>=0 && pot<=1000)
    {
     lcd.setCursor(0,0);
     lcd.print(pot/1000);
     lcd.setCursor(5,0);
     lcd.print("          ");
     Serial.println(pot/1000);
     digitalWrite(WG, HIGH);
     digitalWrite(WR, LOW);
     digitalWrite(AG, HIGH);
     digitalWrite(AR, LOW);
     digitalWrite(EG, HIGH);
     digitalWrite(ER, LOW);
     lcd.setCursor(0,1);
     lcd.print("               "); 
    }
      // Asteapta aproximativ o secunda pana la urmatoarea citire.
      delay(1000);                   
}
