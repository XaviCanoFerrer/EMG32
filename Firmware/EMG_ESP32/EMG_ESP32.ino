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

Adafruit_ADS1015 ads;     /* Use this for the 12-bit ADC version */

const int LED_pin = 2;
const int button_pin = 33;
bool state = 1;
bool parallax = false; // True if you want to acquire with Parallax PLX-DAQ
int16_t ch1, ch2;
float volts1, volts2;

void setup(void) 
{
  //Serial.begin(256000); // Fastest Baud rate for Parallax PLX-DAQ
  Serial.begin(2000000);
  //To transmit in Parallax PLX-DAQ
  Serial.println("CLEARDATA");
  Serial.println("LABEL,Realtime,EMG_ch1, EMG_ch2,Time(ms)");

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
  digitalWrite(LED_pin, state);
  
  // unsigned long start = micros();
  if (state == 1)
  {
    // Read the two ADC channels
    ch2 = ads.readADC_SingleEnded(1);
    ch1 = ads.readADC_SingleEnded(2);

    // Convert the 12 bit data into volts
    volts1 = ads.computeVolts(ch1);
    volts2 = ads.computeVolts(ch2);

    if (parallax == true)
    {
      //To transmit in Parallax PLX-DAQ
      Serial_Parallax_PLX_DAQ();
    }
    else 
    {
      //Regular serial print
      _print();
    }
  }
  if (state == 0)
  {
    // Read only channel 1
    ch1 = ads.readADC_SingleEnded(2);

    // Convert the 12 bit data into volts
    volts1 = ads.computeVolts(ch1);

    if (parallax == true)
    {
      //To transmit in Parallax PLX-DAQ
      Serial_Parallax_PLX_DAQ_1ch();
    }
    else 
    {
      //Regular serial print
      _print_1ch();
    }
  }
}

void Serial_Parallax_PLX_DAQ()
{
  Serial.print("DATA,TIME,");
  Serial.print(volts1);
  Serial.print(","); 
  Serial.print(volts2);
  Serial.print(","); 
  Serial.println(millis());
}

void Serial_Parallax_PLX_DAQ_1ch()
{
  Serial.print("DATA,TIME,");
  Serial.print(volts1);
  Serial.print(","); 
  Serial.println(millis());
}

void _print()
{
  Serial.print(volts1);
  Serial.print(" "); 
  Serial.print(volts2);
  Serial.print(" "); 
  Serial.println(millis());
}

void _print_1ch()
{
  Serial.print(volts1);
  Serial.print(" "); 
  Serial.println(millis());
}

void _mode()
{
  state = !state;
}
