#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#include <DHT.h>

/* ---------- WIFI DETAILS ---------- */
#define WIFI_SSID "YOUR_WIFI_NAME"
#define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"

/* ---------- FIREBASE DETAILS ---------- */
#define FIREBASE_HOST "your-project.firebaseio.com"
#define FIREBASE_AUTH "YOUR_FIREBASE_DATABASE_SECRET"

/* ---------- PIN DEFINITIONS ---------- */
#define HEATER_RELAY D1
#define DRAFT_FAN    D2
#define TOP_FAN      D3

#define DHTPIN D4
#define DHTTYPE DHT11   // or DHT22

#define PT100_PIN A0    // Analog PT100 module

/* ---------- OBJECTS ---------- */
FirebaseData fbdo;
DHT dht(DHTPIN, DHTTYPE);

/* ---------- VARIABLES ---------- */
float currentTemp = 0;
float humidity = 0;
float setTemp = 0;
float humidityLimit = 70;

void setup() {
  Serial.begin(9600);

  pinMode(HEATER_RELAY, OUTPUT);
  pinMode(DRAFT_FAN, OUTPUT);
  pinMode(TOP_FAN, OUTPUT);

  digitalWrite(HEATER_RELAY, HIGH);
  digitalWrite(DRAFT_FAN, HIGH);
  digitalWrite(TOP_FAN, HIGH);

  dht.begin();

  /* ---------- WIFI ---------- */
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected");

  /* ---------- FIREBASE ---------- */
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  Serial.println("System Ready");
}

void loop() {

  /* ---------- READ SENSORS ---------- */
  int pt100Value = analogRead(PT100_PIN);
  currentTemp = map(pt100Value, 0, 1023, 0, 100); // Approximation
  humidity = dht.readHumidity();

  Serial.print("Temp: ");
  Serial.print(currentTemp);
  Serial.print(" °C | Humidity: ");
  Serial.println(humidity);

  /* ---------- READ FIREBASE ---------- */
  if (Firebase.getFloat(fbdo, "/curing/setTemp")) {
    setTemp = fbdo.floatData();
  }

  if (Firebase.getFloat(fbdo, "/curing/humidityLimit")) {
    humidityLimit = fbdo.floatData();
  }

  /* ---------- TEMPERATURE CONTROL ---------- */
  if (currentTemp < setTemp) {
    digitalWrite(HEATER_RELAY, LOW);   // Heater ON
    digitalWrite(DRAFT_FAN, LOW);      // Draft Fan ON
  } else {
    digitalWrite(HEATER_RELAY, HIGH);  // Heater OFF
    digitalWrite(DRAFT_FAN, HIGH);     // Draft Fan OFF
  }

  /* ---------- HUMIDITY CONTROL ---------- */
  if (humidity > humidityLimit) {
    digitalWrite(TOP_FAN, LOW);        // Exhaust Fan ON
  } else {
    digitalWrite(TOP_FAN, HIGH);       // Exhaust Fan OFF
  }

  delay(2000);
}
