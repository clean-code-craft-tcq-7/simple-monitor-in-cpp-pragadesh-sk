#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

int vitalsOk(float temperature, float pulseRate, float spo2) {
return vitalTemp(temperature)&&vitalPulseRate(pulseRate)&&vitalSpo2(spo2);
}

int vitalTemp(float temperature) {
  if (temperature > 102 || temperature < 95) {
    cout << "Temperature is critical!\n";
    delay();
      return 0;
    }
    return 1;
  }
  int vitalPulseRate(float pulseRate) {
  if (pulseRate < 60 || pulseRate > 100) {
    cout << "Pulse Rate is out of range!\n";
    delay();
    return 0;
    }
    return 1;
  }
  int vitalSpo2(float spo2) {
    if (spo2 < 90) {
    cout << "Oxygen Saturation out of range!\n";
    delay();
    return 0;
    }
  return 1;
  }
void delay() {
for (int i = 0; i < 6; i++) {
      cout << "\r* " << flush;
      sleep_for(seconds(1));
      cout << "\r *" << flush;
      sleep_for(seconds(1));
    }
}
