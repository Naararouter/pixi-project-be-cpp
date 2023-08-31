#include <string>
#include <chrono>
#include <utility>

class GameEvent {
public:
    GameEvent(std::string type)
            : m_type(std::move(type)), m_timestamp(std::chrono::system_clock::now()) {}

    const std::string& getType() const { return m_type; }
    auto getTimestamp() const { return m_timestamp; }

private:
    std::string m_type;
    std::chrono::system_clock::time_point m_timestamp; // Capture the event timestamp
};
