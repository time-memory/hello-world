#ifndef _TIME_MEMORY_H_
#define _TIME_MEMORY_H_

#include"time_memory_common.h"

typedef enum _TIME_MEMORY_COMP_NAME
{
	TIME_MEMORY_LED = 0,
	TIME_MEMORY_BOX,
	TIME_MEMORY_MONITOR,
	TIME_MEMORY_SOUNDBOX,

	TIME_MEMORY_COMP_COUNT	/*Only for counts*/
} TIME_MEMORY_COMP_NAME;

typedef enum _TIME_MEMORY_MSG_TYPE_T
{
	TM_MSG_INIT = 0,
	TM_MSG_EXIT
} TIME_MEMORY_MSG_TYPE_T;

typedef enum _TIME_MEMORY_CMD_TYPE_T
{
	TM_CMD_WELCOM = 0,
	TM_CMD_COUNT
} TIME_MEMORY_CMD_TYPE_T;


typedef int (*time_memory_init) (void);
typedef int (*time_memory_deinit) (void);
typedef int (*time_memory_handle_msg) (TIME_MEMORY_MSG_TYPE_T,void*);
typedef int (*time_memory_cmd_do) (TIME_MEMORY_CMD_TYPE_T,void*);


typedef struct _TIME_MEMORY_COMP_INITF_T
{
	time_memory_init		pf_init;
	time_memory_deinit		pf_deinit;
	time_memory_handle_msg	pf_handle_msg;
	time_memory_cmd_do		pf_cmd_do;
	
} TIME_MEMORY_COMP_INITF_T;

typedef struct _TIME_MEMORY_T
{
	TIME_MEMORY_COMP_INITF_T	time_memory_comp[TIME_MEMORY_COMP_COUNT];
} TIME_MEMORY_T;

#endif
