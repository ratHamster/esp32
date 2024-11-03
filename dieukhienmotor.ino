#include <Stepper.h>

const int stepsPerRevolution = 2048; // Số bước 1 vòng quay đối với động cơ bước 28BYJ-48 nên 1 bước quay là 2048/360 độ

Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11); // Cài đặt động cơ bước và cấu hình chân cắm.
//Stepper myStepper1 = Stepper(stepsPerRevolution, 10, 8, 9, 11);

void setup() {
 
    myStepper.setSpeed(15); // Tốc độ quay khai báo 1-19 Ngoài phạm vi này motor không chạy
    Serial.begin(9600); // Khởi tạo kết nối Serial

}

void loop() 
{
  
  myStepper.step(512);// muốn quay được 90 thuận thì ta lấy 90 nhân với 2048/360 ra 512 chính là số bước cần quay để động cơ quay 90 độ
  delay(1000);

  myStepper.step(-512); // tương tự như quay 90 độ thuận nhưng ta thêm dấu trừ chính là quay nghịch

  delay(1000);

}
