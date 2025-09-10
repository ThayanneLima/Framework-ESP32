#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H

#include "BatteryManager.h"  // <— necessário aqui
class PowerMode;             // forward para evitar puxar tudo

class SystemManager {
public:
    SystemManager();
    void init();
    void update_mode(PowerMode* mode);
    void run();

private:
    float cpu_frequency;
    BatteryManager battery_manager; // OK, agora o tipo é conhecido
    PowerMode* current_mode;
};

#endif
