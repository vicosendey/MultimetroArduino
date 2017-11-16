void calculaTensao(){
  
  int nivel = 0;
  
  double valorAnalogico = analogRead(portaVoltimetro);
  double valorConvertido = (valorAnalogico*vref)/1023;
  double tensaoEscala50V = 0, tensaoEscala20V = 0, tensaoEscala5V = 0;

  if(digitalRead(controleEscalaVolt[0]) == HIGH)
  {
    nivel = 1;
    tensaoEscala5V  = valorConvertido ;
  }
  else if(digitalRead(controleEscalaVolt[1]) == HIGH)
  {
    nivel = 2;
    tensaoEscala20V = valorConvertido*3.92;
  }

  if(tensaoEscala5V >= 4.7)
  {
    digitalWrite(controleEscalaVolt[0], LOW);
    digitalWrite(controleEscalaVolt[1], HIGH);
  }
  
  if(nivel == 1)
  {
    lcd.clear();
    Serial.print("V005");
    Serial.print(String(tensaoEscala5V));
    Serial.println("V");
    lcd.setCursor(3,1);
    lcd.print(tensaoEscala5V);
    lcd.print("V"); 
  }
  else if(nivel == 2)
  {
    lcd.clear();
    Serial.print("V020");
    Serial.print(String(tensaoEscala20V));
    Serial.println("V");
    lcd.setCursor(3,1);
    lcd.print(tensaoEscala20V);
    lcd.print("V"); 
    if(tensaoEscala20V < 4.7)
    {
      digitalWrite(controleEscalaVolt[0], HIGH);
      digitalWrite(controleEscalaVolt[1], LOW);
    }
  }
  else if(nivel ==3)
  {
    lcd.clear();
    Serial.print("V050");
    Serial.print(String(tensaoEscala50V));
    Serial.println("V");
    lcd.setCursor(3,1);
    lcd.print(tensaoEscala50V);
    lcd.print("V"); 
  }
  
}

