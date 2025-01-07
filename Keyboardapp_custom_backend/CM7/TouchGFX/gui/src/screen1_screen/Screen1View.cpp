#include <gui/screen1_screen/Screen1View.hpp>
#include <cstring>
#include <cstdio>

Screen1View::Screen1View()
{
	keyboard.setPosition(80,16,320,240);
	add(keyboard);
	keyboard.setVisible(false);
	keyboard.invalidate();

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::NameClicked(){
	keyboard.setVisible(true);
	keyboard.invalidate();
	flexButtonOk.setVisible(true);
	flexButtonOk.invalidate();
	flexButtonExit.setVisible(true);
	flexButtonExit.invalidate();
	buttonSend.setVisible(false);
	buttonSend.invalidate();
	namemode=1;
	agemode=0;
}

void Screen1View::AgeClicked(){
	keyboard.setVisible(true);
	keyboard.invalidate();
	flexButtonOk.setVisible(true);
	flexButtonOk.invalidate();
	flexButtonExit.setVisible(true);
	flexButtonExit.invalidate();
	buttonSend.setVisible(false);
	buttonSend.invalidate();
	namemode=0;
	agemode=1;
}

void Screen1View::OkClicked(){
	keyboard.setVisible(false);
	keyboard.invalidate();
	flexButtonOk.setVisible(false);
	flexButtonOk.invalidate();
	flexButtonExit.setVisible(false);
	flexButtonExit.invalidate();
	buttonSend.setVisible(true);
	buttonSend.invalidate();
	if(namemode){
		Unicode::strncpy(textAreaNameBuffer, keyboard.getBuffer(), TEXTAREANAME_SIZE);
		textAreaName.invalidate();
	}
	if(agemode){
		Unicode::strncpy(textAreaAgeBuffer, keyboard.getBuffer(), TEXTAREAAGE_SIZE);
		textAreaAge.invalidate();
	}

	keyboard.clearBuffer();
}

void Screen1View::ExitClicked(){
	keyboard.setVisible(false);
	keyboard.invalidate();
	flexButtonOk.setVisible(false);
	flexButtonOk.invalidate();
	flexButtonExit.setVisible(false);
	flexButtonExit.invalidate();
	buttonSend.setVisible(true);
	buttonSend.invalidate();
	namemode=agemode=0;
}

void Screen1View::buttonSendClicked()
{
	// convert the unicode chars to chars
	int i=0;
	do
	{
		namebuf[i] = (char) textAreaNameBuffer[i];
		i++;
	}while (textAreaNameBuffer[i]!=0);

	i=0;
	do
	{
		agebuf[i] = (char) textAreaAgeBuffer[i];
		i++;
	}while (textAreaAgeBuffer[i]!=0);
#ifndef SIMULATOR
	// store the data in a presentable format
	sprintf (dataBuf, "Name:%s, Age:%s\r\n", namebuf, agebuf);

	// send the data to the presenter
	presenter->sendData(dataBuf);

	//clear the buffers
	memset (namebuf, '\0', TEXTAREANAME_SIZE);
	memset (agebuf, '\0', TEXTAREAAGE_SIZE);
#endif
}

