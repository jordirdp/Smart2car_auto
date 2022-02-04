
/* Project: Smart2car */
/* Author: Jordi Rodriguez */

#include "Pinout.h"
#include "Constants.h"

#include <NewPing.h>
NewPing sonar (TRIGGER_PIN, ECHO_PIN);

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27, 20, 4);


void setup() {
  lcd.init();
  lcd.clear();
  lcd.setCursor (0,0);
  lcd.print("****Smart2car****");
  
  Buzzer_init();
  Buzzer(2,100,100);

  Led_init(WHITE_R);
  Led_init(WHITE_L);
  Led_init(RED_R);
  Led_init(RED_L);
  for (byte i=0; i<3; i++){
    Led_wheel();
  }

  pinMode(SENSOR_L, INPUT);
  pinMode(SENSOR_R, INPUT);

  Motores_init();

  lcd.clear();
  lcd.setCursor (0,0);
}


void loop() {
  Lectura_sensores();
  Luces();
  Distancia();
  Linea();
}


void Lectura_sensores() {
  Sensor_left_old = Sensor_left;
  Sensor_right_old = Sensor_right;
  
  Sensor_left = digitalRead(SENSOR_L);
  Sensor_right = digitalRead(SENSOR_R);

  Sensor_front = sonar.ping_cm();

  Sensor_luz = digitalRead(FOTOSENSOR);
}

void Luces() {
  /* Enciende luces en la oscuridad */
  if (Sensor_luz == HIGH){
    LightOn(WHITE_R);
    LightOn(WHITE_L);
    LightOn(RED_R);
    LightOn(RED_L);
  }
  else {
    LightOff(WHITE_R);
    LightOff(WHITE_L);
    LightOff(RED_R);
    LightOff(RED_L);    
  }
}

void Distancia() {

  while (Sensor_front<=STOP_DISTANCE){
    Para(100);
    Sensor_front = sonar.ping_cm();
    
    /* Retrocede si tiene un obstáculo cerca */
    if (Sensor_front<=ATRAS_DISTANCE) {
      lcd.print("******Atras******");
      Retrocede();
      Buzzer(1,500,500);
    }
  
    /* Se mantiene parado si tiene un obstáculo delante */
    else {
      
      lcd.print("******Stop*******");
      Stop();
      Buzzer(1,100,1000);
    }
  }
}

void Linea() {
  /* Decisiones de movimiento en función de los sensores de línea */
  if (Sensor_left == 1 && Sensor_right == 1){
    Avanza();
    lcd.print("*****Avanza******");
    
  }
  if (Sensor_left == 0 && Sensor_right == 1){
    Derecha();
    lcd.print("*****Derecha*****");
  }
  if (Sensor_left == 1 && Sensor_right == 0){
    Izquierda();
    lcd.print("****Izquierda****");
  }

  /* Si pierde la línea */ 
  if (Sensor_left == 0 && Sensor_right == 0){
    Para(100);
    Led_wheel();
    lcd.print("******Stop*******");
    if (Sensor_left_old == 1 && Sensor_right_old == 0){
      lcd.print("**Buscando izq.**");
      Gira_izquierda();
      Avanza();
    }
    if (Sensor_left_old == 0 && Sensor_right_old == 1){
      lcd.print("**Buscando der.**");
      Gira_derecha();
      Avanza();
    }   
  }
}
