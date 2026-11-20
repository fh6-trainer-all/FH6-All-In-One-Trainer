

#include "../hotkeys/Trainer.h"

// ImGui overlay for the fh6 trainer: opens on Insert, organized
// into tabs - Money, Cars, Race, Player, Teleport.

namespace fh6 {

void Trainer::openOverlay() {
    overlayInit(gameHwnd());
    addTab("Money",    [] { /* credits freeze slider */ });
    addTab("Cars",     [] { /* unlock all 812 */ });
    addTab("Race",     [] { /* instant win, skip checkpoint */ });
    addTab("Player",   [] { /* god mode, xp multiplier */ });
    addTab("Teleport", [] { /* waypoint + saved spots */ });
}

void Trainer::drawOverlayFrame() {
    if (!overlayVisible()) return;
    overlayBegin("FH6 Trainer All-in-One v3.2");
    overlayRenderTabs();
    overlayEnd();
}

} // namespace fh6
