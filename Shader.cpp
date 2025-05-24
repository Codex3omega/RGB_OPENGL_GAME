#include "Shader.h"

/*Shader::Shader(const char* vertex_path, const char* frag_path) {

    // Get Shader Source
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    // ensure ifstream objects can throw exceptions:
    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        // open files
        vShaderFile.open(vertex_path);
        fShaderFile.open(frag_path);
        std::stringstream vShaderStream, fShaderStream;
        // read file's buffer contents into streams
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        // close file handlers
        vShaderFile.close();
        fShaderFile.close();
        // convert stream into string
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch (std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();


    // all the opengl Shader stuff goes here :


    int success;
    char infoLog[512];

    // vertex shader
    unsigned int vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vShaderCode, NULL);
    glCompileShader(vertex_shader);


    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
    if (!success) {

        glGetShaderInfoLog(vertex_shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;

    }

    // fragment shader
    unsigned int frag_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(frag_shader, 1, &fShaderCode, NULL);
    glCompileShader(frag_shader);

    glGetShaderiv(frag_shader, GL_COMPILE_STATUS, &success);
    if (!success) {

        glGetShaderInfoLog(frag_shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;

    }

    id = glCreateProgram();
    glAttachShader(id, vertex_shader);
    glAttachShader(id, frag_shader);
    glLinkProgram(id);

    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if (!success) {

        glGetProgramInfoLog(id, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER PROGRAM::LINK_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertex_shader);
    glDeleteShader(frag_shader);

}*/

void Shader::init(const char* vertex_path, const char* frag_path) {

    // Get Shader Source
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    // ensure ifstream objects can throw exceptions:
    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        // open files
        vShaderFile.open(vertex_path);
        fShaderFile.open(frag_path);
        std::stringstream vShaderStream, fShaderStream;
        // read file's buffer contents into streams
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        // close file handlers
        vShaderFile.close();
        fShaderFile.close();
        // convert stream into string
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch (std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();


    // all the opengl Shader stuff goes here :


    int success;
    char infoLog[512];

    // vertex shader
    unsigned int vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vShaderCode, NULL);
    glCompileShader(vertex_shader);


    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
    if (!success) {

        glGetShaderInfoLog(vertex_shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;

    }

    // fragment shader
    unsigned int frag_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(frag_shader, 1, &fShaderCode, NULL);
    glCompileShader(frag_shader);

    glGetShaderiv(frag_shader, GL_COMPILE_STATUS, &success);
    if (!success) {

        glGetShaderInfoLog(frag_shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;

    }

    id = glCreateProgram();
    glAttachShader(id, vertex_shader);
    glAttachShader(id, frag_shader);
    glLinkProgram(id);

    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if (!success) {

        glGetProgramInfoLog(id, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER PROGRAM::LINK_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertex_shader);
    glDeleteShader(frag_shader);

}

void Shader::use() {
    glUseProgram(id);
}

void Shader::setFloat(const std::string& name, float value) const {

    glUniform1f(glGetUniformLocation(id, name.c_str()), value);

}

void Shader::setBool(const std::string& name, bool value)const {

    glUniform1i(glGetUniformLocation(id, name.c_str()), (int)value);

}

void Shader::setInt(const std::string& name, int value)const {

    glUniform1i(glGetUniformLocation(id, name.c_str()), value);

}

void Shader::setFloatVec4(const std::string& name, float x, float y, float z, float w) {

    glUniform4f(glGetUniformLocation(id, name.c_str()), x, y, z, w);

}

void Shader::setFloatVec3(const std::string& name, float x, float y, float z) {

    glUniform3f(glGetUniformLocation(id, name.c_str()), x, y, z);

}

void Shader::setMat4(const std::string& name, glm::mat4 mat) {

    glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));

}

void Shader::delete_shader() {

    glDeleteProgram(id);

}