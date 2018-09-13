void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int valor = analogRead(A0);
  int valorSalida = valor/4;
  analogWrite(3, valorSalida);
}
