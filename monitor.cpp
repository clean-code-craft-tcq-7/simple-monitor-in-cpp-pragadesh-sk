#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

int vitalsOk(float temperature, float pulseRate, float spo2) {
return vit_Temp(temperature)&&vit_PulseRate(pulseRate)&&vit_Spo2(spo2);
}

int vit_Temp(float temperature) {
  if (temperature > 102 || temperature < 95) {
    cout << "Temperature is critical!\n";
    time();
      return 0;
    }
    return 1;
  }
  int vit_PulseRate(float pulseRate) {
  if (pulseRate < 60 || pulseRate > 100) {
    cout << "Pulse Rate is out of range!\n";
    time();
    return 0;
    }
    return 1;
  }
  int vit_Spo2(float spo2) {
    if (spo2 < 90) {
    cout << "Oxygen Saturation out of range!\n";
    time();
    return 0;
    }
  return 1;
  }
void time() {
for (int i = 0; i < 6; i++) {
      cout << "\r* " << flush;
      sleep_for(seconds(1));
      cout << "\r *" << flush;
      sleep_for(seconds(1));
    }
}
