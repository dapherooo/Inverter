#include <TimerOne.h>

#define PWM1 11
#define PWM2 12
#define PWM3 10
#define PWM4 9

int feedback;

void setup() {
  Timer1.initialize(50);  // 50uS
  Timer1.attachInterrupt(invPWM);

  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);
  pinMode(PWM3, OUTPUT);
  pinMode(PWM4, OUTPUT);
}

void loop() {
  //feedback = analogRead(A0);
  //feedback = map(feedback, 0, 1024, 20, 190);
}

void invPWM() {
  static int count;

  if (count <= 200) {
    if (count < 10) {
      digitalWrite(PWM1, 1);
      digitalWrite(PWM3, 0);
    }
    else {
      digitalWrite(PWM1, 0);
      digitalWrite(PWM3, 1);
    }
  }
  else if (count > 200) {
    if (count < 200 + 10) {
      digitalWrite(PWM2, 1);
      digitalWrite(PWM4, 0);
    }
    else {
      digitalWrite(PWM2, 0);
      digitalWrite(PWM4, 1);
    }
  }

  count++;
  if (count == 400) count = 0;
}
