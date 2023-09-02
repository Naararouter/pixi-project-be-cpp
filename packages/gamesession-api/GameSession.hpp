#ifndef GAME_SESSION_HPP
#define GAME_SESSION_HPP

#include "./GameEvent.hpp"

class GameSession {
public:
    void pushEvent(const GameEvent& event);
    const std::vector<GameEvent>& getEvents() const;

private:
    std::vector<GameEvent> m_events;
};

#endif // GAME_SESSION_HPP