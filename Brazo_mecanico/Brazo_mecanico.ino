#include <Servo.h>

Servo brazo;
Servo pinza;
Servo base;
Servo hombro;

int posicion=0;

int valorbase[40];
int valorbrazo[40];

const int boton1 = 4;
const int boton2 = 5;

int potpin0 = A0;  
int val0;

int potpin1 = A1;  
int val1;

int potpin2 = A3;  
int val2;

int potpin3 = A5;  
int val3;


void setup() {
  
  pinza.attach(8); 
  hombro.attach(9);
  brazo.attach(10);
  base.attach(11);
 

  pinMode(boton1, INPUT);
  pinMode(boton2, INPUT);
    
}

void loop() {

val1 = analogRead(A1);            // reads the value of the potentiometer (value between 0 and 1023)
  val1 = map(val1, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  brazo.write(val1);                  // sets the servo position according to the scaled value
  

val0 = analogRead(A0);            // reads the value of the potentiometer (value between 0 and 1023)
  val0 = map(val0, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  pinza.write(val0);                  // sets the servo position according to the scaled value
  delay(15);     

val2 = analogRead(A3);            // reads the value of the potentiometer (value between 0 and 1023)
  val2 = map(val2, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  hombro.write(val2);                  // sets the servo position according to the scaled value
  delay(15);   

val3 = analogRead(A5);            // reads the value of the potentiometer (value between 0 and 1023)
  val3 = map(val3, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  base.write(val3);                  // sets the servo position according to the scaled value
  delay(15);     
  

if(boton1==HIGH){
  delay(10);
  valorbase[posicion]=val3;
  valorbrazo[posicion]=val2;
  posicion++;
}

if(boton2==HIGH){
  for(int x=0;x<20;x++){
    base.write(valorbase[x]);
  }
}
}
