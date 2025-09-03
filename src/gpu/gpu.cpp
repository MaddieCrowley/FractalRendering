//
// Created by madeline on 9/2/25.
//

#include "gpu.h"

gpu::gpu(const char* computePath) {
    glewInit();
    unsigned int compute;
    std::string code;
    std::ifstream cShaderFile;
    cShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        cShaderFile.open(computePath);

        std::stringstream cShaderStream;
        cShaderStream << cShaderFile.rdbuf();
        cShaderFile.close();
        code = cShaderStream.str();
    }
    catch (std::ifstream::failure& e) {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << e.what() << std::endl;
    }
    const char* cShaderCode = code.c_str();

    compute = glCreateShader(GL_COMPUTE_SHADER);
    glShaderSource(compute,1,&cShaderCode,nullptr);
    glCompileShader(compute);

    ID=glCreateProgram();
    glAttachShader(ID,compute);
    glLinkProgram(ID);
    checkCompileErrors(ID,"PROGRAM");
    glDeleteShader(compute);
}

void gpu::comp() {
    glUseProgram(ID);
}

gpu::~gpu() {
}
// gpu