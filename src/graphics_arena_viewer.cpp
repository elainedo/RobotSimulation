#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "obstacle.h"
#include "arena_params.h"

#include "graphics_arena_viewer.h"

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
GraphicsArenaViewer::GraphicsArenaViewer(const struct arena_params* const params)
    : SimpleGraphics(params->x_dim, params->y_dim, "Robot Simulation"),
        arena_(new Arena(params)),
        paused_(false),
        pause_btn_(nullptr),
        game_win_window_(nullptr),
        game_lose_window_(nullptr),
        last_dt(-1) {
    nanogui::FormHelper *gui = new nanogui::FormHelper(this);
    nanogui::ref<nanogui::Window> window = gui->addWindow(Eigen::Vector2i(10, 10),
                                                        "Simulation Controls");
    gui->addButton("Restart",
        std::bind(&GraphicsArenaViewer::OnRestartBtnPressed, this));
    pause_btn_ = gui->addButton("Pause",
        std::bind(&GraphicsArenaViewer::OnPauseBtnPressed, this));

    game_win_window_ = gui->addWindow(Eigen::Vector2i(10, 10), "Game Over");
    gui->addGroup("You Win!");

    game_win_window_->setVisible(false);
    game_win_window_->center();

    game_lose_window_ = gui->addWindow(Eigen::Vector2i(10, 10), "Game Over");
    gui->addGroup("You Lose!");

    game_lose_window_->setVisible(false);
    game_lose_window_->center();

    last_dt = 0;
    performLayout();
}


/*******************************************************************************
 * Member Functions
 ******************************************************************************/

// This is the primary driver for state change in the arena.
// It will be called at each iteration of nanogui::mainloop()
void GraphicsArenaViewer::UpdateSimulation(double dt) {
    if (!paused_ && !arena_->win() && !arena_->lose()) {
        if ((last_dt + dt) > .05) {
            arena_->AdvanceTime(dt+last_dt);
            last_dt = 0;
        } else {
            last_dt += dt;
        }
    }
    if (arena_->win())
        game_win_window_->setVisible(true);
    if (arena_->lose())
        game_lose_window_->setVisible(true);
}

/*******************************************************************************
 * Handlers for User Keyboard and Mouse Events
 ******************************************************************************/
void GraphicsArenaViewer::OnRestartBtnPressed() {
    game_win_window_->setVisible(false);
    game_lose_window_->setVisible(false);
    //arena_->Reset();
}

void GraphicsArenaViewer::OnPauseBtnPressed() {
    paused_ = !paused_;
    if (paused_) {
        pause_btn_->setCaption("Play");
    } else {
        pause_btn_->setCaption("Pause");
    }
}

void GraphicsArenaViewer::OnSpecialKeyDown(int key, int scancode,
    int modifiers) {
    (void) scancode;  // compiler will see this as used variable;
    (void) modifiers;
    // EventKeypress e(key);
    // arena_->Accept(&e);
}

/*******************************************************************************
 * Drawing of Entities in Arena
 ******************************************************************************/


void GraphicsArenaViewer::DrawObstacle(NVGcontext *ctx,
                                       const Obstacle* const obstacle) {
    nvgBeginPath(ctx);
    nvgCircle(ctx, obstacle->get_pos().x(), obstacle->get_pos().y(),
            obstacle->radius());
    nvgFillColor(ctx, nvgRGBA(static_cast<int>(obstacle->get_color().r),
                                static_cast<int>(obstacle->get_color().g),
                                static_cast<int>(obstacle->get_color().b),
                                255));
    nvgFill(ctx);
    nvgStrokeColor(ctx, nvgRGBA(0, 0, 0, 255));
    nvgStroke(ctx);

    nvgFillColor(ctx, nvgRGBA(0, 0, 0, 255));
    nvgText(ctx, obstacle->get_pos().x(), obstacle->get_pos().y(),
            obstacle->get_name().c_str(), NULL);
}



void GraphicsArenaViewer::DrawUsingNanoVG(NVGcontext *ctx) {
        // initialize text rendering settings
    nvgFontSize(ctx, 18.0f);
    nvgFontFace(ctx, "sans-bold");
    nvgTextAlign(ctx, NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);

    std::vector<Obstacle*> obstacles = arena_->obstacles();
    for (size_t i = 0; i < obstacles.size(); i++) {
        DrawObstacle(ctx, obstacles[i]);
    } /* for(i..) */
}



