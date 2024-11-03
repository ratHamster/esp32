#include <Stepper.h>

const int stepsPerRevolution = 2048;// Tất cả các bước để quay hết một vòng, cứ 1 bước là quay được khoảng 2048/360 độ
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);//Khai báo kết nối dây Arduino và động cơ bước
const int sensorPin = 7; // Chân 7 của Arduino kết nối với chân D0 cảm biến dò line
int sensorValue = 0;// được sử dụng để lưu trữ giá trị đọc từ cảm biến và giá trị ban đầu của nó được đặt là 0 để đảm bảo rằng nó không chứa bất kỳ giá trị nào trước khi được gán giá trị thực tế từ cảm biến.

void setup() {
  myStepper.setSpeed(15);// Đặt tốc độ của động cơ là 15 vòng/phút
    pinMode(sensorPin, INPUT);
  Serial.begin(9600); // Khởi tạo kết nối Serial
}

void loop() {
  sensorValue = digitalRead(sensorPin);

  // In giá trị cảm biến ra Serial Monitor
  Serial.println(sensorValue);

  // Nếu line sáng, quay 90 độ
  if (sensorValue > 0) {
    myStepper.step(512);
    delay(1000);
    myStepper.step(0); // Dừng động cơ
    delay(1000);
  }

  // Nếu line tối, quay 45 độ
  else {
    myStepper.step(256);
    delay(1000);
    myStepper.step(0); // Dừng động cơ
    delay(1000);
  }
}
