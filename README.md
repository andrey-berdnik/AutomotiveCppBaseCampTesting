# Test task for Automotive C++ BaseCamp

A small service that evaluates the accuracy of your computer's clock. Performs a time check over NTP, turns off synchronization (implemented only for), waits for a predetermined time, requests the time from NTP and calculates the discrepancy with the system time accumulated over the evaluation period.

For compile: 
```
make
```
For run: 
```
make run
```

Notes: To work with the NTP server (ntp-client.cpp), David Lettier's code was used, distributed under the BSD license.