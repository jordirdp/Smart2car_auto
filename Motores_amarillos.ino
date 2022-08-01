
/* Project: Smart2car */
/* Author: Jordi Rodriguez */

void Motores_init(){
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
}

void Para (int tiempo){
  analogWrite (ENA, 0);
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW);
  analogWrite (ENB, 0);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW);
  delay (tiempo);
}

void Stop (){
  analogWrite (ENA, 0);
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW);
  analogWrite (ENB, 0);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW);
}

void Avanza(){
  analogWrite (ENA, Velocidad);
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite (ENB, Velocidad);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
}

void Retrocede(){
  analogWrite (ENA, Velocidad/2);
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite (ENB, Velocidad/2);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  Buzzer (1, 100, 100);
}

void Izquierda(){
  analogWrite (ENA, Velocidad);
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite (ENB, 0);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
}

void Derecha(){
  analogWrite (ENA, Velocidad);
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite (ENB, 0);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
}

void Gira_izquierda(){
  analogWrite (ENA, Velocidad/2);
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite (ENB, Velocidad/2);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
}

void Gira_derecha(){
  analogWrite (ENA, Velocidad/2);
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite (ENB, Velocidad/2);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
}
