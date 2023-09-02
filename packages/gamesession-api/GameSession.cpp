#include <string>

#include "./GameSession.hpp"

void GameSession::pushEvent(const GameEvent& event) {
    m_events.push_back(event);
}

const std::vector<GameEvent>& GameSession::getEvents() const { return m_events; }
