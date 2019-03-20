#ifndef _VIRTUAL_H_
#define _VIRTUAL_H_

#include "PublishedMessages.h"
//void post_from_virtual(void* msg_type, void * msg_id, void * msg_data);

void virtual_COV_notification(void* wire_msg);
void AE_COV_notification(MESSAGE_ID_t , void * msg_data);

#endif // !_VIRTUAL_H_

