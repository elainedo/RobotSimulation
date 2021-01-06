/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "simple_graphics.h"
#include "arena.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 *  @brief An application that uses the cs3081 SimpleGraphics library to open up
 *  a window that includes a few buttons for controlling the simulation and can
 *  be used to draw circles and other computer graphics.
 *
 *  After constructing a new RobotViewer, call Run() to start and run the
 *  application.  Run() will not return until the application window is closed.
 *  Make sure that you call cs3081::InitGraphics() before creating the
 *  RobotViewer app.  Example:
 *
 *  ```
 *  int main(int argc, char **argv) {
 *      cs3081::InitGraphics();
 *      RobotViewer *app = new RobotViewer();
 *      app->Run();
 *      cs3081::ShutdownGraphics();
 *      return 0;
 *  }
 *  ```
 *
 *  While the window is open \ref UpdateSimulation() will be called repeatedly,
 *  once per frame.  Fill this in to update your simulation or perform any other
 *  processing that should happen over time as the simulation progresses.
 *
 *  Fill in the On*() methods as desired to respond to user input events.
 *
 *  Fill in the Draw*() methods to draw graphics to the screen using
 *  either the nanovg library or raw OpenGL.
 */
class GraphicsArenaViewer : public SimpleGraphics {
public:
    explicit GraphicsArenaViewer(const struct arena_params* const params) ;
    virtual ~GraphicsArenaViewer(void) { /*delete arena_; */}

    /**
     * @brief Informs the arena of the new time, so that it can update.
     */
    void UpdateSimulation(double dt) override;

    /**
     * @brief Handle the user pressing the restart button on the GUI.
     */
    void OnRestartBtnPressed();

    /**
     * @brief Handle the user pressing the pause button on the GUI.
     */
    void OnPauseBtnPressed();

    /**
     * @brief Called each time a special (non-alphabetic) key is pressed.
     *
     * @param[in] key The key that was pressed.
     * @param[in] scancode The scancode corresponding to the key.
     * @param[in] modifiers Any modifiers that were also pressed.
     */
    void OnSpecialKeyDown(int key, int scancode, int modifiers) override;

    /**
     * @brief Draw the arena with all robots, obstacles using nanogui.
     *
     * This is the primary driver for drawing all entities in the arena.  It is
     *  called at each iteration of \ref nanogui::mainloop().
     *
     * @param[in] ctx Context for nanogui.
     */
    void DrawUsingNanoVG(NVGcontext *ctx) override;

    Arena* arena(void) const { return arena_; }

 private:
    /**
     * @brief Draw an obstacle in the arena using nanogui.
     *
     * This function requires an active nanovg drawing context (ctx), so it should
     * probably only be called from with \ref DrawUsingNanoVG().
     *
     * @param[in] ctx The nanogui context.
     * @param[in] obstacle The obstacle handle.
     */
    void DrawObstacle(NVGcontext *ctx,
                                const class Obstacle* const obstacle);

    /**
     * @brief Draw a player using nanogui.
     *
     * This function requires an active nanovg drawing context (ctx), so it should
     * probably only be called from with \ref DrawUsingNanoVG().
     *
     * @param[in] ctx The nanogui context.
     * @param[in] player The player handle.
     */
    void DrawPlayer(NVGcontext *ctx, const class Player* const player);

    Arena *arena_;
    bool paused_;
    nanogui::Button *pause_btn_;
    nanogui::Window *game_win_window_;
    nanogui::Window *game_lose_window_;

    double last_dt;

    // Satisfies compilers warning that the copy constructor should exist.
    GraphicsArenaViewer& operator=(const GraphicsArenaViewer& other) = delete;
    GraphicsArenaViewer(const GraphicsArenaViewer& other) = delete;
};