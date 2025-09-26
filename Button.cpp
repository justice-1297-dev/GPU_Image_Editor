#include "Button.h"
#include "Application.h"

namespace csci3081 {

Button::Button(){
    float aspect = 1.0f*app.windowWidth/app.windowHeight;
    app.buttonX = 0.01;
    app.buttonY = 0.01;
    app.buttonWidth = 0.1;
    app.buttonHeight = 0.1*aspect;
    app.buttonHighlighted = false;
    app.buttonClicked = false;
}

Button::~Button(){


}

}