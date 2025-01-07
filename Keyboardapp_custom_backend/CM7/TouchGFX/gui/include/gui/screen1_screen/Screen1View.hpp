#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>
#include<gui/common/CustomKeyboard.hpp>

#ifndef SIMULATOR
#include "stdio.h"
#include <cstring>
#endif


class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void NameClicked();
    virtual void AgeClicked();
    virtual void OkClicked();
    virtual void ExitClicked();
    virtual void buttonSendClicked();
protected:
    CustomKeyboard keyboard;
    int namemode;
    int agemode;
    char dataBuf[50];
    char namebuf[TEXTAREANAME_SIZE];
    char agebuf[TEXTAREAAGE_SIZE];
};

#endif // SCREEN1VIEW_HPP
