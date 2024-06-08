#include <hyprutils/string/String.hpp>
#include "shared.hpp"

using namespace Hyprutils::String;

int main(int argc, char** argv, char** envp) {
    int ret = 0;

    EXPECT(trim("               a             "), "a");
    EXPECT(trim("   a   a           "), "a   a");
    EXPECT(trim("a"), "a");
    EXPECT(trim("                           "), "");

    EXPECT(isNumber("99214123434"), true);
    EXPECT(isNumber("-35252345234"), true);
    EXPECT(isNumber("---3423--432"), false);
    EXPECT(isNumber("s---3423--432"), false);
    EXPECT(isNumber("---3423--432s"), false);
    EXPECT(isNumber("1s"), false);
    EXPECT(isNumber(""), false);
    EXPECT(isNumber("--0"), false);
    EXPECT(isNumber("abc"), false);
    EXPECT(isNumber("0.0", true), true);
    EXPECT(isNumber("0.2", true), true);
    EXPECT(isNumber("0.", true), false);
    EXPECT(isNumber(".0", true), false);
    EXPECT(isNumber("", true), false);
    EXPECT(isNumber("vvss", true), false);
    EXPECT(isNumber("0.9999s", true), false);
    EXPECT(isNumber("s0.9999", true), false);

    return ret;
}