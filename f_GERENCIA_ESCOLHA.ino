void gerencia_escolha()
{
  escolha = comando.toInt();

  if(escolha == 1)
  {
    comando = "";
    Serial.println("OFF");
    lcd.print("OFF"); 
  }
  else if(escolha == 2)
  {
    comando = "";
    lcd.setCursor(3,0);
    lcd.print("Voltimetro");
    tempoAtual = millis();
    if((tempoAtual - tempoAnterior) >= 500)
    {
      calculaTensao();
      tempoAnterior = tempoAtual;
    }
  }
  else if(escolha == 3)
  {
    comando = "";
    lcd.setCursor(2, 0);
    lcd.print("Amperimetro");
    tempoAtual = millis();
    if((tempoAtual - tempoAnterior) >= 1000)
    {
      lcd.clear();
      calculaCorrente();
      tempoAnterior = tempoAtual;
    }
  }
  else if(escolha == 4)
  {
    comando = "";
    lcd.setCursor(3, 0);
    lcd.print("Ohmimetro");
    tempoAtual = millis();
    if((tempoAtual - tempoAnterior) >= 1000)
    {
      lcd.clear();
      calculaResistencia();
      tempoAnterior = tempoAtual;
    }
  }
}

