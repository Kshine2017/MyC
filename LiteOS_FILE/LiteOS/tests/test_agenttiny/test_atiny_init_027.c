#include "test_agenttiny.h"

void test_atiny_init_027 (void **state)
{
	void *phandle;
	atiny_param_t uwAtiny_params;
	memset(&uwAtiny_params, 0, sizeof(atiny_param_t));
	int ret = 0;

	uwAtiny_params.server_params.binding = (char *)"SQ";
	uwAtiny_params.server_params.life_time = 5000;
	uwAtiny_params.server_params.storing_cnt = 1024;

	uwAtiny_params.server_params.bootstrap_mode = BOOTSTRAP_SEQUENCE;
	uwAtiny_params.server_params.hold_off_time = 10;

	uwAtiny_params.security_params[0].server_ip = TEST_LWM2M_SERVER_IP_INVALID;
	uwAtiny_params.security_params[0].server_port = TEST_LWM2M_SERVER_DTLS_PORT;
	uwAtiny_params.security_params[0].psk_Id = TEST_LWM2M_SERVER_PSK_ID;
	uwAtiny_params.security_params[0].psk = TEST_LWM2M_SERVER_PSK;
	uwAtiny_params.security_params[0].psk_len = 65535;

	uwAtiny_params.security_params[1].server_ip = TEST_LWM2M_SERVER_IP_INVALID;
	uwAtiny_params.security_params[1].server_port = TEST_LWM2M_SERVER_DTLS_PORT;
	uwAtiny_params.security_params[1].psk_Id = TEST_LWM2M_SERVER_PSK_ID;
	uwAtiny_params.security_params[1].psk = TEST_LWM2M_SERVER_PSK_INVALID;
	uwAtiny_params.security_params[1].psk_len = 16;

	ret = atiny_init(&uwAtiny_params, &phandle);
	assert_int_equal(ret, ATINY_OK);

    atiny_destroy(phandle);
    atiny_deinit(phandle);
}

