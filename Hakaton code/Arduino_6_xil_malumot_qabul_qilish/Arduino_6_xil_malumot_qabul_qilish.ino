 #include <SoftwareSerial.h>

SoftwareSerial bluetooth(2, 3); // Bluetooth modülünü Arduino'nun 2. ve 3. pinlerine bağlayın

void setup() {
  Serial.begin(9600); // Seri iletişimi başlat
  bluetooth.begin(9600); // Bluetooth iletişimini başlat
}

void loop() {
  if (bluetooth.available()) { // Bluetooth modülünden veri var mı kontrol et
    String receivedChar = bluetooth.readString(); // Veriyi oku
  
    Serial.println(receivedChar);
  }
}