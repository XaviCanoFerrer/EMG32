# EMG32

Two-channel EMG acquisition system

# Features:

Adjustable total gain 100-10000

Instrumentation amplifier (AD8226)

12 bit ADC (Texas instruments ADS1015)

First order high and low pass filters fc = 22 Hz and fc = 482 Hz

LiPo battery power management system (It can be charged from the USB port)

The basic code has two modes, 2ch and 1 ch modes which can be selected pressing the SW1 pushbutton.

SW2 to reset the board.

Sampling frequencies 385 Hz through the serial port and 200 Hz using BT for 1 channel so not enough for sEMG standards Fs = 1kHz. 

It is still usable to measure muscle activity but not for frequency dependant processing or analysis.

<p align="center">
  <img width="640" height="480" src="https://user-images.githubusercontent.com/54901317/214152530-e8083803-7724-4060-a290-7e1f43e9bdb6.png">
</p>

# V1 has a couple of mistakes but it can be fuctional: 

The quad amplifier (LM324) has to be assembled with a 180 degree rotation if not it will be shorted.

The JAC connectors are not close enough to the edge and depensing on the length of your cable it won't go deep enough to make a good contact.

Both mistakes are solved in V2.

![alt text](https://github.com/XaviCanoFerrer/EMG_32/blob/main/Figure.png?raw=true)



