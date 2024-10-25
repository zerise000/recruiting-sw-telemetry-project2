#ifndef __SESSION_H__
#define __SESSION_H__

#include <iostream>
#include <fstream>
#include <cstdint>
#include <cstring>
#include <format>
#include <chrono>

#include "message.h"

const uint16_t max_id_size = 4096;
typedef std::chrono::time_point<std::chrono::system_clock> duration_t;

typedef struct{
	uint32_t id;
	std::ofstream log_file;
	uint64_t freq[max_id_size];
	duration_t last_msg_time[max_id_size];
	double diff_sum[max_id_size];

	void start_new_session();
	void stop_session();
	void update_session(Message msg);
}Session;




#endif