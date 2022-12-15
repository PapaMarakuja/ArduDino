#include <Servo.h>
int pinoSensorLuzPula = A0;
int valorLuzPula = 0;
int pinoSensorLuzAbaixar = A1;
int valorLuzAbaixar = 0;
Servo servoPula;
Servo servoAbaixa;
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  valorLuzPula = analogRead(pinoSensorLuzPula);
  valorLuzAbaixar = analogRead(pinoSensorLuzAbaixar);
  Serial.print("Pula");
  Serial.println(valorLuzPula);
  Serial.print("Abaixa");
  Serial.println(valorLuzAbaixar);
  servoPula.attach(6);
  servoAbaixa.attach(7);

  if (valorLuzPula < 100)
  {
    for (int angulo = 30; angulo <= 70; angulo++)
    {
      servoPula.write(angulo);
      delay(1);
    }
    for (int angulo = 70; angulo >= 30; angulo--)
    {
      servoPula.write(angulo);
      delay(1);
    }
    delay(100);
  }

  if (valorLuzAbaixar < 100)
  {
    for (int angulo = 30; angulo <= 70; angulo++)
    {
      servoAbaixa.write(angulo);
      delay(1);
    }
    for (int angulo = 70; angulo >= 30; angulo--)
    {
      servoAbaixa.write(angulo);
      delay(1);
    }
    delay(100);
  }
}
