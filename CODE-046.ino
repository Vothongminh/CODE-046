const int stepPin = 5; //clk+
const int dirPin = 2;//cw+
const int enPin = 8;//en+
int button = 7;
int voltage;
//.......................................................................................
void setup() {
  Serial.begin(9600);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enPin, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  digitalWrite(enPin, LOW);
}
//.......................................................................................
void loop()
{
  //Serial.println(digitalRead(button));
  int value = analogRead(A0);   //đọc giá trị điện áp ở chân A0
  //(value luôn nằm trong khoảng 0-1023)
  //Serial.println(value);        //xuất ra giá trị vừa đọc
  voltage = map(value, 0, 1023, 250, 3000); //chuyển thang đo của value
  //từ 0-1023 sang 300-5000
  //Serial.println(voltage);
  if (digitalRead(button) == 0)
  {
    //Serial.println("thuan");
    thuan();
  }
  else if (digitalRead(button) == 1)
  {
    //Serial.println("nghich");
    nghich();
  }
}

void thuan()
{
  digitalWrite(dirPin, HIGH);
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(voltage);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(voltage);
}
void nghich()
{
  digitalWrite(dirPin, LOW);
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(voltage);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(voltage);
}
