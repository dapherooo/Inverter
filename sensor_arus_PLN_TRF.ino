#include <PZEM004Tv30.h>
PZEM004Tv30 pzem(11, 12);

void setup() {
  Serial.begin(115200);
}

void loop() {
    float current = pzem.current();
    if( !isnan(current) ){
        Serial.print("Arus PLN: "); Serial.print(current); Serial.println("A");
    } else {
        Serial.println("Error reading current");
    }
    int average = 0;
for(int i = 0; i < 1000; i++) {
average = average + (0.0264 * analogRead(A0)-13.51);
delay(1);
}
Serial.print("Arus TRF: ");
Serial.print(average/1000);
Serial.println("A     ");

    Serial.println();
    delay(2000);
}
