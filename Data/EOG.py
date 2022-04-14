import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from scipy.signal import kaiserord, lfilter, firwin, freqz
import scipy.signal
plt.style.use('bmh')

#Amplifier gains
G1 = 50.4
G2 = 2
G3 = 56.8

#ADC gain
G_adc = 2/3

#Total gain of the system
G_total = G1*G2*G3*G_adc

# Import from excel
V = pd.read_excel('EOG1.xlsx',usecols="A")/G_total*1e6
t = pd.read_excel('EOG1.xlsx',usecols="B")/1000
V = V-np.mean(V)
Vrect = abs(V)


#Plot raw EOG
plt.xlabel('Time (s)')
plt.ylabel('Voltage (uV)')
plt.plot(t, V)
plt.title('EOG signal')
plt.legend(loc='upper right', frameon=False)
plt.xlim(38, 46)
plt.show()

#V = V.flatten()

# apply a 3-pole lowpass filter at 0.1x Nyquist frequency
b, a = scipy.signal.butter(2, 0.1)
EOG_filtered = scipy.signal.filtfilt(b, a, V)

# plot the original data next to the filtered data

plt.figure(figsize=(10, 4))

plt.subplot(121)
plt.plot(t, V)
plt.title("EOG Signal with Noise")
plt.margins(0, .05)

plt.subplot(122)
plt.plot(t, EOG_filtered)
plt.title("Filtered EOG Signal")
plt.margins(0, .05)

plt.tight_layout()
plt.show()
