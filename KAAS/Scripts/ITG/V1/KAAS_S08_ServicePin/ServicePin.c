ServicePin()
{
	
	web_set_sockets_option("SSL_VERSION", "TLS1.2");
	
	lr_save_string(lr_eval_string("{cp_WISEAccessToken}"), "WISEAccessToken");
    web_add_header("Content-Type","application/x-www-form-urlencoded");
	//Use Access Token for HPI in the URL itself for Service Pin
        
	//{"servicePin
	web_reg_find("Text={\"servicePin", "SaveCount=Text_count", LAST);
	
	lr_start_transaction("KAAS_T019_ServicePin");
	web_custom_request("web_custom_request",
		"URL=https://hx9ekpvvbi.execute-api.us-east-1.amazonaws.com/KaaS-ITG/v2/servicepin/{WISEAccessToken}/{p_servicePIN}",
		//https://hx9ekpvvbi.execute-api.us-east-1.amazonaws.com/KaaS-ITG/v2/servicepin/000ayXsW8s5Beok6fPaxF8XZEue5/B5L48V
		"Method=GET",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Body=",
		LAST);
	
	if(strcmp(lr_eval_string("{Text_count}"),"0")==0)
	{
		lr_end_transaction("KAAS_T019_ServicePin", LR_FAIL);

	}
	else
	{
		lr_end_transaction("KAAS_T019_ServicePin", LR_PASS);

	}

	//lr_end_transaction("KAAS_T019_ServicePin", LR_AUTO);
	
	return 0;
}
