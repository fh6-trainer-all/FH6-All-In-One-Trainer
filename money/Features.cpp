

#include "../hotkeys/Trainer.h"

// Cheat implementations. Every write goes through GameMem -
// external only, no game files are ever modified.

namespace fh6 {

void Trainer::moneyFreeze(bool on) {
    // credits pinned at 999,999,999
    if (on) mem_.pin<u32>(sig_.credits, 999999999);
    else mem_.release(sig_.credits);
}

void Trainer::speedBoost(float mult) {
    // 1x-10x: fh6 speed boost writes the physics tick directly
    mem_.write<float>(sig_.speedFactor, mult);
}

void Trainer::godMode(bool on) {
    mem_.write<u8>(sig_.damageFlag, on ? 0 : 1);
}

void Trainer::unlockGarage() {
    // owned=1 across all 812 garage slots
    for (u32 i = 0; i < 812; i++)
        mem_.write<u8>(sig_.garageBase + i * 0x18, 1);
}

void Trainer::instantWin() {
    mem_.write<u8>(sig_.racePosition, 1);
    mem_.write<u8>(sig_.raceFinished, 1);
}

void Trainer::xpBoost(int mult) {
    mem_.write<float>(sig_.xpFactor, static_cast<float>(mult));
}

} // namespace fh6
