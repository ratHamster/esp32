int const VRx_pin = A0;// khai bao chan 
int const VRy_pin = A1;

int button = 2; // khai bao chan nut nhan 
int VRx , VRy,sw;

void setup(){
    Serial.begin(9600);
}

void loop(){
  VRx = analogRead(VRx_pin);
  VRy = analogRead(VRy_pin);
  sw = digitalRead(button);

// Print the coordinate and Press Value
    Serial.print("x : " ); Serial.print(VRx); Serial.print(",");
    Serial.print("Y : " ); Serial.print(VRy); Serial.print(",");
    Serial.print("KEY: "); Serial.print(sw);
    Serial.println();
    




}