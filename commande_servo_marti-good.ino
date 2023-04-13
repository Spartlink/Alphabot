#include <Servo.h> 
 
Servo servo;  // Création d'un objet servo 
                // limité à 8 servos
 
int pos = 100;    // variable contenant la position désirée 
const int serv_out = 6;
const int pos_ouv = 50;
const int pos_fer = 210;
const int vitesse = 2;
 
void setup() 
{   
  servo.write(25);
}
//***************************************************
void fermeture()
{
    servo.attach(serv_out); 
    for(pos = pos_ouv; pos < pos_fer; pos += vitesse)  
    {                              
    servo.write(pos);
    delay(5);                                   
    } 
    servo.detach(); 
}
void ouverture()
{
    servo.attach(serv_out); 
    for(pos = pos_fer; pos > pos_ouv; pos -= vitesse)  
    {                                    
    servo.write(pos);
    delay(5);                                    
    }  
    servo.detach(); 
} 
//**************************************************
void loop() 
{ 
  fermeture();
  delay(2000);
  ouverture();
  delay(20);
} 
