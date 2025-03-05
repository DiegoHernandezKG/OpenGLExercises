#ifndef TEXTURELOADER_HPP
#define TEXTURELOADER_HPP

#include <glad/glad.h>
#include <stb_image.h>
#include <iostream>

class TextureLoader {
public:
    static GLuint loadTexture(const char* path, bool flipVertically = false);
};

#endif // TEXTURELOADER_HPP