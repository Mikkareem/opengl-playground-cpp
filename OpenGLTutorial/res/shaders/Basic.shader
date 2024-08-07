#shader vertex
#version 330 core
layout(location = 0) in vec3 position;
uniform mat4 u_Camera;
uniform mat4 u_Model;
void main() {
   vec4 newPosition = u_Camera * u_Model * vec4(position, 1.0);
   gl_Position = newPosition;
}

#shader fragment
#version 330 core
precision mediump float;
layout(location = 0) out vec4 color;
uniform vec4 u_Color;
void main() {
   color = vec4(vec3(1.0, 0.0, 0.0), 1.0);
   color = u_Color;
}
