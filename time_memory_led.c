#include"time_memory_led.h"
#include"time_memory.h"


int _time_memory_led_init(void)
{
	return RUN_OK;
}

int _time_memory_led_deinit(void)
{
	return RUN_OK;
}

int _time_memory_led_handle_msg(TIME_MEMORY_MSG_TYPE_T e_tm_msg,
											void*	ptm_msg_param)
{
	switch(e_tm_msg)
	{
		case TM_MSG_INIT:
			printf("This is LED, welcom!!!\n");
			break;
		default:
			break;
	}
	return RUN_OK;
}

int _time_memory_led_cmd_do(TIME_MEMORY_CMD_TYPE_T e_tm_cmd,
									void*	ptm_cmd_param)
{

	return RUN_OK;
}

int time_memory_led_register(void)
{
	TIME_MEMORY_COMP_INITF_T	t_init;

	t_init.pf_init			= _time_memory_led_init;
	t_init.pf_deinit		= _time_memory_led_deinit;
	t_init.pf_handle_msg	= _time_memory_led_handle_msg;
	t_init.pf_cmd_do		= _time_memory_led_cmd_do;

	return time_memory_comp_register(TIME_MEMORY_LED,&t_init);
}

