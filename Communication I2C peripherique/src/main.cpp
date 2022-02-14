/*
  Titre      : LED et Potentiometre avec deux microcontroleur 
  Auteur     : Anis Aliouachene
  Date       : 10/02/2022
  Description: Partie peripherique I2C 
  Version    : 0.0.1
*/


#include <Arduino.h>
#include<Wire.h>

// Declaration
const int LED_PIN = 5;
int Intensite; 

// Fonction pour lire et recevoir les donnees envoyer de la part de controleur 
void receive(int bytes){
  Intensite =  Wire.read();
}

// Setup des broches et communication I2C 
void setup() {

  pinMode(LED_PIN, OUTPUT);
  Wire.begin(9); // Debut communication I2C avec l'adresse 9 
  Wire.onReceive(receive); // appeler la fonction receive lorsque le peripherique reçois une donnee

}

void loop() {

  // Allumage LED 
  analogWrite(LED_PIN, Intensite);

}

