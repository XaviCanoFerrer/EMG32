import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from scipy.signal import kaiserord, lfilter, firwin, freqz
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
