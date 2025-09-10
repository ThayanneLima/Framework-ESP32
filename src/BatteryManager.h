#ifndef BATTERYMANAGER_H
#define BATTERYMANAGER_H

class BatteryManager {
public:
    float battery_level();
    float last_voltage() const;
    void update();
};

#endif
