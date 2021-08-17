ContentEnabler()
{
	
	web_set_sockets_option("SSL_VERSION","TLS1.1");
	
	lr_save_string(lr_eval_string("{cp_WCCAccessToken}"), "WCCAccessToken");
	web_add_header("accessToken","{WCCAccessToken}");
	web_add_header("Content-Type","application/json");
	
	web_reg_find("Text=series", "SaveCount=Text_count", LAST);
	
	lr_start_transaction("KAAS_T033_ContentEnabler_ExpandProduct");
	
	web_custom_request("web_custom_request",
	    "URL=https://hx9ekpvvbi.execute-api.us-east-1.amazonaws.com/KaaS-ITG/contentenabler/expandToModelsAndSeries",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Body=[\"5264756\"]",
		LAST);
	

	if(strcmp(lr_eval_string("{Text_count}"),"0")==0)
	{

		lr_end_transaction("KAAS_T033_ContentEnabler_ExpandProduct", LR_FAIL);
   
	}
    else
    {
        lr_end_transaction("KAAS_T033_ContentEnabler_ExpandProduct", LR_PASS);
    }

		
	//lr_end_transaction("KAAS_T033_ContentEnabler_ExpandProduct", LR_AUTO);
	
	return 0;
}
