#include "menus.hpp"
#include "imgui.h"

// We'll store everything in a static vector
static std::vector<SliderItem> s_sliders;

void addSlider(const char* label, float* var, float minVal, float maxVal)
{
    SliderItem item;
    item.label   = label;
    item.type    = SliderType::Float;
    item.minVal  = minVal;
    item.maxVal  = maxVal;
    item.floatPtr = var;  // fill union
    s_sliders.push_back(item);
}

void addSlider(const char* label, glm::vec3* var, float minVal, float maxVal)
{
    SliderItem item;
    item.label   = label;
    item.type    = SliderType::Vec3;
    item.minVal  = minVal;
    item.maxVal  = maxVal;
    item.vec3Ptr = var;  // fill union
    s_sliders.push_back(item);
}

void createValueSlider(const char* windowName)
{
    ImGui::Begin(windowName);

    for (auto& item : s_sliders) {
        switch (item.type) {
        case SliderType::Float:
            ImGui::SliderFloat(item.label, item.floatPtr,
                               item.minVal, item.maxVal);
            break;

        case SliderType::Vec3:
            ImGui::SliderFloat3(item.label, &item.vec3Ptr->x,
                                item.minVal, item.maxVal);
            break;
        }
    }

    ImGui::End();
}
