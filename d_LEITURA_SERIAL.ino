void leitura_serial()
{
  
  if(Serial.available())
  {
    
    while(Serial.available())
    {
      comando += char(Serial.read());
      
      delay(10);
    }
    
    lcd.clear();
    
  }
  
}


