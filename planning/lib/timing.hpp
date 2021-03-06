//
//  Time recording
//
#pragma once

#include <chrono>

namespace search
{
    //
    //  class Timing
    //  an RAII style timer with std::chrono from c++ 11
    //
    struct Timing
    {
        using Time = std::chrono::high_resolution_clock;
        using TimePoint = std::chrono::high_resolution_clock::time_point;

        explicit Timing(long long& record)
            : recording{ record }, start{ Time::now() }
        { }

        ~Timing()
        {
            using std::chrono::duration;
            using std::chrono::duration_cast;
            recording = duration_cast<std::chrono::milliseconds>(Time::now() - start).count();
        }

        long long& recording;
        TimePoint const start;
    };
}