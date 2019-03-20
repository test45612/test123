#include "PublishedMessages.h"
#include "RuleEngineInterface.h"
#include "pb_encode.h"
#include "pb_decode.h"
#include "pb.h"
#include "idu.pb.h"
#include "idu_wrc.pb.h"
#include "idu_comm.pb.h"
#include <stdint.h>
#include <stdio.h>
#include "extract_msg_id.h"


void virtual_COV_notification(void* wire_msg)
{
	extract_which_comm_messages(wire_msg);
}


void AE_COV_notification(MESSAGE_ID_t msgId, void * msg_data)
{
  post_message(msgId, msg_data);
 // post_message(HUMIDITY_MODE_MSG_ID, msg_data);
}
/*
void post_from_virtual(void* msg_type, void * msg_id, void * msg_data) {
	void *ptr = NULL;
	post_message(TEMP_MODE_MSG_ID, ptr);
	post_message(HUMIDITY_MODE_MSG_ID, ptr);
}*/