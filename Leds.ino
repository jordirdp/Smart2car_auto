
/* Project: Smart2car */
/* Author: Jordi Rodriguez */

void Led_init (uint8_t LED_PIN){
  pinMode (LED_PIN, OUTPUT);
  digitalWrite (LED_PIN, LOW);
}

void LightOn (uint8_t LED_PIN){
  digitalWrite (LED_PIN, HIGH);
}

void LightOff (uint8_t LED_PIN){
  digitalWrite (LED_PIN, LOW);
}

void Parpadeo (uint8_t LED_PIN){
  LightOn (LED_PIN);
  delay(200);
  LightOff (LED_PIN);  
}

void Led_wheel (){
  Parpadeo (WHITE_R);
  Parpadeo (WHITE_L);
  Parpadeo (RED_R);
  Parpadeo (RED_L);
}
