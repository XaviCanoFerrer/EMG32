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

# V1 has a couple of mistakes but it can be fuctional: 

The quad amplifier (LM324) has to be assembled with a 180 degree rotation if not it will be shorted.

The JAC connectors are not close enough to the edge and depensing on the length of your cable it won't go deep enough to make a good contact.

Both mistakes are solved in V2 but still not tested.

![alt text](https://github.com/XaviCanoFerrer/EMG_32/blob/main/Figure.png?raw=true)

# Next steps

Change the ADC for one with higher sampling rate
