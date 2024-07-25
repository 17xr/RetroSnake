#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <cassert>
#include <chrono>
#include <random>
#include <type_traits>

namespace Random {
    inline std::mt19937_64 generator() {
        using namespace std::chrono;
        steady_clock::rep clock{steady_clock::now().time_since_epoch().count()};

        std::random_device dev{};
        std::seed_seq seq{
            static_cast<std::seed_seq::result_type>(clock), dev(), dev(), dev(), dev(), dev(), dev(), dev()
        };

        return std::mt19937_64{seq};
    }

    inline std::mt19937_64 engine{generator()};

    template<typename T>
    inline T rand(T min, T max) {
        assert(std::is_floating_point<T>::value && "rand(): Template parameter is not of floating-point type.\n");
        assert(min <= max && "rand(): Invalid range.\n");

        std::uniform_int_distribution dist(min, max);
        T rand{dist(engine)};

        return rand;
    }

    template<typename T>
    inline T randint(T min, T max) {
        assert(std::is_integral<T>::value && "randint(): Template parameter is not of integral type.\n");
        assert(min <= max && "randint(): Invalid range.\n");

        std::uniform_int_distribution dist(min, max);
        T randint{dist(engine)};

        return randint;
    }
}

#endif
