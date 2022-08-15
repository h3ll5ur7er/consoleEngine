#pragma once
#include <cstdint>
#include <memory>

class Engine;

class Scene {
public:
    inline Scene(std::shared_ptr<Engine> engine): engine(engine) {}
    ~Scene() = default;
    
    virtual void init() = 0;
    virtual void terminate() = 0;
    virtual void update(int64_t time, int64_t dt) = 0;
    virtual void draw(int64_t time, int64_t dt) = 0;
protected:
    std::shared_ptr<Engine> engine;
};
