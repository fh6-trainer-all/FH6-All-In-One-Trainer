

#include "../hotkeys/Trainer.h"
#include <iostream>

// FH6 Trainer All-in-One - forza horizon 6 trainer entry point.
// Attaches to the game, hosts the ImGui cheat overlay on Insert.

int main() {
    fh6::Trainer trainer;

    std::cout << "FH6 Trainer All-in-One v3.2\n";
    std::cout << "waiting for ForzaHorizon6.exe...\n";

    if (!trainer.waitForGame("ForzaHorizon6.exe", 2000)) {
        std::cerr << "game not found - launch FH6 first\n";
        return 1;
    }

    trainer.resolveSignatures();  // pattern scan for v1.626.354.0
    trainer.bindCheatKeys();      // F1-F8
    trainer.openOverlay();        // ImGui menu on VK_INSERT

    return trainer.loop();
}
