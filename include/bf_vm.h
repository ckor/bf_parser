#ifndef					H_BF_VM
# define				H_BF_VM

# include "dl_list.h"

typedef t_dl_list		t_bf_code;
typedef t_dl_list		t_bf_memory;

/*

#define					INT8_SIZE		sizeof(signed char),
#define					UINT8_SIZE		sizeof(unsigned char),
#define					INT16_SIZE		sizeof(signed int),
#define					UINT16_SIZE		sizeof(unsigned int),
#define					INT32_SIZE		sizeof(signed long),
#define					UINT32_SIZE		sizeof(unsigned long),

typedef signed char		t_int8;
typedef unsigned char	t_uint8;
typedef signed int 		t_int16;
typedef unsigned int	t_uint16;
typedef signed long		t_int32;
typedef unsigned long	t_uint32;

typedef enum
{
	int8,
	uint8,
	int16,
	uint16,
	int32,
	uint32,
	undefined
}						t_var_type;

typedef enum
{
	int8_size =			INT8_SIZE,
	uint8_size =		UINT8_SIZE,
	int16_size =		INT16_SIZE,
	uint16_size =		UINT16_SIZE,
	int32_size =		INT32_SIZE,
	uint32_size =		UINT32_SIZE,
}						t_var_size;

typedef struct			s_var
{
	t_var_type			type;
	void				*ut_value;
	union
	{
		int8			*i8,
		uint8			*ui8,
		int16			*i16,
		uint16			*ui16,
		int32			*i32,
		uint32			*ui32,
	}					value;
}						t_var;

*/

typedef struct			s_bf_vm
{
	t_bf_code			*code;
	t_bf_memory			*memory;
	long				c_cur;
	long				m_cur;
}						t_bf_vm;

#endif
