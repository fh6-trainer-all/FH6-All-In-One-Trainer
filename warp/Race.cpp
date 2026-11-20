
#include <cstdint>
#include <string>
static constexpr const char* kBuild = "v3.2";
std::string build_tag() { return std::string(kBuild); }
