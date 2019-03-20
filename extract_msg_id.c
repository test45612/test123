/**
 * @file: cs_virtual_object.c
 * @copyright Johnson Controls Hitachi Inc.
 * @author: Lokesh V
 * @Date: 14/09/18
 * @brief: virtual object write and read
 */
/*local includes*/

#include "pb_encode.h"
#include "pb_decode.h"
#include "pb.h"
#include "idu.pb.h"
#include "idu_wrc.pb.h"
#include "idu_comm.pb.h"
#include "extract_msg_id.h"
#include "virtual.h"   

/* system includes */
#include <stdio.h>
#include <stdint.h>
/* local macros*/

#define TRUE 1
#define FALSE -1

/*variable intialization*/
set_idu_wrc_configuration set_wrc_idu_configuration_data;

uint8_t extract_which_comm_messages(void* wire_msg)
{
        idu_to_wrc_message *msg = wire_msg;
	switch (msg->which_comm_messages)
	{
		/*		case(idu_to_cs_message_capability_info_tag):
						break;
				case(idu_to_cs_message_idu_cfg_tag):
					break;
				case(idu_to_cs_message_cs_cfg_tag):
					break;
				case(idu_to_cs_message_event_report_data_tag):
					break;
				case(idu_to_cs_message_inspection_data_tag):
					break;
		*/
			case(idu_wrc_configuration_info_type_tag):
				extract_msg_type(msg);
				break;
			default: 
				break;
	}
        return TRUE;
}

/**
* @fn                  : vo_cs_write
* @author              :Lokesh V
* @date                : 26/11/2018
* @brief               :updating cs virtual object based on type of configuration.
* @param               :cs_idu_configuration_type,msg_type ,which type of configuration  data.
* @param               :void * const, msgId, gives information about which property_type.
* @param               :void * const, parameter, the changed value of the property.
* @return              :returns the status whether updated or not.
*/

uint8_t extract_msg_type(idu_to_wrc_message *wire_msg)
{
	uint8_t retVal;                                                                                   //return value intialization
	switch(wire_msg->comm_messages.set_cfg.type)
	{		
		case idu_wrc_configuration_type_TEMPERATURE_CONFIG_INFO:                           //checking for which type of configuration
		retVal = extract_temp_config_msg_id(wire_msg);              //status of updation of cs virtual object
		break;
	}
	return retVal;
}

/**
* @fn                  :vo_cs_write_temp_config
* @author              :Lokesh V
* @date                : 26/11/2018
* @brief               :updating cs virtual object based on type of configuration.
* @param               :temp_conf_type, msgId, gives information about which property_type.
* @param               :void * const, parameter, the changed value of the property.
* @return              :returns the status whether updated or not.
*/

uint8_t extract_temp_config_msg_id(idu_to_wrc_message *wire_msg)
{
	switch (wire_msg->comm_messages.set_cfg.type)
	{
	case temp_conf_type_SET_TEMP_PROHIBIT:
		AE_COV_notification(TEMP_MODE_MSG_ID, wire_msg);                //upating the propertywith new value 
		break;
	case temp_conf_type_SET_TEMPERATURE:
		AE_COV_notification(TEMP_MODE_MSG_ID, wire_msg);                  //upating the propertywith new value 
		break;
	case temp_conf_type_AUTO_HEATING_SET_TEMPERATURE:
		AE_COV_notification(TEMP_MODE_MSG_ID, wire_msg);                 //upating the propertywith new value 
		break;
	case temp_conf_type_AUTO_COOLING_SET_TEMPERATURE:
		AE_COV_notification(TEMP_MODE_MSG_ID, wire_msg);                 //upating the propertywith new value 
		break;
	case temp_conf_type_HEATING_AUTO_TEMP:
		AE_COV_notification(TEMP_MODE_MSG_ID,wire_msg);                  //upating the propertywith new value 
		break;
	case temp_conf_type_HEATING_TEMP_CORRECTION:
		AE_COV_notification(TEMP_MODE_MSG_ID, wire_msg);                  //upating the propertywith new value 
		break;
	case temp_conf_type_COOLING_TEMP_CORRECTION:
		AE_COV_notification(TEMP_MODE_MSG_ID, wire_msg);                 //upating the propertywith new value 
		break;
	case temp_conf_type_COOLING_LOWER_LIMIT:
		AE_COV_notification(TEMP_MODE_MSG_ID, wire_msg);                 //upating the propertywith new value 
		break;

	case temp_conf_type_HAETING_UPPER_LIMIT:
		AE_COV_notification(TEMP_MODE_MSG_ID, wire_msg);                 //upating the propertywith new value 
		break;
	case temp_conf_type_SET_TEMP_PARTIAL_PROHIBIT:
		AE_COV_notification(TEMP_MODE_MSG_ID, wire_msg);                 //upating the propertywith new value 
		break;

	case temp_conf_type_SET_TEMP_SUPPORT:
		AE_COV_notification(TEMP_MODE_MSG_ID, wire_msg);                //upating the propertywith new value 
		break;
	case temp_conf_type_AUTO_TEMP_SUPPORT:
		AE_COV_notification(TEMP_MODE_MSG_ID, wire_msg);                  //upating the propertywith new value 
		break;

	default:
		return FALSE;
	}
	return TRUE;
}

/**
* @fn                  : vo_cs_write_operation_config
* @author              :Lokesh V
* @date                : 26/11/2018
* @brief               :updating cs virtual object based on type of configuration.
* @param               :operation_cfg_type, msgId, gives information about which property_type.
* @param               :void * const, parameter, the changed value of the property.
* @return              :returns the status whether updated or not.
*/

uint8_t extract_operation_config_msg_id(operation_cfg_type msgId,  void* const parameter)
{
	switch(msgId)
	{
		default:
		return FALSE;
	}
	return TRUE;
}

/**
* @fn                  :vo_cs_write_fan_config
* @author              :Lokesh V
* @date                : 26/11/2018
* @brief               :updating cs virtual object based on type of configuration.
* @param               :fan_cfg_type, msgId, gives information about which property_type.
* @param               :void * const, parameter, the changed value of the property.
* @return              :returns the status whether updated or not.
*/
uint8_t extract_fan_config_msg_id(fan_cfg_type msgId, void* const parameter)
{
	switch(msgId)
	{
		default:
		return FALSE;
	}
	return TRUE ;
}
/**
* @fn                  :vo_cs_write_louver_config
* @author              :Lokesh V
* @date                : 26/11/2018
* @brief               :updating cs virtual object based on type of configuration.
* @param               :louver_cfg_type, msgId, gives information about which property_type.
* @param               :void * const, parameter, the changed value of the property.
* @return              :returns the status whether updated or not.
*/
uint8_t extract_louver_config_msg_id(louver_cfg_type msgId, void* const parameter)
{
	switch(msgId)
	{
		default:
		return FALSE;
	}
	return TRUE ;
}
/**
* @fn                  :vo_cs_write_schedule_config
* @author              :Lokesh V
* @date                : 26/11/2018
* @brief               :updating cs virtual object based on type of configuration.
* @param               :schedule_cfg_type, msgId, gives information about which property_type.
* @param               :void * const, parameter, the changed value of the property.
* @return              :returns the status whether updated or not.
*/
uint8_t extract_schedule_config_msg_id(schedule_cfg_type msgId, void* const parameter)
{
	switch(msgId)
	{
		default:
		return FALSE;
	}
	return TRUE ;
}
/**
* @fn                  :vo_cs_write_aux_heater_config
* @author              :Lokesh V
* @date                : 26/11/2018
* @brief               :updating cs virtual object based on type of configuration.
* @param               :aux_heater_type, msgId, gives information about which property_type.
* @param               :void * const, parameter, the changed value of the property.
* @return              :returns the status whether updated or not.
*/
uint8_t extract_aux_heater_config_msg_id(aux_heater_type msgId, void* const parameter)
{
	switch(msgId)
	{
		default:
		return FALSE;
	}
	return TRUE ;
}


