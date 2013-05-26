// Pressure Sensor
// © 2013 Joshua Grosso

// Open the Serial Monitor in the Arduino editor to see the results

const int PRESSURE = 0;
const int BUTTON = 7;

int valPressure = 0;
int valButton = 0;
int preValPressure = 0;
int preValButton = 0;
int calibration = 0;

void setup()
{
  pinMode(PRESSURE, INPUT);
  pinMode(BUTTON, INPUT);
  Serial.begin(9600);
  valPressure = analogRead(PRESSURE);
  
  calibration = valPressure;
}

void loop()
{
  valPressure = analogRead(PRESSURE);
  valButton = digitalRead(BUTTON);
//  valButton = LOW;
  
  if (valButton == HIGH && preValButton == LOW)
  {
    calibration = valPressure;
    Serial.print("BUTTON\n");
    Serial.print(calibration);
    Serial.print("\n");
    Serial.print(valPressure);
    Serial.print("\n");
    delay(100);
  }
  
  preValButton = valButton;
  
  if (valPressure > calibration)
  {
    Serial.print("PERSON\n");
    Serial.print(valPressure);
    Serial.print("\n");
    delay(100);
  }
  
  preValPressure = valPressure;
}
