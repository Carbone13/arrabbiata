#ifndef ARRABBIATA_MAIN_HPP
#define ARRABBIATA_MAIN_HPP

void render();
void update ();
void tick ();
void debug_stats ();

// Helpers BGFX text debug macros

#define DEBUG_MILLISECONDS(title, time, nb) \
(bgfx::dbgTextPrintf(0, nb, ((0x2 + nb) << 4) | 0xF, \
(std::stringstream() << title \
<< std::fixed << std::setprecision(3) \
<< time << " ms").str().c_str()))

#define DEBUG_NUMBER(title, number, nb) \
(bgfx::dbgTextPrintf(0, nb, ((0x2 + nb) << 4) | 0xF, \
(std::stringstream() << title \
<< number).str().c_str()))

#endif //ARRABBIATA_MAIN_HPP
