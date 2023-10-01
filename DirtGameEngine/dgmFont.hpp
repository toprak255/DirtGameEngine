#pragma once
#include <vector>
#include <string>
struct CharInfo {
    int id;
    int x, y, width, height;
    int xoffset, yoffset, xadvance;
    int page, chnl;

};
typedef std::vector<CharInfo> fontData;

namespace dgm {

    int loadFont(std::string name = "Bahnschrift");

    int text2D();

}