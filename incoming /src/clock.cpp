#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <chrono>

#include "clock.h"
#include "ntp-client.h"

using namespace std;

double request_test_duration()
{
    bool correct_input = false;
    int h = -1;
    int m = -1;
    int s = -1;
    char d1, d2, d3;

    double output;
    do
    {
        cout << "Please enter testing time (HH:MM:SS format): ";
        cin >> h >> d1 >> m >> d2 >> s;
        if (h >= 0 && m >= 0 && s >= 0 && d1 == ':' && d2 == ':')
        {
            output = h * 60 * 60 + m * 60 + s;
            if (output > 0)
            {
                correct_input = true;
            }
        }
        else
        {
            cout << "incorrect input";
        }
        cout << endl;
    } while (!correct_input);

    return output;
}

void run_test()
{
    time_t systemTime1, systemTime2, ntpTime1, ntpTime2;
    std::chrono::time_point<std::chrono::steady_clock> steadyTime1, steadyTime2;

    double systemTimeDiff, ntpTimeDiff, steadyTimeDiff;

    double seconds_to_test = request_test_duration();

    // Fix time on start
    systemTime1 = time(0);
    ntpTime1 = get_ntp_time();
    steadyTime1 = chrono::steady_clock::now();

    // Disable ntp synchronized
    DISABLE_NTP

    for (int i = seconds_to_test; i > 0; i--)
    {
        cout << i << " seconds out of " << seconds_to_test << " left" << endl;
        sleep(1); // not very accurate, but enough
    }

    // Fix time on end
    systemTime2 = time(0);
    ntpTime2 = get_ntp_time();
    steadyTime2 = chrono::steady_clock::now();

    // Calc and output diff
    ntpTimeDiff = difftime(ntpTime2, ntpTime1);
    systemTimeDiff = difftime(systemTime2, systemTime1);
    steadyTimeDiff = chrono::duration_cast<chrono::seconds>(steadyTime2 - steadyTime1).count();

    cout << "Time difference ntp: " << ntpTimeDiff << " sec." << endl;
    cout << "Time difference system clock: " << systemTimeDiff << " sec." << endl;
    cout << "Time difference in stady clock: " << steadyTimeDiff << " sec." << endl;

    // Enable ntp synchronized
    ENABLE_NTP
    return;
}