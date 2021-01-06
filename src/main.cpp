/*
    src/example1.cpp -- C++ version of an example application that shows
    how to use the various widget classes. For a Python implementation, see
    '../python/example1.py'.

    NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/

#include "graphics/graphics_arena_viewer.h"
#include "params/arena_params.h"

// Includes for the GLTexture class.
#include <cstdint>
#include <memory>
#include <utility>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
using std::pair;
using std::to_string;

int main(int /* argc */, char ** /* argv */) {
    try {
        nanogui::init();

        arena_params aparams;

        // Start up the graphics (which creates the arena).
        // Run will enter the nanogui::mainloop()
        GraphicsArenaViewer *app =
            new GraphicsArenaViewer(&aparams);
        app->Run();
        nanogui::shutdown();
    } catch (const std::runtime_error &e) {
        std::string error_msg = std::string("Caught a fatal error: ") + std::string(e.what());
        std::cerr << error_msg << endl;
        return -1;
    }
    return 0;
}

