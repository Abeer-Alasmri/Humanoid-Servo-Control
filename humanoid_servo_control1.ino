#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

unsigned long startTime;
const int sweepDuration = 2000; // المدة: 2 ثانية

void setup() {
  servo1.attach(3);   // سلك الإشارة رايح لـ D3
  servo2.attach(5);   // D5
  servo3.attach(6);   // D6
  servo4.attach(9);   // D9
  servo5.attach(10);  // D10
  servo6.attach(11);  // D11

  startTime = millis(); // نحفظ وقت بدء التشغيل
}

void loop() {
  // نشيك إذا مضى أقل من ثانيتين
  if (millis() - startTime < sweepDuration) {
    for (int pos = 0; pos <= 180; pos += 5) {
      moveAllServos(pos);
      delay(15);
    }
    for (int pos = 180; pos >= 0; pos -= 5) {
      moveAllServos(pos);
      delay(15);
    }
  } else {
    // نثبت جميع السيرفوات عند 90 درجة
    moveAllServos(90);
    while (true); // نوقف التكرار بعد التثبيت
  }
}

void moveAllServos(int angle) {
  servo1.write(angle);
  servo2.write(angle);
  servo3.write(angle);
  servo4.write(angle);
  servo5.write(angle);
  servo6.write(angle);
}
