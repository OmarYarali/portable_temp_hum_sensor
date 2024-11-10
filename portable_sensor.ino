#include <LiquidCrystal.h>
#include <DHT.h>

// Initialize LCD screen with the pin numbers for RS, E, D4, D5, D6, and D7
LiquidCrystal lcd(4, 5, 6, 7, 8, 9);

// Define DHT sensor type and pin
#define DHTTYPE DHT11
#define DHTPIN 11

// Define LED pin for error indication
#define LED_PIN 13

// Create DHT sensor object
DHT dht(DHTPIN, DHTTYPE);

// Variables for storing temperature and humidity values
float humidity = 0;
float temperature = 0;
float lastHumidity = 0;
float lastTemperature = 0;

// Flag to indicate sensor read status
int errorFlag = 0;


// Display temperature and humidity on the LCD
 
void displayReadings(float temp, float hum) {
   lcd.setCursor(0, 0);
   lcd.print("Temp: ");
   lcd.print(temp);
   lcd.print(" C");
 
   lcd.setCursor(0, 1);
   lcd.print("Humidity: ");
   lcd.print((int)hum);
   lcd.print("%");

}

void setup() {
  // Initialize LCD and Serial communication
  lcd.begin(16, 2);
  Serial.begin(9600);
  
  // Start DHT sensor
  dht.begin();
  delay(500);
  
  // Set LED pin as output
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Read humidity and temperature from DHT sensor
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();

  // Check if readings are valid
  if (isnan(humidity) || isnan(temperature)) {
    if (errorFlag == 0) {
      // Clear LCD and display error message
      lcd.clear();
      lcd.print("Failed to Read!");
      
      // Turn on LED to indicate error
      digitalWrite(LED_PIN, HIGH);
      errorFlag = 1;
    }
    return; // Exit loop if reading failed
  }

  // Reset error indication if readings are successful
  if (errorFlag) {
    lcd.clear();
    digitalWrite(LED_PIN, LOW);
    displayReadings(temperature, humidity);
    errorFlag = 0;
  }

  // Update display if there is a change in temperature or humidity
  if ((temperature != lastTemperature) || (humidity != lastHumidity)) {
    displayReadings(temperature, humidity);
  }

  // Update last recorded values
  lastTemperature = temperature;
  lastHumidity = humidity;
}
