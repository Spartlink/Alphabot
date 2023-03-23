// Alphabot Project 

// Libraries include

#include <AlphaBot.h>
#include <IRremote.h>

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

// const value initialisation
const int speedOne = 100;
const int speedTwo = 255;
int speed = speedOne; // mutable speed variable
int RECV_PIN = 4;
IRrecv irrecv(RECV_PIN);
decode_results results;

AlphaBot Carl = AlphaBot();

void setup() {
  Carl.SetSpeed(speed); // set speed of the bot
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
 if (irrecv.decode(&results)) {
  if (results.value == buttonCentPlus || buttonPlus) {
    forward(results.value);
  }
  irrecv.resume();
 }
 delay(50);
}

void setSpeed(speedInt) {
  speed = speedInt;
  Carl.SetSpeed(speed);
}

void forward(int button) {
  if (button == buttonCentPlus) {
    speed = speedOne;
    Carl.SetSpeed(speed);
    Carl.Forward(1000);
  } else if (button == buttonPlus) {
    speed = speedTwo;
    Carl.SetSpeed(speed);
    Carl.Forward(1000);
  }
}

void backward(int button) {
  if (button == buttonDeux) {
    speed = speedOne;
      
  }
}
