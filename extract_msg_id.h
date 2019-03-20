/**
 * @file: cs_virtual_object.h
 * @copyright Johnson Controls Hitachi Inc.
 * @author: Lokesh V
 * @Date: 14/09/18
 * @brief: virtual object write
 */


#ifndef CS_VIRTUAL_OBJECT_INCLUDED
#define CS_VIRTUAL_OBJECT_INCLUDED

/*function prototypes*/
//uint8_t extract_msg_type(idu_wrc_configuration_type msg_type, void * const msgId, void* const parameter);
uint8_t extract_operation_config_msg_id(operation_cfg_type msgId,  void* const parameter);
//uint8_t extract_temp_config_msg_id(temp_conf_type msgId, void* const parameter);
uint8_t extract_fan_config_msg_id(fan_cfg_type msgId, void* const parameter);
uint8_t extract_louver_config_msg_id(louver_cfg_type msgId, void* const parameter);
uint8_t extract_schedule_config_msg_id(schedule_cfg_type msgId, void* const parameter);
uint8_t extract_aux_heater_config_msg_id(aux_heater_type msgId, void* const parameter);

uint8_t extract_which_comm_messages(void* wire_msg);
uint8_t extract_msg_type(idu_to_wrc_message *wire_msg);
uint8_t extract_temp_config_msg_id(idu_to_wrc_message *wire_msg);

#endif