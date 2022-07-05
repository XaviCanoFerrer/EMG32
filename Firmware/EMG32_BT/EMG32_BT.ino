/*
  ----------------------------------------------------------------------------
  This file is part of the EMG32 repository
  Written by Xavier Cano-Ferrer
  ----------------------------------------------------------------------------
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, version 3.
  This program is distributed  WITHOUT ANY WARRANTY and without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU General Public License for more details.
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <Adafruit_ADS1X15.h>
#include "BluetoothSerial.h"


Adafruit_ADS1015 ads;     /* Use this for the 12-bit ADC version */
BluetoothSerial SerialBT;

const int LED_pin = 2;
const int button_pin = 33;
bool state = 1;
bool parallax = false; // True if you want to acquire with Parallax PLX-DAQ
int16_t ch1, ch2;
float volts1, volts2;

void setup(void) 
{
  SerialBT.begin("WirelessEOG");
  
  pinMode(LED_pin, OUTPUT);
  pinMode(button_pin, INPUT_PULLUP);

  digitalWrite(LED_pin, state);

  // The Interrupt calls the function _mode
  attachInterrupt(digitalPinToInterrupt(button_pin), _mode, FALLING);
  
  // The ADC input range (or gain) can be changed via the following
  // functions, but be careful never to exceed VDD +0.3V max, or to
  // exceed the upper and lower limits if you adjust the input range!
  // Setting these values incorrectly may destroy your ADC!
  //                                                                ADS1015  ADS1115
  //                                                                -------  -------
   //ads.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)
   ads.setGain(GAIN_ONE);        // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV
  // ads.setGain(GAIN_TWO);        // 2x gain   +/- 2.048V  1 bit = 1mV      0.0625mV
  // ads.setGain(GAIN_FOUR);       // 4x gain   +/- 1.024V  1 bit = 0.5mV    0.03125mV
  // ads.setGain(GAIN_EIGHT);      // 8x gain   +/- 0.512V  1 bit = 0.25mV   0.015625mV
  // ads.setGain(GAIN_SIXTEEN);    // 16x gain  +/- 0.256V  1 bit = 0.125mV  0.0078125mV
  
  Wire.setClock(400000);
  ads.setDataRate(RATE_ADS1015_3300SPS); // Fastes sampling rate possible on the ADC
  ads.begin();

  //delay(1000);

}

void loop(void) 
{
  ch1 = ads.readADC_SingleEnded(2);
  ch2 = ads.readADC_SingleEnded(1);
  volts1 = ads.computeVolts(ch1);
  volts2 = ads.computeVolts(ch2);
  SerialBT.print(volts1);
  SerialBT.print("  ");
  SerialBT.println(volts2);
  //delay(2);
}

void _print()
{
  SerialBT.print(volts1);
  SerialBT.print("  "); 
  SerialBT.println(volts2);
}

void _mode()
{
  state = !state;
}
