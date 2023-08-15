#pragma once

#include "ghost.hpp"
#include "constants.hpp"
#include "math.hpp"
#include "pacman.hpp"

#include <centurion/common/math.hpp>

class Pinky final : public Ghost
{
public:
    Pinky(cen::renderer_handle const& renderer)
      : Ghost {renderer, {
                             .color = cen::colors::pink,
                             .start = startpos_of(PINKY_CHAR),
                             .home = startpos_of(PINKY_CHAR), // use position in home area
                             .scatter = TOP_LEFT * TILE_SIZE // top left
                         }}
    {
    }

    [[nodiscard]] virtual auto calc_target(Pacman const& pacman) const -> cen::ipoint
    {
        // Pinky's target is 4 blocks ahead of Pacman
        constexpr auto dist = 4 * TILE_SIZE;
        return pacman.position() + to_point<int>(pacman.direction()) * dist;
    }
};