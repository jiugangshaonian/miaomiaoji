#include <Arduino.h>
#include <BluetoothSerial.h>

// put function declarations here:
BluetoothSerial SerialBT;
bool lastConn = false;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("汪汪机");
  Serial.println("\n[ESP32] 等待手机连接...");
}

void loop() {
  // put your main code here, to run repeatedly:
  bool conn = SerialBT.hasClient();
  if ( conn && !lastConn) Serial.println("[ESP32] 手机已连接");
  if (!conn &&  lastConn) Serial.println("[ESP32] 手机已断开");
  lastConn = conn;

  if(SerialBT.available())
  {
    Serial.write(SerialBT.read());
    SerialBT.print("汪~汪~汪~");
  }
  if(Serial.available())
  {
    SerialBT.write(Serial.read());
    SerialBT.print("喵~喵~喵~");
  }

  delay(5);
}

// put function definitions here:
