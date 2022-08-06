#define SECONDS 2.0

int count = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("Zero Cross Test");

  attachInterrupt(0, cross, RISING);
}

void loop()
{
  delay(SECONDS * 1000);

  noInterrupts();
  float hz = count / SECONDS / 2;
  count = 0;
  interrupts();

  Serial.print(hz);
  Serial.println("Hz");
}

void cross() {
  count++;
}
