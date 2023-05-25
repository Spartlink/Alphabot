// Alphabot Project 
//___________________________________ LIBRAIRIES ___________________________________

#include <AlphaBot.h>
#include <IRremote.h>
#include <Servo.h> 

//____________________________________ VARIABLES ____________________________________
// Code des boutons, NE PAS MODIFIER sauf erreur

const int buttonChMoins = 16753245;
const int buttonCh = 16736925;
const int buttonChPlus = 16769565;

const int buttonBack = 16720605;
const int buttonNext = 16712445;
const int buttonPause = 16761405;

const int buttonMoins = 16769055;
const int buttonPlus = 16754775;
const int buttonEQ = 16748655;

const int buttonZero = 16738455;
const int buttonCentPlus = 16750695;
const int buttonDeuxCentPlus = 16756815;

const int buttonUn = 16724175;
const int buttonDeux = 16718055;
const int buttonTrois = 16743045;
const int buttonQuatre = 16716015;
const int buttonCinq = 16726215;
const int buttonSix = 16734885;
const int buttonSept = 16728765;
const int buttonHuit = 16730805;
const int buttonNeuf = 16732845;

const int buttonContinu = 4294967295;

//------------------------ Autres Variables ------------------------
// Constantes
const int speedOne = 100;
const int speedTwo = 255;
const int serv_out = 6;
const int pos_ouv = 50;
const int pos_fer = 210;
const int vitesse = 2;

//Non constantes
int speed = speedOne; 
int RECV_PIN = 4;
int pos = 100;    // variable contenant la position désirée 
int vitesse2;

//______________________________________ SETUP ______________________________________
AlphaBot Carl = AlphaBot();
IRrecv irrecv(RECV_PIN);
decode_results results;
Servo servo;

void setup() {
  Carl.SetSpeed(speed); // set speed of the bot
  Serial.begin(9600);
  irrecv.enableIRIn();
}

//____________________________________ FONCTIONS ____________________________________
//------------------------ Mouvement ------------------------
void setSpeed(int speedInt) {
  speed = speedInt;
  Carl.SetSpeed(speed);
}

void forward(int button) {
  if (button == buttonCentPlus) {
    setSpeed(speedOne);
    Carl.Forward(1000);
  } else if (button == buttonPlus) {
    setSpeed(speedTwo);
    Carl.Forward(1000);
  }
}

void backward(int button) {
  Serial.println("hehe");
  if (button == buttonDeux) {
    setSpeed(speedOne);
    Carl.Backward(1000);   
  } else if (button == buttonCinq) {
    setSpeed(speedTwo);
    Carl.Backward(1000);
    
  }
}

void right(int button) {
  if (button == buttonPause) {
    Carl.Right(1000);
  } else if (button == buttonEQ) {
    Serial.println("debug");
    Carl.Right(500);
  } 
}

void left(int button) {
  if (button == buttonBack) {
    Carl.Left(1000);
  } else if (button == buttonMoins) {
    Carl.Left(500);
  }
}

//-------------------------- Pince --------------------------
void fermeture()
{
    servo.attach(6); 
    for(pos = 0; pos < 100; pos += vitesse)  
    {                              
      servo.write(pos);
      delay(5);                                   
    } 
    servo.detach(); 
}
void ouverture()
{
    servo.attach(6); 
    for(pos = 100; pos > 0; pos -= vitesse)  
    {                                    
      servo.write(pos);
      delay(5);                                    
    }  
    servo.detach(); 
} 

//____________________________________ MAIN _____________________________________
void loop() {
 if (irrecv.decode(&results)) {
  
  Serial.println(results.value);
  
  if (results.value == buttonCentPlus || buttonPlus) {
    vitesse2=results.value;
    forward(vitesse2);
    fermeture();
  } 
  
  if (results.value == buttonDeux || buttonCinq) {
    backward(results.value);
  }

  if (results.value == buttonEQ || buttonPause)  {
    right(results.value);
  }

  if (results.value == buttonChMoins) {
    fermeture();
  }

  if (results.value == buttonChPlus) {
    ouverture();
  }
  
  irrecv.resume();
 }
 delay(100 );
}
