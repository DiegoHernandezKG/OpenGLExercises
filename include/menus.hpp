#ifndef MENUS_HPP
#define MENUS_HPP

#include <glm/glm.hpp>
#include <vector>

enum class SliderType {
    Float,
    Vec3
};

struct SliderItem {
    const char* label;
    SliderType  type;
    float       minVal;
    float       maxVal;

    // We use a union to store either a float* or glm::vec3*
    union {
        float* floatPtr;
        glm::vec3* vec3Ptr;
    };
};

// Add items to a single global/static list:
void addSlider(const char* label, float* var, float minVal, float maxVal);
void addSlider(const char* label, glm::vec3* var, float minVal, float maxVal);

// Draw the ImGui window that shows all sliders
void createValueSlider(const char* windowName);

#endif
