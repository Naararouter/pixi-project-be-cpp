#include "GameEvent.hpp"

GameEvent::GameEvent(std::string type)
        : m_type(std::move(type)), m_timestamp(std::chrono::system_clock::now()) {}

const std::string& GameEvent::getType() const {
    return m_type;
}

auto GameEvent::getTimestamp() const {
    return m_timestamp;
}
