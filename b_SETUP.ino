void setup() {
  
  Serial.begin(9600);
  
  lcd.begin (16,2);
  
  lcd.setBacklight(HIGH);
  
  lcd.setCursor(3,0);
  
  lcd.write("Multimetro");
  
  pinMode(botao_1, INPUT);
  
  pinMode(botao_2, INPUT);
  
  pinMode(botao_3, INPUT);

  digitalWrite(botao_1, LOW);

  digitalWrite(botao_2, LOW);

  digitalWrite(botao_3, LOW);

  tempoAtual = millis();

  //---------------Voltimetro--------------
  Serial.setTimeout(10);
  pinMode(controleEscalaVolt[0], OUTPUT);
  pinMode(controleEscalaVolt[1], OUTPUT);
  pinMode(controleEscalaVolt[2], OUTPUT);
  digitalWrite(controleEscalaVolt[0], LOW);
  digitalWrite(controleEscalaVolt[1], HIGH);
  digitalWrite(controleEscalaVolt[2], LOW);
  //----------------------------------------
  
  //---------------Ohmimetro-----------
  pinMode(controleEscala[0], OUTPUT);
  pinMode(controleEscala[1], OUTPUT);
  pinMode(controleEscala[2], OUTPUT);
  digitalWrite(controleEscala[0], HIGH);
  digitalWrite(controleEscala[1], LOW);
  digitalWrite(controleEscala[2], LOW);
  //-------------------------------------
  
}
