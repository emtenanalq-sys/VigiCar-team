// ============================
// VigiCar — MVP System
// Motion + Temperature + GPS
// ============================

// ---- Pins ----
int pirPin = 2; // PIR output → D2
int tempPin = A0; // TMP36 output → A0

// ---- GPS Simulation ----
float latitude = 24.7136; // Riyadh (example)
float longitude = 46.6753;

void setup() {
Serial.begin(9600);

pinMode(pirPin, INPUT);

Serial.println("VigiCar System Starting...");
delay(1000);
}

void loop() {

// ====== 1) Motion Detection ======
int motion = digitalRead(pirPin);

if (motion == HIGH) {
Serial.println("Motion Detected!");
Serial.println("Action Required!");
}

// ====== 2) Temperature Reading ======
int sensorValue = analogRead(tempPin);
float voltage = sensorValue * (5.0 / 1023.0);
float temperatureC = (voltage - 0.5) * 100.0;

Serial.print("Temperature: ");
Serial.print(temperatureC);
Serial.println(" °C");

if (temperatureC > 35) {
Serial.println("🔥 WARNING: High Temperature Detected!");
}

// ====== 3) Print GPS ALWAYS ======
Serial.print("Location: Lat: ");
Serial.print(latitude, 4);
Serial.print(" , Lon: ");
Serial.println(longitude, 4);

Serial.println("----------------------------");

// Simulate movement (optional)
latitude += 0.0001;
longitude += 0.0001;

delay(1000);
}
