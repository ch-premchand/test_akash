#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#ifndef SIMULATOR
#include "main.h"
#include "string.h"
#include "cmsis_os2.h"
extern "C"
{

	extern osMessageQueueId_t uartQueueHandle;
	uartdata_t uartdata_q;
}
#endif
Model::Model() : modelListener(0)
{

}

void Model::tick()
{

}

void Model::sendData (char *data)
{
#ifndef SIMULATOR
	strcpy (uartdata_q.data, data);
	uartdata_q.len = strlen (data);
	if (osMessageQueueGetSpace(uartQueueHandle)>0)  // if there is some space in the queue
	{
		osMessageQueuePut(uartQueueHandle, &uartdata_q, 0, 0);  // send the structure to the queue
	}
#endif
}
