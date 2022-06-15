import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from scipy.signal import kaiserord, lfilter, firwin, freqz
from numpy.fft import fft, ifft
plt.style.use('bmh')

#Amplifier gains
G1 = 50.4
G2 = 2
G3 = 56.8

#ADC gain
G_adc = 1

#Total gain of the system
G_total = G1*G2*G3*G_adc

# Import from excel
V = pd.read_excel('EMG2.xlsx',usecols="A")/G_total*1e6
t = pd.read_excel('EMG2.xlsx',usecols="B")/1000
V = V-np.mean(V)
Vrect = abs(V)


#Plot raw EMG
plt.xlabel('Time (s)')
plt.ylabel('Voltage (uV)')
plt.plot(t, V)
plt.title('Forearm EMG signal')
plt.legend(loc='upper right', frameon=False)
plt.xlim(9, 16)
plt.show()

#Plot rectified EMG
plt.xlabel('Time (s)')
plt.ylabel('Voltage (uV)')
plt.plot(t, Vrect, 'm')
plt.title('Forearm EMG signal rectified')
plt.legend(loc='upper right', frameon=False)
plt.xlim(9, 16)
plt.show()

#Plot a single contraction
plt.xlabel('Time (s)')
plt.ylabel('Voltage (uV)')
plt.plot(t, V)
plt.title('Forearm single contraction')
plt.legend(loc='upper right', frameon=False)
plt.xlim(12.4, 13)
plt.ylim(-80, 60)
plt.show()


V2 = V[450:610]
plt.xlabel('Time (s)')
plt.ylabel('Voltage (uV)')
plt.plot(V2)
plt.title('Forearm single contraction')
plt.legend(loc='upper right', frameon=False)
plt.ylim(-80, 60)
plt.show()

# FFT
#V2 = V[400:500]
X = fft(V2)
N = len(X)
n = np.arange(N)
# get the sampling rate
sr = 385
#sr = np.mean(np.diff(t))
#print(np.diff(t*1000))
T = N/sr
freq = n/T

# Get the one-sided specturm
n_oneside = N//2
# get the one side frequency
f_oneside = freq[:n_oneside]

#plt.figure(figsize = (12, 6))
plt.plot(f_oneside, np.abs(X[:n_oneside]), 'b')
plt.xlabel('Freq (Hz)')
plt.ylabel('FFT Amplitude |X(freq)|')
plt.xlim(0, 385/2)
plt.ylim(0, 100)
plt.show()
