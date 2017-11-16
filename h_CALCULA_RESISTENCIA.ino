void calculaResistencia()
{
  int nivel = 0;
  double soma = 0;
  double valorAnalogico = 0;
    double valorConvertido = 0;
  for(int i = 0; i < 10; i++)
  {
    valorAnalogico = analogRead(portaOhmimetro);
    valorConvertido = (valorAnalogico*vref)/1023;
    soma = soma + valorConvertido;
  }

  double media = soma / 10;
  
  double resistenciaEscala2k = 0, resistenciaEscala100k = 0, resistenciaEscala10M = 0;

  if(digitalRead(controleEscala[0]) == HIGH)
  {
    nivel = 1;
    resistenciaEscala2k = ((vref*resistorRef[0])/media) - resistorRef[0];
  }
  else if(digitalRead(controleEscala[1]) == HIGH)
  {
    nivel = 2;
    resistenciaEscala100k = ((vref*resistorRef[1])/media) - resistorRef[1];
  }
  else if(digitalRead(controleEscala[2]) == HIGH)
  {
    nivel = 3;
    resistenciaEscala10M = ((vref*resistorRef[2])/media) - resistorRef[2];
  }
  
  if(resistenciaEscala2k >= 2500)
  {
    digitalWrite(controleEscala[0], LOW);
    digitalWrite(controleEscala[1], HIGH);
    digitalWrite(controleEscala[2], LOW);
  }
  else if(resistenciaEscala100k >= 101000)
  {
    digitalWrite(controleEscala[0], LOW);
    digitalWrite(controleEscala[1], LOW);
    digitalWrite(controleEscala[2], HIGH);
  }
  
  if(nivel == 1)
  {
    lcd.clear();
    Serial.println("O002" + String(resistenciaEscala2k) + "ohm");
    lcd.setCursor(3,1);
    lcd.print(String(resistenciaEscala2k));
    lcd.print(" ohm");
  }
  else if(nivel == 2)
  {
    lcd.clear();
    Serial.println("O100" + String(resistenciaEscala100k/1000) + "K ohm");
    lcd.setCursor(3,1);
    lcd.print(String(resistenciaEscala100k/1000) + "K");
    lcd.print(" ohm");
    if(resistenciaEscala100k <= 2500)
    {
      digitalWrite(controleEscala[0], HIGH);
      digitalWrite(controleEscala[1], LOW);
      digitalWrite(controleEscala[2], LOW);
    }
  }
  else if(nivel == 3)
  {
    lcd.clear();
    if(resistenciaEscala10M <= 100000)
    {
      digitalWrite(controleEscala[0], LOW);
      digitalWrite(controleEscala[1], HIGH);
      digitalWrite(controleEscala[2], LOW);
    }
    if(resistenciaEscala10M >= 11000000)
    {
      Serial.println("O010INF");
      lcd.setCursor(3,1);
      lcd.print("INF");
    }
    else
    {
      Serial.println("O010" + String(resistenciaEscala10M/1000000) + "M ohm");
      lcd.setCursor(3,1);
      lcd.print(String(resistenciaEscala10M/1000000) + "M");
      lcd.print(" ohm");
    }
  }
  
  
}
