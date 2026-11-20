

#include "Trainer.h"

// Trainer shell: attach, hotkey bindings, overlay loop.

namespace fh6 {

bool Trainer::waitForGame(const char* proc, unsigned long timeoutMs) {
    return mem_.waitFor(proc, timeoutMs);
}

void Trainer::bindCheatKeys() {
    // F1 money, F2 speed, F3 god mode, F4 unlock cars,
    // F5 teleport, F6 instant win, F7 checkpoint, F8 xp
    mapKey(VK_F1, [this] { moneyFreeze(true); });
    mapKey(VK_F4, [this] { unlockGarage(); });
    mapKey(VK_F6, [this] { instantWin(); });
}

int Trainer::loop() {
    while (gameAlive()) {
        pumpKeys();
        drawOverlayFrame();
    }
    return 0;
}

} // namespace fh6
