# BIO_ESP32

Two-channel EMG/EOG acquisition system

# Features:

Adjustable total gain 100-10000

Instrumentation amplifier (AD8226)

12 bit ADC (Texas instruments ADS1015)

First order high and low pass filters fc = 22 Hz and fc = 482 Hz

LiPo battery power management system (It can be charged from the USB port)

The sampling frequency using 3.3 KSPS setting on the ADC sampling rate and 3.4 MHz I2C clock the Fs are 1.4 kHz (1ch) 714 Hz (2ch).


# V1 has a couple of mistakes but it can be fuctional: 

The quad amplifier (LM324) has to be assembled with a 180 degree rotation if not it will be shorted.

The JAC connectors are not close enough to the edge and depensing on the length of your cable it won't go deep enough to make a good contact.

Both mistakes are solved in V2 but still not tested.

![alt text](https://github.com/XaviCanoFerrer/Wireless_EMG/blob/main/Wireless%20EMG%20.png?raw=true)

![alt text](https://github.com/XaviCanoFerrer/Open_wireless_EMG/blob/main/IMG_20220404_123702.jpg?raw=true)

![alt text](https://github.com/XaviCanoFerrer/Open_wireless_EMG/blob/main/IMG_20220404_123524.jpg?raw=true)


# Some preliminary data:

![alt text](https://github.com/XaviCanoFerrer/Open_wireless_EMG/blob/main/Data/Forearm_uV_vs_t.png?raw=true)

![alt text](https://github.com/XaviCanoFerrer/Open_wireless_EMG/blob/main/Data/Forearm_uV_vs_t_rect.png?raw=true)


