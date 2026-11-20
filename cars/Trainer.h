

#pragma once
#include <cstdint>
#include <string>

using u8 = unsigned char;
using u32 = unsigned int;

namespace fh6 {

class GameMem {
public:
    bool waitFor(const char* process, unsigned long timeoutMs);
    template<typename T> bool write(uintptr_t addr, T value) {
        return writeBytes(addr, &value, sizeof(T));
    }
    template<typename T> void pin(uintptr_t addr, T value);
    void release(uintptr_t addr);
    bool readBytes(uintptr_t addr, void* out, size_t size);
    bool writeBytes(uintptr_t addr, const void* data, size_t size);

private:
    void* handle_ = nullptr;
};

struct Signatures {
    uintptr_t credits = 0;
    uintptr_t speedFactor = 0;
    uintptr_t damageFlag = 0;
    uintptr_t garageBase = 0;
    uintptr_t racePosition = 0;
    uintptr_t raceFinished = 0;
    uintptr_t xpFactor = 0;
};

class Trainer {
public:
    bool waitForGame(const char* proc, unsigned long timeoutMs);
    void resolveSignatures();
    void bindCheatKeys();
    void openOverlay();
    int loop();

    void moneyFreeze(bool on);
    void speedBoost(float mult);
    void godMode(bool on);
    void unlockGarage();
    void instantWin();
    void xpBoost(int mult);

private:
    GameMem mem_;
    Signatures sig_;
};

} // namespace fh6
