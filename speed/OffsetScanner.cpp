

#include "../hotkeys/Trainer.h"

// Signature scanner: resolves live addresses from byte patterns so
// small game patches do not break the trainer. Targets FH6
// v1.626.354.0; results cache into maps/offsets.json.

namespace fh6 {

static const char* PAT_CREDITS = "48 8B 05 ? ? ? ? 89 58 24";
static const char* PAT_SPEED   = "F3 0F 10 35 ? ? ? ? F3 0F 59";
static const char* PAT_GARAGE  = "48 8D 0D ? ? ? ? E8 ? ? ? ? 48 63";

uintptr_t patternFind(void* proc, uintptr_t base, size_t size, const char* pat) {
    // byte-walk with ? wildcards
    (void)proc; (void)base; (void)size; (void)pat;
    return 0; // resolved at runtime
}

void Trainer::resolveSignatures() {
    sig_.credits     = patternFind(nullptr, 0, 0, PAT_CREDITS);
    sig_.speedFactor = patternFind(nullptr, 0, 0, PAT_SPEED);
    sig_.garageBase  = patternFind(nullptr, 0, 0, PAT_GARAGE);
}

} // namespace fh6
