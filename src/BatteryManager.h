#ifndef BATTERYMANAGER_H
#define BATTERYMANAGER_H

#include <cmath>

class BatteryManager {
public:
    enum class Mode { Normal, Economy, Critical };

    BatteryManager() = default;

    // Define o nível atual da bateria em porcentagem (0..100).
    // Valores fora do intervalo são automaticamente "clampados".
    void setLevelPercent(float percent);

    // Lê o nível atual em porcentagem.
    float levelPercent() const { return _levelPercent; }

    // Decide o modo com base no nível atual (%).
    Mode selectMode() const;

    // Helper para imprimir (útil em logs/Serial).
    static const char* toString(Mode m);

    // (Opcional) Converte tensão -> % e atualiza o nível.
    // Ex.: setLevelFromVoltage(vbat, 3.3f, 4.2f);
    void setLevelFromVoltage(float vbat, float vmin, float vmax);

private:
    float _levelPercent = NAN; // 0..100
};

#endif
