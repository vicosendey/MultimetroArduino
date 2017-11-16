void calculaCorrente(){
  double valorAnalogico = analogRead(portaAmperimetro);
  double valorConvertido = (valorAnalogico*vref)/1023;

  double tensaoPortaAnalogica = valorConvertido;

  corrente = (tensaoPortaAnalogica/10)*1.1;

  Serial.println("A500" + String(corrente*1000) + "mA");
  lcd.setCursor(3,1);
  lcd.print(String(corrente*1000) + "mA");
}
