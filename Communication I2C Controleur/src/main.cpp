/*
  Titre      : LED et Potentiometre avec deux microcontroleur 
  Auteur     : Anis Aliouachene
  Date       : 10/02/2022
  Description: Partie controleur I2C 
  Version    : 0.0.1
*/

#include <Arduino.h>
#include<Wire.h>

// Declaration 
const int POTENTIOMETRE = A1; 
int Valeur, Intensite; 

// Configuration Broche potentiometre et Protocol I2C
void setup() {

  pinMode(POTENTIOMETRE, INPUT); 
  Wire.begin(); // Debut communication I2C 
}


void loop() {

  // Recupuration valeur Analog de potentiometre
  Valeur = analogRead(POTENTIOMETRE); 
  Intensite = map(Valeur,0,1023,0,255); // Fonction map pour avoir une valeur entre 0 et 255 
  
  // Transfer et envoie des donnees vers l'autre microcontroleur 
  Wire.beginTransmission(9); // Debut de transmission vers l'adresse 9 
  Wire.write(Intensite); // Transmission de donnees 
  Wire.endTransmission(); 
  
  /* 
  Si on Ajoute un autre microcontroleur comme peripherique on doit utiliser une autre adresse par exemple 8 ou 12 ou 11 et dans 
  le code de peripherique on doit initialiser cette adress pour qu'il se communique a travers de cette adresse 

  Wire.beginTransmission(11); // Debut de transmission vers l'adresse 8
  Wire.write(Intensite); // Transmission de donnees 
  Wire.endTransmission(); 

  */ 
  
}