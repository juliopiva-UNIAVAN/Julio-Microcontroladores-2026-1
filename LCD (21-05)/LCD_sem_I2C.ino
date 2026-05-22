#define RS 12
#define EN 11

#define D4 5
#define D5 4
#define D6 3
#define D7 2

void pulseEnable()
{
  digitalWrite(EN, LOW);
  delayMicroseconds(1);

  digitalWrite(EN, HIGH);
  delayMicroseconds(1);

  digitalWrite(EN, LOW);

  delayMicroseconds(100);
}

void sendNibble(byte data)
{
  digitalWrite(D4, bitRead(data,0));
  digitalWrite(D5, bitRead(data,1));
  digitalWrite(D6, bitRead(data,2));
  digitalWrite(D7, bitRead(data,3));

  pulseEnable();
}

void sendByte(byte data, bool rs)
{
  digitalWrite(RS, rs);

  // envia parte alta
  sendNibble(data >> 4);

  // envia parte baixa
  sendNibble(data & 0x0F);

  delay(2);
}

void setup()
{
  pinMode(RS, OUTPUT);
  pinMode(EN, OUTPUT);

  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);

  delay(50);

  // Inicialização LCD
  sendNibble(0x03);
  delay(5);

  sendNibble(0x03);
  delay(5);

  sendNibble(0x03);
  delay(5);

  sendNibble(0x02);

  // Configura display 4 bits, 2 linhas
  sendByte(0x28, LOW);

  // Liga display sem cursor
  sendByte(0x0C, LOW);

  // Incrementa cursor
  sendByte(0x06, LOW);

  // Limpa display
  sendByte(0x01, LOW);

  delay(5);

  // Escreve JULIO
  sendByte('J', HIGH);
  sendByte('U', HIGH);
  sendByte('L', HIGH);
  sendByte('I', HIGH);
  sendByte('O', HIGH);
}

void loop()
{

}