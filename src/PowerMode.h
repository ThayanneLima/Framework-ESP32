#ifndef POWERMODE_H
#define POWERMODE_H

class PowerMode {
public:
    virtual void enter_mode() = 0;   // método abstrato
    virtual ~PowerMode() {}
};

#endif
