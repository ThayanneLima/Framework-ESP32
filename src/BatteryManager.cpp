#include "BatteryManager.h"
#include <algorithm>

void BatteryManager::setLevelPercent(float percent) {
    if (std::isnan(percent)) {
        _levelPercent = 0.0f; // trate como esgotado
        return;
    }
    // Limita ao intervalo [0, 100]
    _levelPercent = std::max(0.0f, std::min(100.0f, percent));
}

BatteryManager::Mode BatteryManager::selectMode() const {
    // Se ainda não foi definido, considere crítico
    float p = std::isnan(_levelPercent) ? 0.0f : _levelPercent;

    // Faixas pedidas:
    // Normal:   100..71
    // Economia: 70..30
    // Crítico:  29..1  (0% também consideraremos crítico)
    if (p >= 71.0f) {
        return Mode::Normal;
    } else if (p >= 30.0f) {
        return Mode::Economy;
    } else {
        return Mode::Critical;
    }
}

const char* BatteryManager::toString(BatteryManager::Mode m) {
    switch (m) {
        case Mode::Normal:   return "Normal";
        case Mode::Economy:  return "Economia";
        case Mode::Critical: return "Crítico";
        default:             return "Desconhecido";
    }
}

void BatteryManager::setLevelFromVoltage(float vbat, float vmin, float vmax) {
    if (std::isnan(vbat) || vmax <= vmin) {
        setLevelPercent(0.0f);
        return;
    }
    // Mapeia linearmente a tensão para 0..100%
    float pct = (vbat - vmin) * 100.0f / (vmax - vmin);
    setLevelPercent(pct);
}
