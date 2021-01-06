#include <nanogui/opengl.h>
#include <nanogui/glutil.h>
#include <nanogui/screen.h>
#include <nanogui/window.h>
#include <nanogui/formhelper.h>
#include <iostream>
#include <string>

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

class SimpleGraphics : public nanogui::Screen {
public:
    SimpleGraphics(int width, int height, const std::string &caption);
    
    virtual ~SimpleGraphics();

    virtual void OnMouseMove(__unused int x, __unused int y) {}

    virtual void OnLeftMouseDown(__unused int x, __unused int y) {}

    virtual void OnLeftMouseUp(__unused int x, __unused int y) {}

    virtual void OnRightMouseDown(__unused int x, __unused int y) {}

    virtual void OnRightMouseUp(__unused int x, __unused int y) {}

    virtual void OnKeyDown(__unused const char *c, __unused int modifiers) {}

    virtual void OnKeyUp(__unused const char *c, __unused int modifiers) {}

    virtual void OnSpecialKeyDown(__unused int key, __unused int scancode,
                                    __unused int modifiers) {}

    virtual void OnSpecialKeyUp(__unused int key, __unused int scancode,
                                __unused int modifiers) {}

    /**
     * @brief Called once per frame.
     *
     * @param[in] dt The elapsed time since the last call.
     *
     * Override *ONE OF THESE* and fill it in to update your simulation code or
     * any other updates you need to make to your model that are timed rather than
     * in response to user input.
     */
    virtual void UpdateSimulation(__unused double dt) {}
    virtual void UpdateSimulation(__unused uint dt) {}

    /**
     * @brief Draw stuff with nanogui.
     *
     * @param[in] ctx Context for nanogui.
     *
     * Override this to draw graphics using the nanovg vector graphics library,
     * which provides an easy way to draw 2D shapes to the screen.
     */
    virtual void DrawUsingNanoVG(__unused NVGcontext *ctx) {}

    /**
     * @brief Draw stuff with OpenGL.
     *
     * Override this to draw graphics using raw OpenGL 2D or 3D graphics
     * which provides an easy way to draw 2D shapes to the screen.
     */
    virtual void DrawUsingOpenGL(void) {}

    /// After creating a new GraphicsApp, call this to start the app's
    /// mainloop.  Each time through the mainloop the app will: 1. respond
    /// any user input events by calling the On*() callback methods, 2. call
    /// UpdateSimulation(), and 3. call the two Draw*() methods.  Note that
    /// Run() does not return until the user closes the app and the program
    /// is ready to shutdown.
    void Run();

private:
    bool mouseButtonEvent(const Eigen::Vector2i &p, int button, bool down,
                        int modifiers);
    bool mouseMotionEvent(const Eigen::Vector2i &p, const Eigen::Vector2i &rel,
                        int button, int modifiers);
    bool keyboardEvent(int key, int scancode, int action, int modifiers) override;
    void draw(NVGcontext *ctx) override;
    void DrawContents();

    double last_draw_time_;
};
