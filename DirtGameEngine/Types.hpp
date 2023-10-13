//Types.hpp
#pragma once

#include <glm.hpp>

namespace dgm {
    namespace WindowSettings {
        extern int majorVer;
        extern int minorVer;
        extern bool fullscreen;
        extern glm::vec2 screenSize;
        extern char title[40];
    };

    namespace EngineSettings {
        extern bool debugMode;
    };
}
