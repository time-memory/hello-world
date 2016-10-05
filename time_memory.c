#include"time_memory.h"

static TIME_MEMORY_T	time_memory;



int time_memory_comp_register(TIME_MEMORY_COMP_NAME 				comp_name,
										TIME_MEMORY_COMP_INITF_T*			pv_this)
{
	TIME_MEMORY_T*		pt_this = &time_memory;

	pt_this->time_memory_comp[comp_name].pf_init			= pv_this->pf_init;
	pt_this->time_memory_comp[comp_name].pf_deinit			= pv_this->pf_deinit;
	pt_this->time_memory_comp[comp_name].pf_handle_msg		= pv_this->pf_handle_msg;
	pt_this->time_memory_comp[comp_name].pf_cmd_do			= pv_this->pf_cmd_do;

	return RUN_OK;
}

int time_memory_brdcast_msg(TIME_MEMORY_MSG_TYPE_T e_tm_msg,
									void*	ptm_msg_param)
{
	int i = 0;
	TIME_MEMORY_T*		pt_this = &time_memory;

	for(i = 0; i < TIME_MEMORY_COMP_COUNT; i++)
	{
		if(pt_this->time_memory_comp[i].pf_handle_msg != NULL)
		{
			(*(pt_this->time_memory_comp[i].pf_handle_msg))(e_tm_msg,ptm_msg_param);
		}
	}
	return RUN_OK;
}

int main(void)
{
	int fret = 0;

	fret = time_memory_led_register();
	fret = time_memory_monitor_register();
	time_memory_brdcast_msg(TM_MSG_INIT,NULL);

	
	
	return 0;
}


