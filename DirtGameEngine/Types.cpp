#include "Types.hpp"

namespace dgm {
    namespace WindowSettings {
        int majorVer = 4;
        int minorVer = 3;
        bool fullscreen = false;
        glm::vec2 screenSize = { 600, 300 };
        char title[40] = "DGM Demo Window";
    };

    namespace EngineSettings {
        bool debugMode = false;
    };
}
