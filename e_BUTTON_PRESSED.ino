void button_pressed()
{
  if(digitalRead(botao_1) == HIGH)
  {
    btn_pressed[0] = true;
    btn_pressed[1] = false;
    btn_pressed[2] = false;
    lcd.clear();
  }
  else if(digitalRead(botao_2) == HIGH)
  {
    btn_pressed[1] = true;
    btn_pressed[0] = false;
    btn_pressed[2] = false;
    lcd.clear();
  }
  else if(digitalRead(botao_3) == HIGH)
  {
    btn_pressed[1] = false;
    btn_pressed[0] = false;
    btn_pressed[2] = true;
    lcd.clear();
  }

  if(btn_pressed[0] == true)
  {
    comando = 2;
  }
  else if(btn_pressed[1] == true)
  {
    comando = 4;
  }
  else if(btn_pressed[2] == true)
  {
    comando = 3;
  }
}

