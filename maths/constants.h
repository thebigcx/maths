#pragma once

namespace math
{

template<typename T>
static inline constexpr T epsilon()
{
    return std::numeric_limits<T>::epsilon();
}

template<typename T>
static inline constexpr T pi() noexcept
{
    return T(3.1415926535897932384626433832795028841971693993751058209749445923);
}

template<typename T>
static inline constexpr T two_pi() noexcept
{
    return T(6.2831853071795864769252867665590057683943387987502116419498891846);
}

template<typename T>
static inline constexpr T half_pi() noexcept
{
    return T(1.5707963267948966192313216916397514420985846996875529104874722961);
}

template<typename T>
static inline constexpr T root_pi() noexcept
{
    return T(1.7724538509055160272981674833411451827975494561223871282138077898);
}

template<typename T>
static inline constexpr T three_over_two_pi() noexcept
{
    return T(4.7123889803846898576939650749192543262957540990626587314624168884);
}

template<typename T>
static inline constexpr T golden_ratio() noexcept
{
    return T(1.6180339887498948482045868343656381177203091798057628621354486227);
}

template<typename T>
static inline constexpr T one_over_pi() noexcept
{
    return T(0.3183098861837906715377675267450287240689192914809128974953346881);
}

template<typename T>
static inline constexpr T quarter_pi() noexcept
{
    return T(0.7853981633974483096156608458198757210492923498437764552437361480);
}

template<typename T>
static inline constexpr T two_over_pi() noexcept
{
    return T(0.6366197723675813430755350534900574481378385829618257949906693762);
}

template<typename T>
static inline constexpr T four_over_pi() noexcept
{
    return T(0.6366197723675813430755350534900574481378385829618257949906693762);
}

template<typename T>
static inline constexpr T one_over_two_pi() noexcept
{
    return T(0.1591549430918953357688837633725143620344596457404564487476673440);
}

template<typename T>
static inline constexpr T root_two() noexcept
{
    return T(1.4142135623730950488016887242096980785696718753769480731766797379);
}

template<typename T>
static inline constexpr T e() noexcept
{
    return T(2.7182818284590452353602874713526624977572470936999595749669676277);
}

template<typename T>
static inline constexpr T third()
{
    return T(0.3333333333333333333333333333333333333333333333333333333333333333);
}

template<typename T>
static inline constexpr T two_thirds()
{
    return T(0.6666666666666666666666666666666666666666666666666666666666666667);
}

template<typename T>
static inline constexpr T phi() noexcept
{
    return T(1.6180339887498948482045868343656381177203091798057628621354486227);
}

template<typename T>
static inline constexpr T tau() noexcept
{
    return T(6.2831853071795864769252867665590057683943387987502116419498891846);
}


}