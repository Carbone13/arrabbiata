#ifndef ARRABBIATA_TIME_HPP
#define ARRABBIATA_TIME_HPP


struct Time
{
    float delta;
    float fixedDelta = 1.0f / 30.0f;

    void poll();
    void registerOneTick () { accumulator -= fixedDelta; }
    bool shouldPhysicsTick() { return accumulator >= fixedDelta; };
private:
    float lastTime {0};
    float accumulator {0};
};

#endif //ARRABBIATA_TIME_HPP
