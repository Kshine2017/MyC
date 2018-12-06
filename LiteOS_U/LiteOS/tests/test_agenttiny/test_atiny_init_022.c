#include "test_agenttiny.h"

void test_atiny_init_022 (void **state)
{
	void *phandle;
	atiny_param_t uwAtiny_params;
	memset(&uwAtiny_params, 0, sizeof(atiny_param_t));
	int ret = 0;

	uwAtiny_params.server_params.binding = (char *)"SQ";
	uwAtiny_params.server_params.life_time = -2147483648;
	uwAtiny_params.server_params.storing_cnt = 4294967295;

	uwAtiny_params.server_params.bootstrap_mode = BOOTSTRAP_CLIENT_INITIATED;
	uwAtiny_params.server_params.hold_off_time = 2147483647;

	uwAtiny_params.security_params[0].server_ip = TEST_LWM2M_SERVER_IP;
	uwAtiny_params.security_params[0].server_port = TEST_LWM2M_SERVER_DTLS_PORT_INVALID;
	uwAtiny_params.security_params[0].psk_Id = TEST_LWM2M_SERVER_PSK_ID_INVALID;
	uwAtiny_params.security_params[0].psk = TEST_LWM2M_SERVER_PSK;
	uwAtiny_params.security_params[0].psk_len = 16;

	uwAtiny_params.security_params[1].server_ip = TEST_LWM2M_SERVER_IP;
	uwAtiny_params.security_params[1].server_port = TEST_LWM2M_SERVER_DTLS_PORT_INVALID;
	uwAtiny_params.security_params[1].psk_Id = TEST_LWM2M_SERVER_PSK_ID_INVALID;
	uwAtiny_params.security_params[1].psk = TEST_LWM2M_SERVER_PSK_INVALID;
	uwAtiny_params.security_params[1].psk_len = 0;

	ret = atiny_init(&uwAtiny_params, &phandle);	
	assert_int_equal(ret, ATINY_OK);

    atiny_destroy(phandle);
    atiny_deinit(phandle);
}

