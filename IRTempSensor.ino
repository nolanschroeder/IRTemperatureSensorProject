#include <Wire.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

#define MLX90614_ADDR 0x5A // I2C address of MLX90614

int elapsedTime = 0;
// Function to update the emissivity to 0.96 for human skin
/*
void updateEmissivity(float emissivity) {
  uint16_t newValue = 0xFFFF - (emissivity * 65535); // Calculate EEPROM value
  
  // Write 0x0000 to address 0x04 to erase the EEPROM cell
  Wire.beginTransmission(MLX90614_ADDR);
  Wire.write(0x24);
  Wire.write(0x00);
  Wire.write(0x00);
  Wire.endTransmission();
  delay(100);

  // Write the new emissivity value to address 0x04
  Wire.beginTransmission(MLX90614_ADDR);
  Wire.write(0x24);
  Wire.write(newValue & 0xFF);          // Lower byte
  Wire.write((newValue >> 8) & 0xFF);   // Upper byte
  Wire.endTransmission();
  delay(100);

  Serial.print("Emissivity updated to: ");
  Serial.println(emissivity);
} */

void setup() {
  Serial.begin(9600);
  Serial.println("Human Body Temperature Monitor");

  Wire.begin();

  if (!mlx.begin()) {
    Serial.println("Error initializing MLX90614.");
    while (1);
  }
  // Update emissivity to 0.96 (optimal for human skin)
  //updateEmissivity(0.96);
}

void loop() {
  //float ambientTemp = mlx.readAmbientTempC();
  float objectTemp = mlx.readObjectTempC();

  Serial.print("At time = ");
  Serial.print(elapsedTime);
  Serial.print(" seconds, the calibrated Object temperature is: ");
  Serial.print(objectTemp + 1.0);
  Serial.println(" °C");

  elapsedTime += 1;
  // Delay for 1 second before taking another reading
  delay(1000);

}
