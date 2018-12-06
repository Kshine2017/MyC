#include "test_agenttiny.h"

void test_atiny_bind_019 (void **state)
{
	atiny_param_t uwAtiny_params;
	memset(&uwAtiny_params, 0, sizeof(atiny_param_t));
    atiny_device_info_t uwDevice_info;
    memset(&uwDevice_info, 0, sizeof(atiny_device_info_t));
	int ret = 0;

	uwAtiny_params.server_params.binding = (char *)"else";  // invalid model
	uwAtiny_params.server_params.life_time = 5000;
	uwAtiny_params.server_params.storing_cnt = 4294967295;  //boundary value

	uwAtiny_params.server_params.bootstrap_mode = BOOTSTRAP_SEQUENCE;  // BOOTSTRAP_SEQUENCE
	uwAtiny_params.server_params.hold_off_time = 0;

	uwAtiny_params.security_params[0].server_ip = "not a ip addr";  // invalid ip
	uwAtiny_params.security_params[0].server_port = "not a port";   // invalid port
    
    uwAtiny_params.security_params[1].server_ip = TEST_LWM2M_SERVER_IP;
	uwAtiny_params.security_params[1].server_port = TEST_LWM2M_SERVER_PORT;

    uwDevice_info.endpoint_name = "66660006";
    uwDevice_info.manufacturer = "LiteOS";
    uwDevice_info.dev_type = "IOT";
    
    ret = atiny_init(&uwAtiny_params, &test_phandle);
    if(ATINY_OK != ret)
    {
        return;
    }
    atiny_bind(&uwDevice_info, test_phandle);
    assert_int_equal(ret, ATINY_OK);
}




