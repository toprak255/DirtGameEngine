#pragma once

struct _vec2 { float x; float y; };
typedef struct _vec2 vec2;


namespace dgm {
	int collision(vec2* vertices1, vec2* vertices2);
}