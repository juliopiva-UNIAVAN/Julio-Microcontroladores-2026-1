#include <Wire.h>

#define PCF8574_ADDR 0x20

byte dataLCD = 0;

// ----------------------------

void writePCF(byte data)
{
  Wire.beginTransmission(PCF8574_ADDR);

  Wire.write(data);

  Wire.endTransmission();
}

// ----------------------------

void pulseEnable()
{
  bitSet(dataLCD, 5);

  writePCF(dataLCD);

  delayMicroseconds(1);

  bitClear(dataLCD, 5);

  writePCF(dataLCD);

  delayMicroseconds(100);
}

// ----------------------------

void sendNibble(byte nibble)
{
  // limpa P0-P3
  dataLCD &= 0xF0;

  // coloca nibble em P0-P3
  dataLCD |= (nibble & 0x0F);

  writePCF(dataLCD);

  pulseEnable();
}

// ----------------------------

void sendByte(byte value, bool rs)
{
  bitWrite(dataLCD, 4, rs);

  sendNibble(value >> 4);

  sendNibble(value & 0x0F);

  delay(2);
}

// ----------------------------

void command(byte value)
{
  sendByte(value, LOW);
}

// ----------------------------

void writeChar(char value)
{
  sendByte(value, HIGH);
}

// ----------------------------

void setup()
{
  Wire.begin();

  delay(50);

  sendNibble(0x03);
  delay(5);

  sendNibble(0x03);
  delay(5);

  sendNibble(0x03);
  delay(5);

  sendNibble(0x02);
  delay(5);

  command(0x28);

  command(0x0C);

  command(0x06);

  command(0x01);

  delay(5);

  writeChar('J');
  writeChar('U');
  writeChar('L');
  writeChar('I');
  writeChar('O');
}

void loop()
{

}