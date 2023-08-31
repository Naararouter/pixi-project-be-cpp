#include <string>

#include "./GameEvent.cpp"

class GameSession {
public:
    void pushEvent(const GameEvent& event) {
        m_events.push_back(event);
    }

    const std::vector<GameEvent>& getEvents() const { return m_events; }

private:
    std::vector<GameEvent> m_events;
};
