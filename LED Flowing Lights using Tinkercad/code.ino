// C++ code

int ledPin=11;
void setup()
{
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  
  for(int a=0;a<=255;a++)
  {
    analogWrite(ledPin,a);
    delay(20);
  }
   for(int a=255;a>=0;a++)
   {
   analogWrite(ledPin,a);
      delay(20);
   }
  delay(200);
}
