#include "Camera.hpp"

Camera::Camera() {
    projectionMatrix = glm::perspective(glm::radians(45.0f), (float)640/(float)480, 0.0f, 30.0f);
//    projectionMatrix = glm::mat4(1.0f);
    location = new PVector { 0.0f, 0.0f, 2.0f };
    seenAtCenter = new PVector { 0.0f, 0.0f, 0.0f };
    up = new PVector { 0.0f, 1.0f, 0.0f };
    ChangeViewMatrix();
}

glm::mat4 Camera::getCameraMatrix() const {
    return projectionMatrix * viewMatrix;
}

void Camera::MoveLeft() {
    location->moveX(-1.0f);
    ChangeViewMatrix();
}

void Camera::MoveRight() {
    location->moveX(1.0f);
    ChangeViewMatrix();
}

void Camera::MoveUp() {
    location->moveY(1.0f);
    ChangeViewMatrix();
}

void Camera::MoveDown() {
    location->moveY(-1.0f);
    ChangeViewMatrix();
}

void Camera::ZoomIn() {
    location->moveZ(1.0f);
    ChangeViewMatrix();
}

void Camera::ZoomOut() {
    location->moveZ(-1.0f);
    ChangeViewMatrix();
}

void Camera::ChangeViewMatrix() {
    viewMatrix = glm::lookAt(
                     glm::vec3(location->x, location->y, location->z),
                     glm::vec3(seenAtCenter->x, seenAtCenter->y, seenAtCenter->z),
                     glm::vec3(up->x, up->y, up->z)
            );
//    viewMatrix = glm::mat4(1.0f);
}
