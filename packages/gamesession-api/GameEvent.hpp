#ifndef GAME_EVENT_HPP
#define GAME_EVENT_HPP

#include <string>
#include <chrono>
#include <utility>

class GameEvent {
public:
    explicit GameEvent(std::string type);
    const std::string& getType() const;
    auto getTimestamp() const;

private:
    std::string m_type;
    std::chrono::system_clock::time_point m_timestamp; // Capture the event timestamp
};

#endif // GAME_EVENT_HPP