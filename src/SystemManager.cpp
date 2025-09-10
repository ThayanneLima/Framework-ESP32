#include "SystemManager.h"
#include "PowerMode.h"
#include <Arduino.h>

SystemManager::SystemManager()
  : cpu_frequency(240.0f), current_mode(nullptr) {}

void SystemManager::init() {
    Serial.println("SystemManager inicializado");
}

void SystemManager::update_mode(PowerMode* mode) {
    current_mode = mode;
    if (current_mode) {
        current_mode->enter_mode();
    }
}

void SystemManager::run() {
    Serial.println("Executando tarefas do SystemManager...");
}
