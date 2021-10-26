#ifndef __CLOCK__
#define __CLOCK__
void run_test();

#if defined(__APPLE__) || defined(__MACH__)
#define DISABLE_NTP system("sudo systemsetup -setnetworktimeserver off");
#define ENABLE_NTP system("sudo systemsetup -setnetworktimeserver on");
#else
#define DISABLE_NTP cout << "you need configure ntp disable cli command for your OS";
#define ENABLE_NTP cout << "you need configure ntp disable cli command for your OS";
#endif

#endif
