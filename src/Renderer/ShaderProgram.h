#pragma once

#include <glad/glad.h>
#include <string>

namespace Renderer {
	class ShaderProgram {
	public:
		ShaderProgram(const std::string& vertexShader, const std::string& fragmentShader);
		~ShaderProgram();
		bool isCompiled() const { return m_isCompiled; }
		void use() const;

		ShaderProgram() = delete;
		ShaderProgram(ShaderProgram&) = delete;
		ShaderProgram& operator = (const ShaderProgram&) = delete;
		ShaderProgram& operator = (ShaderProgram&& ShaderProgram) noexcept;
		ShaderProgram(ShaderProgram&& ShaderProgram) noexcept;

	private:
		bool m_isCompiled = false;
		bool createShader(const std::string& source, const GLuint shaderType, GLuint& shaderID);
		GLuint m_ID = 0;
	};
}
