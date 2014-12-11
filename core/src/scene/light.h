/*  This is the abstract class that other type of lights can extend from it.
 *  Another possible aproach could be something like the vertexLayout but this one
 *  let you define specific methods for subclassed lights.
 */

#pragma once

#include "glm/glm.hpp"
#include "util/shaderProgram.h"

typedef enum {
    LIGHT_NOT_DEFINE = 0,
    LIGHT_DIRECTIONAL,
    LIGHT_POINT,
    LIGHT_SPOT,
    LIGHT_CUSTOM
} LightType;

class Light {
public:
    
    Light();
    virtual ~Light();
    
    /*  This name is used to construct the uniform name to be pass to the shader */
    virtual void setName(const std::string &_name);

    /*  Arrays of lights are manage by the scene. And this number is define on the adding lights methods.
    *   Especial lights don't need to be pass on arrays. */
    virtual void setIndexPos(int _indexPos);

    /* General light colors */
    virtual void setAmbientColor(const glm::vec4 _ambient);
    virtual void setDiffuseColor(const glm::vec4 _diffuse);
    virtual void setSpecularColor(const glm::vec4 _specular);

    /* Get the type of light, especially to identify the class and specific methods to it. */
    virtual LightType getType();

    /* Get the name of the light */
    virtual std::string getName();

    /* Get the uniform name of the light */
    virtual std::string getUniformName();

    /*  This method is inspired on the webgl version.
    *   Once we have a better shader injection system we can ask for the code for a specifict light */
    virtual std::string getBlock() = 0;

    /*  This method is inspired on the webgl version.
    *   used to inject the uniforms for this particular light on
    *   the passed shader */
    virtual void setupProgram( ShaderProgram &_shader );

protected:

    /* Light Colors */
    glm::vec4 m_ambient;
    glm::vec4 m_diffuse;
    glm::vec4 m_specular;

    /*  The name reference to the uniform on the shader. 
    *  For generic names like "directionalLight", "pointLight" or "spotLight" this will become part of the array:
    * "u_directionalLight[0]", "u_pointLight[0]" or "u_spotLight[0]"  */
    std::string m_name;

    /*  This is use to identify the type of light after been pull inside a vector of uniq_ptr of this abstract class*/
    LightType   m_type;

    /* If -1 is a single light not injected through the array */
    int         m_index;
};
