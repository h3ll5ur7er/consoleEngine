#include "engine/engine.hpp"

int main() {
    auto engine = std::make_shared<Engine>();
    engine->tests();
    engine->run();
    return 0;
}
